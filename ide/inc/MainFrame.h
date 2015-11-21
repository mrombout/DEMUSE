#ifndef DEMUSE_MAINFRAME_H
#define DEMUSE_MAINFRAME_H

#include <wx/frame.h>
#include <wx/event.h>
#include <wx/aui/aui.h>

namespace dem {
    namespace ide {
        enum {
            ID_Hello = 1
        };

        class MainFrame : public wxFrame {
        public:
            MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
            ~MainFrame();

        private:
            void onHello(wxCommandEvent &event);
            void onExit(wxCommandEvent &event);
            void onAbout(wxCommandEvent &event);

            wxDECLARE_EVENT_TABLE();

            wxAuiManager mMgr;
        };
    }
}

#endif //DEMUSE_MAINFRAME_H
