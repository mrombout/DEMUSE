#include "OutputTextCtrl.h"

namespace dem {
    namespace ide {
        OutputTextCtrl::OutputTextCtrl(wxWindow *parent, wxWindowID id, const wxString &value, const wxPoint &pos,
                                       const wxSize &size, long style, const wxValidator &validator, const wxString &name) :
                wxTextCtrl(parent, id, value, pos, size, style, validator, name) {
            this->Bind(wxEVT_TEXT_URL, &OutputTextCtrl::onTextUrl, this, wxID_ANY);
        }

        void OutputTextCtrl::onTextUrl(wxTextUrlEvent &e) {
            if(e.GetMouseEvent().ButtonDClick(wxMOUSE_BTN_LEFT)) {
                wxString url{GetRange(e.GetURLStart(), e.GetURLEnd())};
                // TODO: Do something with this
            }
        }
    }
}

