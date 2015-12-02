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
#include "preference/GeneralPage.h"
#include "preference/ExecutionPage.h"
#include "MainFrame.h"
#include "MuseAuiTabArt.h"
#include "MuseArtProvider.h"
#include "MuseLexer.h"

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
            EVT_MENU(ID_Run, MainFrame::onRunRun)
            EVT_MENU(ID_Stop, MainFrame::onRunStop)

            // help
            EVT_MENU(wxID_ABOUT, MainFrame::onAbout)
        wxEND_EVENT_TABLE()

        MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) :
            wxFrame(nullptr, wxID_ANY, title, pos, size) {
            createMenu();
            createStatusBar();

            createCenterNotebook();

            createToolBar();

            createEditor("E:\\Programming\\CPP\\DEMUSE\\compiler\\res\\test.muse");
        }

        MainFrame::~MainFrame() {

        }

        void MainFrame::createMenu() {
            // create menu
            mFileMenu = new wxMenu;
            mFileMenu->Append(ID_NewFile, "&New File...", "Create a new file in de current project.");
            mFileMenu->AppendSeparator();
            mFileMenu->Append(wxID_OPEN);
            mFileMenu->AppendSeparator();
            mFileMenu->Append(wxID_SAVE);
            mFileMenu->Append(wxID_SAVEAS);
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
            mRunMenu->Append(ID_Run, "%Run", "Run the current DEMUSE file.");
            mRunMenu->Append(ID_Stop, "&Stop", "Stop the currently running DEMUSE file.");

            mHelpMenu = new wxMenu;
            mHelpMenu->Append(wxID_HELP);
            mHelpMenu->AppendSeparator();
            mHelpMenu->Append(wxID_ABOUT);

            wxMenuBar *menuBar = new wxMenuBar;
            menuBar->Append(mFileMenu, "&File");
            menuBar->Append(mEditMenu, "&Edit");
            menuBar->Append(mHelpMenu, "&Help");

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
            //mNotebook->SetArtProvider(new MuseAuiTabArt);
            mMgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_PANE_BORDER_SIZE, 0);
        }

        void MainFrame::createEditor(const wxString &filePath /*= wxT("") */) {
            if(!mFileEditors.count(filePath)) {
                // create and new editor and load file if available
                MuseStyledTextEditor *editor = new MuseStyledTextEditor(this, new lexer::MuseLexer());

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

        void MainFrame::createToolBar() {
            wxToolBar *toolbar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTB_DEFAULT_STYLE);
            toolbar->SetToolBitmapSize(wxSize(24, 24));

            toolbar->AddTool(ID_NewFile, wxT("&New File..."), wxArtProvider::GetBitmap(wxART_NEW));
            toolbar->AddTool(wxID_OPEN, wxT("&Open..."), wxArtProvider::GetBitmap(wxART_FILE_OPEN));
            toolbar->AddTool(wxID_SAVE, wxT("&Save"), wxArtProvider::GetBitmap(wxART_FILE_SAVE));
            toolbar->AddTool(wxID_SAVEAS, wxT("&Save as..."), wxArtProvider::GetBitmap(wxART_FILE_SAVE_AS));
            toolbar->AddSeparator();
            toolbar->AddTool(wxID_CUT, wxT("Cut"), wxArtProvider::GetBitmap(wxART_CUT));
            toolbar->AddTool(wxID_COPY, wxT("Copy"), wxArtProvider::GetBitmap(wxART_COPY));
            toolbar->AddTool(wxID_PASTE, wxT("Paste"), wxArtProvider::GetBitmap(wxART_PASTE));
            toolbar->AddSeparator();
            toolbar->AddTool(wxID_UNDO, wxT("Undo"), wxArtProvider::GetBitmap(wxART_UNDO));
            toolbar->AddTool(wxID_REDO, wxT("Redo"), wxArtProvider::GetBitmap(wxART_REDO));
            toolbar->AddSeparator();
            toolbar->AddTool(ID_Run, wxT("Play"), wxArtProvider::GetBitmap(museART_RUN));
            toolbar->AddTool(ID_Stop, wxT("Stop"), wxArtProvider::GetBitmap(museART_STOP));

            toolbar->Realize();

            SetToolBar(toolbar);
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
            preferencesEditor->AddPage(new ExecutionPage());
            preferencesEditor->Show(this);
        }

        void MainFrame::onRunRun(wxCommandEvent &event) {

        }

        void MainFrame::onRunStop(wxCommandEvent &event) {

        }
    }
}
