#include <fstream>
#include <wx/menu.h>
#include <wx/log.h>
#include <wx/msgdlg.h>
#include <wx/textctrl.h>
#include <wx/stc/stc.h>
#include <wx/toolbar.h>
#include <wx/artprov.h>
#include <wx/filedlg.h>
#include <wx/filename.h>
#include <wx/preferences.h>
#include <wx/process.h>
#include <wx/stdstream.h>
#include <wx/wfstream.h>
#include <wx/mimetype.h>
#include "MuseMidiCompiler.h"
#include "App.h"
#include "Compiler.h"
#include "Parser.h"
#include "MuseParser.h"
#include "symbol/Program.h"
#include "symbol/Symbol.h"
#include "preference/GeneralPage.h"
#include "preference/EditorPage.h"
#include "preference/ColorsPage.h"
#include "preference/ExecutionPage.h"
#include "MainFrame.h"
#include "MuseAuiTabArt.h"
#include "MuseArtProvider.h"
#include "MuseLexer.h"
#include "OutputTextCtrl.h"

namespace dem {
    namespace ide {
        wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
            // common
            EVT_MENU(wxID_EXIT,  MainFrame::onExit)

            // file
            EVT_MENU(ID_NewFile, MainFrame::onFileNew)
            EVT_MENU(wxID_OPEN, MainFrame::onFileOpen)
            EVT_MENU(wxID_SAVE, MainFrame::onFileSave)
            EVT_MENU(wxID_SAVEAS, MainFrame::onFileSaveAs)
            EVT_MENU(wxID_CLOSE, MainFrame::onFileClose)

            // edit
            EVT_MENU(wxID_UNDO, MainFrame::onEditUndo)
            EVT_MENU(wxID_REDO, MainFrame::onEditRedo)

            EVT_MENU(wxID_CUT, MainFrame::onEditCut)
            EVT_MENU(wxID_COPY, MainFrame::onEditCopy)
            EVT_MENU(wxID_PASTE, MainFrame::onEditPaste)

            EVT_MENU(wxID_SELECTALL, MainFrame::onEditSelectAll)

            EVT_MENU(wxID_PREFERENCES, MainFrame::onEditPreferences)

            // run
            EVT_MENU(ID_Build, MainFrame::onRunBuild)
            EVT_MENU(ID_Run, MainFrame::onRunRun)
            EVT_MENU(ID_Stop, MainFrame::onRunStop)

            // help
            EVT_MENU(wxID_ABOUT, MainFrame::onAbout)
        wxEND_EVENT_TABLE()

        MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) :
            wxFrame(nullptr, wxID_ANY, title, pos, size) {
            mMgr.SetManagedWindow(this);
            
#ifdef __WINDOWS__
            auto tset = wxICON(icon);
            SetIcon(tset);
#endif

            createMenu();
            createToolBar();

            createCenterNotebook();
            createBottomTools();

            createStatusBar();

            mMgr.Update();
        }

        MainFrame::~MainFrame() {
            mMgr.UnInit();
        }

        void MainFrame::createMenu() {
            // create menu
            mFileMenu = new wxMenu;
            mFileMenu->Append(ID_NewFile, "&New File...", "Create a new file in de current project.");
            mFileMenu->AppendSeparator();
            mFileMenu->Append(wxID_OPEN);
            mFileMenu->AppendSeparator();
            mFileMenu->Append(wxID_SAVE);
            mFileMenu->Append(wxID_SAVEAS, "Save As...");
            mFileMenu->AppendSeparator();
            mFileMenu->Append(wxID_EXIT);

            mEditMenu = new wxMenu;
            mEditMenu->Append(wxID_UNDO);
            mEditMenu->Append(wxID_REDO);
            mEditMenu->AppendSeparator();
            mEditMenu->Append(wxID_CUT);
            mEditMenu->Append(wxID_COPY);
            mEditMenu->Append(wxID_PASTE);
            mEditMenu->Append(wxID_DELETE);
            mEditMenu->AppendSeparator();
            mEditMenu->Append(wxID_SELECTALL);
            mEditMenu->AppendSeparator();
            mEditMenu->Append(wxID_PREFERENCES);

            mRunMenu = new wxMenu;
            mRunMenu->Append(ID_Run, "&Run\tShift+F9", "Run the current DEMUSE file.");
            mRunMenu->Append(ID_Stop, "&Stop\tCtrl+F2", "Stop the currently running DEMUSE file.");

            mRunMenu->Enable(ID_Stop, false);

            /*
            mHelpMenu = new wxMenu;
            mHelpMenu->Append(wxID_HELP);
            mHelpMenu->AppendSeparator();
            mHelpMenu->Append(wxID_ABOUT);
            */

            wxMenuBar *menuBar = new wxMenuBar;
            menuBar->Append(mFileMenu, "&File");
            menuBar->Append(mEditMenu, "&Edit");
            menuBar->Append(mRunMenu, "&Run");
            //menuBar->Append(mHelpMenu, "&Help");

            SetMenuBar(menuBar);
        }

        void MainFrame::createStatusBar() {
            CreateStatusBar();
            SetStatusText("Welcome to wxWidgets!");
            GetStatusBar()->SetFieldsCount(2);
            // TODO: Show current active editor line:column in statusbar
        }

        void MainFrame::createCenterNotebook() {
            mNotebook = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                                    wxAUI_NB_TAB_SPLIT |
                                                    wxAUI_NB_TAB_MOVE | wxAUI_NB_CLOSE_ON_ALL_TABS |
                                                    wxAUI_NB_MIDDLE_CLICK_CLOSE | wxNO_BORDER);
            mNotebook->Bind(wxEVT_AUINOTEBOOK_PAGE_CLOSE, &MainFrame::onNotebookPageClose, this, wxID_ANY);

            mMgr.AddPane(mNotebook, wxCENTER);
            //mNotebook->SetArtProvider(new MuseAuiTabArt);
            mMgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_PANE_BORDER_SIZE, 0);
        }

        void MainFrame::createEditor(const wxString &filePath /*= wxT("") */) {
            if(!mFileEditors.count(filePath)) {
                // create and new editor and load file if available
                MuseStyledTextEditor *editor = new MuseStyledTextEditor(this, new lexer::MuseLexer());
                editor->initialize();

                wxString tabName{wxT("New File")};

                if(!filePath.empty()) {
                    editor->loadFile(filePath);
                    wxFileName fileName{filePath};
                    tabName = fileName.GetFullName();
                }

                size_t pageId = mNotebook->GetPageCount();
                mNotebook->InsertPage(pageId, editor, tabName, true);
                mFileEditors[filePath] = pageId;
            } else {
                // select page with the loaded file
                mNotebook->SetSelection(mFileEditors[filePath]);
            }
        }

        void MainFrame::createBottomTools() {
            // error window
            mErrorList = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_ROW_LINES | wxDV_HORIZ_RULES | wxNO_BORDER);
            mErrorList->AppendIconTextColumn("");
            mErrorList->AppendTextColumn("Line",        wxDATAVIEW_CELL_INERT, 40);
            mErrorList->AppendTextColumn("Column",      wxDATAVIEW_CELL_INERT, 40);
            mErrorList->AppendTextColumn("Description", wxDATAVIEW_CELL_INERT, 400);
            mErrorList->AppendTextColumn("File",        wxDATAVIEW_CELL_INERT, 300);
            mErrorList->Bind(wxEVT_DATAVIEW_ITEM_ACTIVATED, &MainFrame::onErrorListItemActivated, this, wxID_ANY);

            mMgr.AddPane(mErrorList, wxAuiPaneInfo().Name("Errors").Bottom().MinimizeButton(true).PaneBorder(true).MinSize(-1, 200));

            // output window
            mOutput = new OutputTextCtrl(this, -1, _(""), wxDefaultPosition, wxSize(200, 150), wxNO_BORDER | wxTE_MULTILINE | wxTE_AUTO_URL | wxTE_RICH | wxTE_DONTWRAP);
            mMgr.AddPane(mOutput, wxAuiPaneInfo().Name("Output").Bottom().MinimizeButton(true).PaneBorder(true).MinSize(-1, 200));
        }

        void MainFrame::createToolBar() {
            mToolbar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_DEFAULT_STYLE);
            mToolbar->SetToolBitmapSize(wxSize(24, 24));

            mToolbar->AddTool(ID_NewFile, wxT("&New File..."), wxArtProvider::GetBitmap(wxART_NEW));
            mToolbar->AddTool(wxID_OPEN, wxT("&Open..."), wxArtProvider::GetBitmap(wxART_FILE_OPEN));
            mToolbar->AddTool(wxID_SAVE, wxT("&Save"), wxArtProvider::GetBitmap(wxART_FILE_SAVE));
            mToolbar->AddTool(wxID_SAVEAS, wxT("&Save as..."), wxArtProvider::GetBitmap(wxART_FILE_SAVE_AS));
            mToolbar->AddSeparator();
            mToolbar->AddTool(wxID_CUT, wxT("Cut"), wxArtProvider::GetBitmap(wxART_CUT));
            mToolbar->AddTool(wxID_COPY, wxT("Copy"), wxArtProvider::GetBitmap(wxART_COPY));
            mToolbar->AddTool(wxID_PASTE, wxT("Paste"), wxArtProvider::GetBitmap(wxART_PASTE));
            mToolbar->AddSeparator();
            mToolbar->AddTool(wxID_UNDO, wxT("Undo"), wxArtProvider::GetBitmap(wxART_UNDO));
            mToolbar->AddTool(wxID_REDO, wxT("Redo"), wxArtProvider::GetBitmap(wxART_REDO));
            mToolbar->AddSeparator();
            mToolbar->AddTool(ID_Build, wxT("Build"), wxArtProvider::GetBitmap(wxART_EXECUTABLE_FILE));
            mToolbar->AddTool(ID_Run, wxT("Play"), wxArtProvider::GetBitmap(museART_RUN));
            mToolbar->AddTool(ID_Stop, wxT("Stop"), wxArtProvider::GetBitmap(museART_STOP));

            mToolbar->Realize();

            mToolbar->EnableTool(ID_Stop, false);

            SetToolBar(mToolbar);
        }

        MuseStyledTextEditor *MainFrame::activeEditor() {
            size_t editorId = mNotebook->GetSelection();
            if(editorId == wxNOT_FOUND)
                return nullptr;
            return static_cast<MuseStyledTextEditor*>(mNotebook->GetPage(editorId));
        }

        void MainFrame::onExit(wxCommandEvent &event) {
            Close(true);
        }

        void MainFrame::onAbout(wxCommandEvent &event) {
            wxMessageBox("This is a wxWidgets' Hello World sample", "About Hello World", wxOK | wxICON_INFORMATION);
        }

        void MainFrame::onFileNew(wxCommandEvent &event) {
            createEditor();
        }

        void MainFrame::onFileOpen(wxCommandEvent &event) {
            wxFileDialog dlg(this, wxT("Open file"), wxEmptyString, wxEmptyString, wxT("Any file (*)|*"), wxFD_OPEN | wxFD_FILE_MUST_EXIST | wxFD_CHANGE_DIR );
            if(dlg.ShowModal() != wxID_OK) return;
            wxString filePath = dlg.GetPath();
            createEditor(filePath);
        }

        void MainFrame::onFileSave(wxCommandEvent &event) {
            size_t editorId = mNotebook->GetSelection();
            if(editorId == wxNOT_FOUND)
                return;

            MuseStyledTextEditor *page = static_cast<MuseStyledTextEditor*>(mNotebook->GetPage(editorId));

            if(page->filePath().empty())
                return onFileSaveAs(event);
            activeEditor()->saveFile();
        }

        void MainFrame::onFileSaveAs(wxCommandEvent &event) {
            size_t editorId = mNotebook->GetSelection();
            if(editorId == wxNOT_FOUND)
                return;

            // open dialogsize_t editorId = mNotebook->GetSelection();
            wxString filePath = wxEmptyString;
            wxFileDialog dlg(this, wxT("Save file..."), wxEmptyString, wxEmptyString, wxT("Any file (*)|*"), wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
            if(dlg.ShowModal() != wxID_OK) return;
            filePath = dlg.GetPath();

            // change editor name
            wxFileName fileName{filePath};
            MuseStyledTextEditor *page = static_cast<MuseStyledTextEditor*>(mNotebook->GetPage(editorId));

            mNotebook->SetPageText(editorId, fileName.GetFullName());

            mFileEditors.erase(page->filePath());
            mFileEditors[filePath] = editorId;

            // save file under new name
            activeEditor()->saveAsFile(filePath);
        }

        void MainFrame::onFileClose(wxCommandEvent &event) {
            MuseStyledTextEditor *editor = activeEditor();
            if(!editor)
                return;

            if(editor->IsModified()) {
                if(wxMessageBox(_("Text is not saved, save before closing?"), _("Close"), wxYES_NO | wxICON_QUESTION) == wxYES) {
                    editor->saveFile();
                    if(editor->IsModified()) {
                        wxMessageBox(_("Text could not be saved!"), _("Close abort"), wxOK | wxICON_EXCLAMATION);
                        return;
                    }
                }
            }

            mNotebook->RemovePage(mFileEditors[activeEditor()->filePath()]);
        }

        void MainFrame::onEditCut(wxCommandEvent &event) {
            if(activeEditor())
                activeEditor()->Cut();
        }

        void MainFrame::onEditCopy(wxCommandEvent &event) {
            if(activeEditor())
                activeEditor()->Copy();
        }

        void MainFrame::onEditPaste(wxCommandEvent &event) {
            if(activeEditor())
                activeEditor()->Paste();
        }

        void MainFrame::onEditUndo(wxCommandEvent &event) {
            MuseStyledTextEditor *editor = activeEditor();
            if(!editor || !editor->CanUndo()) return;
                editor->Undo();
        }

        void MainFrame::onEditRedo(wxCommandEvent &event) {
            MuseStyledTextEditor *editor = activeEditor();
            if(!editor || !editor->CanRedo()) return;
                editor->Redo();
        }

        void MainFrame::onEditSelectAll(wxCommandEvent &event) {
            MuseStyledTextEditor *editor = activeEditor();
            if(editor)
                editor->SetSelection(0, editor->GetTextLength());
        }

        void MainFrame::onEditPreferences(wxCommandEvent &event) {
            wxPreferencesEditor *preferencesEditor = new wxPreferencesEditor();
            preferencesEditor->AddPage(new GeneralPage());
            preferencesEditor->AddPage(new EditorPage());
            preferencesEditor->AddPage(new ColorsPage());
            preferencesEditor->AddPage(new ExecutionPage());
            preferencesEditor->Show(this);

            // flush
            wxGetApp().config().Flush();

            // re-initialize editors with new settings
            for(auto pair : mFileEditors) {
                MuseStyledTextEditor *editor = dynamic_cast<MuseStyledTextEditor*>(mNotebook->GetPage(pair.second));
                editor->initialize();
            }
        }

        void MainFrame::onRunBuild(wxCommandEvent &event) {
            if(!activeEditor())
                return;
            if(activeEditor()->filePath().empty()) {
                wxMessageDialog dlg{this, "You must save your file before you can play it. Do you want to save your file now?", "Save before playing file", wxYES_NO};
                if(dlg.ShowModal() == wxID_NO)
                    return;

                wxCommandEvent dummy;
                onFileSave(dummy);
            }

            mErrorList->DeleteAllItems();
            activeEditor()->MarkerDeleteAll(demSTC_MARK_ERROR);

            wxStopWatch totalStopWatch;
            wxStopWatch sw;
            sw.Pause();

            mOutput->SetDefaultStyle(wxTextAttr(*wxBLUE));
            mOutput->AppendText("= Building: file:\\\\\\" + activeEditor()->filePath() + "\n");

            // read file
            mOutput->SetDefaultStyle(wxTextAttr(wxColour(255, 0, 255)));
            mOutput->AppendText("== Reading: file:\\\\\\" + activeEditor()->filePath() + "\n");

            sw.Start();
            std::ifstream is(activeEditor()->filePath().c_str());
            std::string content{std::istreambuf_iterator<char>(is), std::istreambuf_iterator<char>()};
            sw.Pause();

            mOutput->AppendText("== Reading finished in " + std::to_string(sw.Time()) + "ms\n");

            // lexing
            mOutput->AppendText("== Lexing: file:\\\\\\" + activeEditor()->filePath() + "\n");

            sw.Start();
            dem::lexer::MuseLexer museLexer;
            auto begin = content.begin();
            auto end = content.end();
            std::vector<dem::lexer::Token> tokens = museLexer.lex(begin, end);
            sw.Pause();

            mOutput->AppendText("== Lexing finished in " + std::to_string(sw.Time()) + "ms\n");

            try {
                // parsing
                mOutput->AppendText("== Parsing: file:\\\\\\" + activeEditor()->filePath() + "\n");

                sw.Start();
                dem::parser::MuseParser parser;
                dem::parser::ParseResults results = parser.parse(tokens);
                dem::parser::Symbol *program{results.astRoot};
                sw.Pause();

                mOutput->AppendText("== Parsing finished in " + std::to_string(sw.Time()) + "ms\n");

                if(!results.successful()) {
                    for(const parser::ParseError &error : results.errors) {
                        // add error to list
                        wxVector<wxVariant> data;

                        if(error.type == parser::ParseError::Type::T_WARNING) {
                            data.push_back(wxVariant(wxDataViewIconText("Warning", wxArtProvider::GetIcon(wxART_WARNING, wxART_OTHER, wxSize(16, 16)))));
                        } else {
                            data.push_back(wxVariant(wxDataViewIconText("Error", wxArtProvider::GetIcon(wxART_ERROR, wxART_OTHER, wxSize(16, 16)))));
                        }

                        data.push_back(wxVariant(error.token.line()));
                        data.push_back(wxVariant(error.token.column()));
                        data.push_back(wxVariant(error.description));
                        data.push_back(wxVariant(activeEditor()->filePath()));
                        mErrorList->AppendItem(data);

                        // add marker to editor
                        activeEditor()->MarkerAdd(error.token.line() - 1, demSTC_MARK_ERROR);
                        // TODO: Remove marker when line is edited
                    }

                    return;
                }

                // compiling
                mOutput->AppendText("== Compiling: file:\\\\\\" + activeEditor()->filePath() + "\n");

                sw.Start();
                wxString outputFileName = getOutputFileName(activeEditor()->filePath());
                std::cout << "Path: " << outputFileName << std::endl;

                dem::compiler::MidiCompiler compiler;
                compiler.compile(static_cast<dem::parser::Program*>(program), std::string(outputFileName.c_str()));
                sw.Pause();

                mOutput->AppendText("== Compiling finished in " + std::to_string(sw.Time()) + "ms\n");

                mOutput->SetDefaultStyle(wxTextAttr(*wxBLUE));
                mOutput->AppendText("= Build finished in " + std::to_string(totalStopWatch.Time()) + "ms\n");

                mOutput->AppendText("Output file: " + outputFileName.c_str());
            } catch(...) {

            }
        }

        void MainFrame::onRunRun(wxCommandEvent &event) {
            if(!activeEditor())
                return;

            onRunBuild(event);

            if(activeEditor()->filePath().empty())
                return;

            wxMimeTypesManager manager;
            wxFileType *fileType = manager.GetFileTypeFromExtension("mid");
            wxString command = fileType->GetOpenCommand(getOutputFileName(activeEditor()->filePath()));

            mActiveProcess = wxProcess::Open(command);
            mActiveProcess->Bind(wxEVT_END_PROCESS, &MainFrame::onEndProcess, this, wxID_ANY);

            mToolbar->EnableTool(ID_Run, false);
            mToolbar->EnableTool(ID_Stop, true);

            mRunMenu->Enable(ID_Run, false);
            mRunMenu->Enable(ID_Stop, true);
        }

        void MainFrame::onRunStop(wxCommandEvent &event) {
            if(mActiveProcess) {
                wxKill(mActiveProcess->GetPid(), wxSIGKILL);
                mActiveProcess = nullptr;
            }

            mToolbar->EnableTool(ID_Run, true);
            mToolbar->EnableTool(ID_Stop, false);

            mRunMenu->Enable(ID_Run, true);
            mRunMenu->Enable(ID_Stop, false);
        }

        void MainFrame::onErrorListItemActivated(wxDataViewEvent &event) {
            wxVariant line;
            wxVariant column;
            mErrorList->GetValue(line, mErrorList->ItemToRow(event.GetItem()), 1);
            mErrorList->GetValue(column, mErrorList->ItemToRow(event.GetItem()), 2);

            // TODO: Move cursor to line and column
        }

        void MainFrame::onNotebookPageClose(wxAuiNotebookEvent &event) {
            wxString filePath = static_cast<MuseStyledTextEditor*>(mNotebook->GetPage(event.GetSelection()))->filePath();
            mFileEditors.erase(filePath);
        }

        wxString MainFrame::getOutputFileName(const wxString &fileName) {
            wxFileName file{fileName};

            wxString outputFileName{file.GetPath()};
            outputFileName += file.GetPathSeparator() + file.GetName() + ".mid";

            return outputFileName;
        }

        void MainFrame::onEndProcess(wxProcessEvent &event) {
            mActiveProcess = nullptr;

            wxCommandEvent dummy;
            onRunStop(dummy);
        }
    }
}
