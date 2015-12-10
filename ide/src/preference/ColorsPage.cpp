#include "preference/ColorsPage.h"
#include "preference/ColorsPanel.h"

namespace dem {
    namespace ide {
        wxString ColorsPage::GetName() const {
            return wxT("Colors");
        }

        ColorsPage::ColorsPage() { }

        wxWindow *ColorsPage::CreateWindow(wxWindow *parent) {
            return new ColorsPanel(parent);
        }
    }
}