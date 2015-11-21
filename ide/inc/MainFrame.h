#ifndef DEMUSE_MAINFRAME_H
#define DEMUSE_MAINFRAME_H

#include <wx/frame.h>
#include <wx/event.h>
#include <wx/aui/aui.h>
#include <wx/dirctrl.h>

namespace dem {
    namespace ide {
        enum {
            ID_Hello = 1,
            ID_NewProject,
            ID_NewFile
        };

        class MainFrame : public wxFrame {
        public:
            MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
            ~MainFrame();

        private:
            void createMenu();
            void createStatuBar();
            void createFileNavigator();
            void createCenterNotebook();
            void createToolBar();

            void onHello(wxCommandEvent &event);
            void onExit(wxCommandEvent &event);
            void onAbout(wxCommandEvent &event);

            wxDECLARE_EVENT_TABLE();

            wxAuiManager mMgr;

            wxMenu *mFileMenu;
            wxMenu *mEditMenu;
            wxMenu *mHelpMenu;

            wxToolBar *mToolBar;

            wxGenericDirCtrl *mFileNavigator;

            wxAuiNotebook *mNotebook;
        };
    }
}

#endif //DEMUSE_MAINFRAME_H
