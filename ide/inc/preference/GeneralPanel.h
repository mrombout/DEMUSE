#ifndef DEMUSE_GENERALPANEL_H
#define DEMUSE_GENERALPANEL_H

#include <wx/panel.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>

namespace dem {
    namespace ide {
        class GeneralPanel : public wxPanel {
        public:
            GeneralPanel(wxWindow *parent);

            virtual bool TransferDataToWindow() override;
            virtual bool TransferDataFromWindow() override;

        private:
            void changedUserMarkdow(wxCommandEvent & e);

        private:
            wxCheckBox *mUserMarkdow;
        };
    }
}

#endif //DEMUSE_GENERALPANEL_H
