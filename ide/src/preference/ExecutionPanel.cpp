#include <wx/preferences.h>
#include <App.h>
#include "preference/ExecutionPanel.h"

namespace dem {
    namespace ide {
        ExecutionPanel::ExecutionPanel(wxWindow *parent) : wxPanel(parent) {
            wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
            wxFlexGridSizer *fgs = new wxFlexGridSizer(3, 2, 9, 25);

            wxStaticText *compilerPathLabel = new wxStaticText(this, wxID_ANY, wxT("Compiler"));
            mCompilerPath = new wxFilePickerCtrl(this, wxID_ANY, "Compiler Path");

            wxStaticText *mediaPlayerPathLabel = new wxStaticText(this, wxID_ANY, wxT("Media Player"));
            mMediaPlayerPath = new wxFilePickerCtrl(this, wxID_ANY, "Mediaplayer Path");

            fgs->Add(compilerPathLabel);
            fgs->Add(mCompilerPath);
            fgs->Add(mediaPlayerPathLabel);
            fgs->Add(mMediaPlayerPath);

            fgs->AddGrowableRow(2, 1);
            fgs->AddGrowableCol(1, 1);

            hbox->Add(fgs, 1, wxALL | wxEXPAND, 15);

            SetSizerAndFit(hbox);

            if(wxPreferencesEditor::ShouldApplyChangesImmediately()) {
                mCompilerPath->Connect(wxEVT_CHECKBOX, wxCommandEventHandler(ExecutionPanel::changedCompilerPath), nullptr, this);
                mMediaPlayerPath->Connect(wxEVT_CHECKBOX, wxCommandEventHandler(ExecutionPanel::changedMediaPlayerPath), nullptr, this);
            }
        }

        bool ExecutionPanel::TransferDataToWindow() {
            wxFileConfig &config = wxGetApp().config();

            wxString compiler = config.Read("execution/compiler");
            wxString mediaPlayer = config.Read("execution/media_player");

            mCompilerPath->SetFileName(compiler);
            mMediaPlayerPath->SetFileName(mediaPlayer);

            return true;
        }

        bool ExecutionPanel::TransferDataFromWindow() {
            wxCommandEvent dummy;
            changedCompilerPath(dummy);
            changedMediaPlayerPath(dummy);

            return true;
        }

        void ExecutionPanel::changedCompilerPath(wxCommandEvent &e) {
            wxFileConfig &config = wxGetApp().config();
            config.Write("execution/compiler", mCompilerPath->GetPath());
        }

        void ExecutionPanel::changedMediaPlayerPath(wxCommandEvent &e) {
            wxFileConfig &config = wxGetApp().config();
            config.Write("execution/media_player", mMediaPlayerPath->GetPath());
        }
    }
}
