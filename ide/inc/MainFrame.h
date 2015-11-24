#ifndef DEMUSE_MAINFRAME_H
#define DEMUSE_MAINFRAME_H

#include <wx/frame.h>
#include <wx/event.h>
#include <wx/aui/aui.h>
#include <wx/dirctrl.h>
#include <wx/stc/stc.h>

namespace dem {
    namespace ide {
        enum {
            ID_Hello = 1,
            ID_NewProject,
            ID_NewFile,
            ID_Run,
            ID_Stop
        };

        class MainFrame : public wxFrame {
        public:
            MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
            ~MainFrame();

        private:
            void createMenu();
            void createStatuBar();
            void createCenterNotebook();
            void createEditor();
            void createToolBar();

            void onHello(wxCommandEvent &event);
            void onExit(wxCommandEvent &event);
            void onAbout(wxCommandEvent &event);

            wxDECLARE_EVENT_TABLE();

            wxAuiManager mMgr;

            wxMenu *mFileMenu;
            wxMenu *mRunMenu;
            wxMenu *mEditMenu;
            wxMenu *mHelpMenu;

            wxAuiNotebook *mNotebook;
            wxStyledTextCtrl *mEditor;
        };
    }
}

#endif //DEMUSE_MAINFRAME_H
