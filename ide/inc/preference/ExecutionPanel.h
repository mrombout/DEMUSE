#ifndef DEMUSE_EXECUTIONPANEL_H
#define DEMUSE_EXECUTIONPANEL_H

#include <wx/panel.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>

namespace dem {
    namespace ide {
        class ExecutionPanel : public wxPanel {
        public:
            ExecutionPanel(wxWindow *parent) :
                    wxPanel(parent) {
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
            }

        private:
            wxFilePickerCtrl *mCompilerPath;
            wxFilePickerCtrl *mMediaPlayerPath;
        };
    }
}

#endif //DEMUSE_EXECUTIONPANEL_H
