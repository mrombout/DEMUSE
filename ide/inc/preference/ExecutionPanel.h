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
            ExecutionPanel(wxWindow *parent);

            virtual bool TransferDataToWindow() override;
            virtual bool TransferDataFromWindow() override;

            void changedMediaPlayerPath(wxCommandEvent &e);

        private:
            wxFilePickerCtrl *mMediaPlayerPath;
        };
    }
}

#endif //DEMUSE_EXECUTIONPANEL_H
