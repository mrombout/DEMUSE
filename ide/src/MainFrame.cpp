#include <wx/menu.h>
#include <wx/log.h>
#include <wx/msgdlg.h>
#include <wx/textctrl.h>
#include <wx/stc/stc.h>
#include <wx/toolbar.h>
#include <wx/artprov.h>
#include "MainFrame.h"

namespace dem {
    namespace ide {
        wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
            EVT_MENU(ID_Hello,   MainFrame::onHello)
            EVT_MENU(wxID_EXIT,  MainFrame::onExit)
            EVT_MENU(wxID_ABOUT, MainFrame::onAbout)
        wxEND_EVENT_TABLE()

        MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size) :
            wxFrame(nullptr, wxID_ANY, title, pos, size) {
            // notify wxAUI which frame to use
            mMgr.SetManagedWindow(this);

            createMenu();
            createStatuBar();

            createFileNavigator();
            createCenterNotebook();

            createToolBar();

            mMgr.Update();
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

        void MainFrame::createFileNavigator() {
            mFileNavigator = new wxGenericDirCtrl(this, -1, wxT("fsdfsdf"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
            mMgr.AddPane(mFileNavigator, wxAuiPaneInfo().Left().Caption(wxT("File Navigator")).Name(wxT("File Navigator")));
        }

        void MainFrame::createCenterNotebook() {
            mNotebook = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
                                                    wxAUI_NB_TAB_SPLIT |
                                                    wxAUI_NB_TAB_MOVE | wxAUI_NB_CLOSE_ON_ALL_TABS |
                                                    wxAUI_NB_MIDDLE_CLICK_CLOSE | wxNO_BORDER);
            mMgr.AddPane(mNotebook, wxAuiPaneInfo().Center().CaptionVisible(false)/*.PaneBorder(false)*/);
        }

        void MainFrame::createToolBar() {
            wxAuiToolBar *toolbar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW);
            wxBitmap exit;
            toolbar->SetToolBitmapSize(wxSize(24, 24));
            toolbar->AddTool(1, wxT("TEst"), wxArtProvider::GetBitmap(wxART_QUESTION));
            toolbar->Realize();

            mMgr.AddPane(toolbar, wxAuiPaneInfo().Name(wxT("tb1")).ToolbarPane().Caption(wxT("Bit Toolbar")).Top());
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
            mMgr.UnInit();
        }
    }
}
