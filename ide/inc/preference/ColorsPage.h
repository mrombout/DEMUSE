#ifndef DEMUSE_COLORSPAGE_H
#define DEMUSE_COLORSPAGE_H

#include <wx/preferences.h>

namespace dem {
    namespace ide {
        class ColorsPage : public wxPreferencesPage {
        public:
            ColorsPage();
            virtual wxWindow *CreateWindow(wxWindow *parent) override;

            virtual wxString GetName() const;
        };
    }
}

#endif //DEMUSE_COLORSPAGE_H
