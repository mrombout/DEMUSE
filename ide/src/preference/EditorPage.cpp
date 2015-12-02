#include "preference/EditorPage.h"
#include "preference/EditorPanel.h"

namespace dem {
    namespace ide {
        wxString EditorPage::GetName() const {
            return wxT("Editor");
        }

        EditorPage::EditorPage() { }

        wxWindow *EditorPage::CreateWindow(wxWindow *parent) {
            return new EditorPanel(parent);
        }
    }
}