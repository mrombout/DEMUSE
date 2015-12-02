#ifndef DEMUSE_GENERALPANEL_H
#define DEMUSE_GENERALPANEL_H

#include <wx/panel.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>

namespace dem {
    namespace ide {
        class GeneralPanel : public wxPanel {
        public:
            GeneralPanel(wxWindow *parent) :
                    wxPanel(parent) {
                mUserMarkdow = new wxCheckBox(this, wxID_ANY, "Testbox!");

                wxSizer *sizer = new wxBoxSizer(wxVERTICAL);
                sizer->Add(mUserMarkdow, wxSizerFlags().Border());

                SetSizerAndFit(sizer);
            }

        private:
            wxCheckBox *mUserMarkdow;
        };
    }
}

#endif //DEMUSE_GENERALPANEL_H
