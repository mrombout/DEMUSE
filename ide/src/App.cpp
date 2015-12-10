#include <wx/splash.h>
#include <wx/artprov.h>
#include <memory>
#include "App.h"
#include "MainFrame.h"
#include "MuseArtProvider.h"

namespace dem {
    namespace ide {
        bool dem::ide::App::OnInit() {
            wxInitAllImageHandlers();

            SetAppName("DEMUSE IDE");
            SetAppDisplayName("DEMUSE IDE");

            /*
            wxBitmap bitmap;
            if(bitmap.LoadFile("res/splash.png", wxBITMAP_TYPE_PNG)) {
                wxSplashScreen *splash = new wxSplashScreen(bitmap, wxSPLASH_CENTRE_ON_SCREEN | wxSPLASH_TIMEOUT, 6000, nullptr, -1, wxDefaultPosition, wxDefaultSize, wxNO_BORDER | wxSTAY_ON_TOP);
            }
            */

            wxArtProvider::Push(new MuseArtProvider());

            MainFrame *frame = new MainFrame(GetAppDisplayName(), wxPoint(50, 50), wxSize(450, 340));
#ifdef __WINDOWS__
            frame->SetIcon(wxICON(frame_icon));
#endif
            frame->Show(true);

            return true;
        }
    }
}
