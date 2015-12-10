#include "preference/GeneralPage.h"
#include "preference/GeneralPanel.h"

namespace dem {
    namespace ide {
        GeneralPage::GeneralPage() : wxStockPreferencesPage(Kind_General) { }

        wxWindow *GeneralPage::CreateWindow(wxWindow *parent) {
            return new GeneralPanel(parent);
        }
    }
}