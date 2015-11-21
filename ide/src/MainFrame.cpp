#include <wx/menu.h>
#include <wx/log.h>
#include <wx/msgdlg.h>
#include <wx/textctrl.h>
#include <wx/stc/stc.h>
#include <wx/toolbar.h>
#include <wx/artprov.h>
#include <wx/dirctrl.h>
#include "MuseAuiDockArt.h"
#include "MuseAuiTabArt.h"
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
            mMgr.SetArtProvider(new MuseAuiDockArt());
            mMgr.GetArtProvider()->SetMetric(wxAUI_DOCKART_SASH_SIZE, 1);

            // create menu
            wxMenu *menuFile = new wxMenu;
            menuFile->Append(ID_Hello, "&Hello...\tCtrl-H", "Help string shown in status bar for this menu item");
            menuFile->AppendSeparator();
            menuFile->Append(wxID_EXIT);

            wxMenu *menuHelp = new wxMenu;
            menuHelp->Append(wxID_ABOUT);

            wxMenuBar *menuBar = new wxMenuBar;
            menuBar->Append(menuFile, "&File");
            menuBar->Append(menuHelp, "&Help");

            SetMenuBar(menuBar);

            // create statusbar
            CreateStatusBar();
            SetStatusText("Welcome to wxWidgets!");

            // create file tree
            wxGenericDirCtrl *fileTree = new wxGenericDirCtrl(this, -1, wxT("fsdfsdf"), wxDefaultPosition, wxDefaultSize, wxNO_BORDER);
            mMgr.AddPane(fileTree, wxAuiPaneInfo().Left().PaneBorder(false).Caption(wxT("File Navigator")).Name(wxT("File Navigator")));

            // create center notebook
            wxAuiNotebook *notebook = new wxAuiNotebook(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_TAB_SPLIT |
                                                        wxAUI_NB_TAB_MOVE | wxAUI_NB_CLOSE_ON_ALL_TABS | wxAUI_NB_MIDDLE_CLICK_CLOSE | wxNO_BORDER);
            notebook->GetAuiManager().GetArtProvider()->SetMetric(wxAUI_DOCKART_PANE_BORDER_SIZE, 0);
            notebook->SetArtProvider(new MuseAuiTabArt());
            mMgr.AddPane(notebook, wxAuiPaneInfo().Center().CaptionVisible(false).PaneBorder(false));

            // create text editor
            wxStyledTextCtrl *text = new wxStyledTextCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(200, 150), wxNO_BORDER);

            text->SetMarginWidth(1, 50);
            text->StyleSetForeground(wxSTC_STYLE_LINENUMBER, wxColour(75, 75, 75));
            text->StyleSetBackground(wxSTC_STYLE_LINENUMBER, wxColour(220, 220, 220));
            text->SetMarginType(1, wxSTC_MARGIN_NUMBER);

            text->SetWrapMode(wxSTC_WRAP_WORD);

            text->SetText("Lorum ipsum");

            notebook->AddPage(text, wxT("HelloWorld.muse"), false);

            // create toolbar
            wxToolBar *toolBar = CreateToolBar(wxTB_FLAT);
            toolBar->AddTool(1, wxT("Test"), wxArtProvider::GetBitmap(wxART_QUESTION));
            toolBar->Realize();

            //wxAuiToolBar *toolbar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_TB_DEFAULT_STYLE | wxAUI_TB_OVERFLOW | wxAUI_TB_GRIPPER);
            //wxBitmap exit;
            //toolbar->SetToolBitmapSize(wxSize(24, 24));
            //toolbar->AddTool(1, wxT("TEst"), wxArtProvider::GetBitmap(wxART_QUESTION));
            //toolbar->Realize();

            //mMgr.AddPane(toolbar, wxAuiPaneInfo().Name(wxT("tb1")).Caption(wxT("Bit Toolbar")).Top());

            mMgr.Update();
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
