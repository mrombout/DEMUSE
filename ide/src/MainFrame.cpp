#include <wx/menu.h>
#include <wx/log.h>
#include <wx/msgdlg.h>
#include <wx/textctrl.h>
#include <wx/stc/stc.h>
#include <wx/toolbar.h>
#include <wx/artprov.h>
#include "MainFrame.h"
#include "MuseAuiTabArt.h"

namespace dem {
    namespace ide {
        wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
            EVT_MENU(ID_Hello,   MainFrame::onHello)
            EVT_MENU(wxID_EXIT,  MainFrame::onExit)
            EVT_MENU(wxID_ABOUT, MainFrame::onAbout)
        wxEND_EVENT_TABLE()

        MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) :
            wxFrame(nullptr, wxID_ANY, title, pos, size) {
            createMenu();
            createStatuBar();

            createCenterNotebook();
            createEditor();

            createToolBar();
        }

        void MainFrame::createMenu() {
            // create menu
            mFileMenu = new wxMenu;
            mFileMenu->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
            mFileMenu->Append(ID_NewProject, "New &Project...", "Create a new DEMUSE project.");
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

        void MainFrame::createStatuBar() {
            CreateStatusBar();
            SetStatusText("Welcome to wxWidgets!");
        }

        void MainFrame::createCenterNotebook() {
            mNotebook = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                                    wxAUI_NB_TAB_SPLIT |
                                                    wxAUI_NB_TAB_MOVE | wxAUI_NB_CLOSE_ON_ALL_TABS |
                                                    wxAUI_NB_MIDDLE_CLICK_CLOSE | wxNO_BORDER);
            mNotebook->SetArtProvider(new MuseAuiTabArt);
            mMgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_PANE_BORDER_SIZE, 0);
        }

        void MainFrame::createEditor() {
            mEditor = new MuseStyledTextEditor(this);
            mNotebook->AddPage(mEditor, "music.muse");
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
            toolbar->AddTool(ID_Run, wxT("Play"), wxArtProvider::GetBitmap(wxART_UNDO));
            toolbar->AddTool(ID_Stop, wxT("Stop"), wxArtProvider::GetBitmap(wxART_REDO));

            toolbar->Realize();

            SetToolBar(toolbar);
        }

        void MainFrame::onHello(wxCommandEvent &event) {
            wxLogMessage("Hello world from wxWidgets!");
        }

        void MainFrame::onExit(wxCommandEvent &event) {
            Close(true);
        }

        void MainFrame::onAbout(wxCommandEvent &event) {
            wxMessageBox("This is a wxWidgets' Hello World sample", "About Hello World", wxOK | wxICON_INFORMATION);
        }

        MainFrame::~MainFrame() {

        }
    }
}
