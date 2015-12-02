#include "preference/ExecutionPage.h"
#include "preference/ExecutionPanel.h"

namespace dem {
    namespace ide {
        wxString ExecutionPage::GetName() const {
            return wxT("Execution");
        }

        ExecutionPage::ExecutionPage() { }

        wxWindow *ExecutionPage::CreateWindow(wxWindow *parent) {
            return new ExecutionPanel(parent);
        }
    }
}