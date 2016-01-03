#include <wx/splash.h>
#include <wx/artprov.h>
#include "App.h"
//#include "MainFrame.h"
//#include "MuseArtProvider.h"

namespace dem {
    namespace ide {
        bool App::OnInit() {
            wxInitAllImageHandlers();

            SetAppName("DEMUSE IDE");
            //SetAppDisplayName("DEMUSE IDE");

            //mConfig = new wxFileConfig(GetAppName());

            //wxArtProvider::Push(new MuseArtProvider());

/*
            MainFrame *frame = new MainFrame(GetAppDisplayName(), wxPoint(50, 50), wxSize(800, 600));
#ifdef __WINDOWS__
            frame->SetIcon(wxICON(frame_icon));
#endif
            frame->Show(true);
*/

            return true;
        }

        int App::OnExit() {
            //delete mConfig;

            return wxAppBase::OnExit();
        }

        /*
        wxFileConfig &App::config() {
            return *mConfig;
        }
        */
    }
}
