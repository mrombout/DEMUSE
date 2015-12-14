#include <wx/preferences.h>
#include "preference/GeneralPanel.h"
#include "App.h"

namespace dem {
    namespace ide {
        GeneralPanel::GeneralPanel(wxWindow *parent) : wxPanel(parent) {
            mUserMarkdow = new wxCheckBox(this, wxID_ANY, "Testbox!");

            wxSizer *sizer = new wxBoxSizer(wxVERTICAL);
            sizer->Add(mUserMarkdow, wxSizerFlags().Border());

            SetSizerAndFit(sizer);

            if(wxPreferencesEditor::ShouldApplyChangesImmediately()) {
                mUserMarkdow->Connect(wxEVT_CHECKBOX, wxCommandEventHandler(GeneralPanel::changedUserMarkdow), nullptr, this);
            }
        }

        bool GeneralPanel::TransferDataToWindow() {
            wxFileConfig &config = wxGetApp().config();

            bool usermardow = config.ReadBool("general/usermardow", false);
            mUserMarkdow->SetValue(usermardow);

            return true;
        }

        bool GeneralPanel::TransferDataFromWindow() {
            wxCommandEvent dummy;
            changedUserMarkdow(dummy);

            return true;
        }

        void GeneralPanel::changedUserMarkdow(wxCommandEvent & e) {
            wxFileConfig &config = wxGetApp().config();
            config.Write("general/usermardow", mUserMarkdow->GetValue());
        }
    }
}
