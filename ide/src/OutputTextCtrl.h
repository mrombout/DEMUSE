#ifndef DEMUSE_OUTPUTTEXTCTRL_H
#define DEMUSE_OUTPUTTEXTCTRL_H

#include <wx/textctrl.h>

namespace dem {
    namespace ide {
        class OutputTextCtrl : public wxTextCtrl {
        public:
            OutputTextCtrl(wxWindow *parent, wxWindowID id, const wxString& value = wxEmptyString, const wxPoint& pos = wxDefaultPosition,
                           const wxSize& size = wxDefaultSize, long style = 0, const wxValidator& validator = wxDefaultValidator,
                           const wxString& name = wxTextCtrlNameStr);

            void onTextUrl(wxTextUrlEvent &e);
        };
    }
}

#endif //DEMUSE_OUTPUTTEXTCTRL_H
