#include <wx/preferences.h>
#include <App.h>
#include "preference/ExecutionPanel.h"

namespace dem {
    namespace ide {
        ExecutionPanel::ExecutionPanel(wxWindow *parent) : wxPanel(parent) {
            wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
            wxFlexGridSizer *fgs = new wxFlexGridSizer(3, 2, 9, 25);

            wxStaticText *mediaPlayerPathLabel = new wxStaticText(this, wxID_ANY, wxT("Media Player"));
            mMediaPlayerPath = new wxFilePickerCtrl(this, wxID_ANY, "Mediaplayer Path");

            fgs->Add(mediaPlayerPathLabel);
            fgs->Add(mMediaPlayerPath);

            fgs->AddGrowableRow(2, 1);
            fgs->AddGrowableCol(1, 1);

            hbox->Add(fgs, 1, wxALL | wxEXPAND, 15);

            SetSizerAndFit(hbox);

            if(wxPreferencesEditor::ShouldApplyChangesImmediately()) {
                mMediaPlayerPath->Connect(wxEVT_CHECKBOX, wxCommandEventHandler(ExecutionPanel::changedMediaPlayerPath), nullptr, this);
            }
        }

        bool ExecutionPanel::TransferDataToWindow() {
            wxFileConfig &config = wxGetApp().config();

            wxString mediaPlayer = config.Read("execution/media_player");

            mMediaPlayerPath->SetFileName(mediaPlayer);

            return true;
        }

        bool ExecutionPanel::TransferDataFromWindow() {
            wxCommandEvent dummy;
            changedMediaPlayerPath(dummy);

            return true;
        }

        void ExecutionPanel::changedMediaPlayerPath(wxCommandEvent &e) {
            wxFileConfig &config = wxGetApp().config();
            config.Write("execution/media_player", mMediaPlayerPath->GetPath());
        }
    }
}
