#ifndef DEMUSE_MUSEARTPROVIDER_H
#define DEMUSE_MUSEARTPROVIDER_H

#include <wx/artprov.h>

#define museART_RUN wxART_MAKE_ART_ID_FROM_STR("muse-run")
#define museART_STOP wxART_MAKE_ART_ID_FROM_STR("muse-stop")
#define museART_FUNCTION wxART_MAKE_ART_ID_FROM_STR("muse-function")
#define museART_VARIABLE wxART_MAKE_ART_ID_FROM_STR("muse-variable")

namespace dem {
    namespace ide {
        class MuseArtProvider : public wxArtProvider {

        protected:
            virtual wxBitmap CreateBitmap(const wxArtID &id, const wxArtClient &client, const wxSize &size) override;
        };
    }
}

#endif //DEMUSE_MUSEARTPROVIDER_H
