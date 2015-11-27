#include <MainFrame.h>
#include "MuseArtProvider.h"

namespace dem {
    namespace ide {
        wxBitmap MuseArtProvider::CreateBitmap(const wxArtID &id, const wxArtClient &client, const wxSize &size) {
            if (id == museART_RUN) {
#ifdef __WXGTK__
                return wxArtProvider::GetBitmap("gtk-media-play");
#else
                return wxBitmap(wxT("res/icon/media-playback-start.png"), wxBITMAP_TYPE_PNG);
#endif
            } else if(id == museART_STOP) {
#ifdef __WXGTK__
                return wxArtProvider::GetBitmap("gtk-media-stop");
#else
                return wxBitmap(wxT("res/icon/media-playback-stop.png"), wxBITMAP_TYPE_PNG);
#endif
            }

            return wxArtProvider::CreateBitmap(id, client, size);
        }
    }
}