#ifndef DEMUSE_GENERALPAGE_H
#define DEMUSE_GENERALPAGE_H

#include <wx/preferences.h>

namespace dem {
    namespace ide {
        class GeneralPage : public wxStockPreferencesPage {
        public:
            GeneralPage();
            virtual wxWindow *CreateWindow(wxWindow *parent) override;
        };
    }
}

#endif //DEMUSE_GENERALPAGE_H
