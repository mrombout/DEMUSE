#ifndef DEMUSE_MUSEAUIDOCKART_H
#define DEMUSE_MUSEAUIDOCKART_H

#include <wx/aui/aui.h>

namespace dem {
    namespace ide {
        class MuseAuiDockArt : public wxAuiDefaultDockArt {
        public:
            MuseAuiDockArt();
            
            virtual void DrawBackground(wxDC &dc, wxWindow *window, int orientation, const wxRect &rect) override;

            virtual void DrawCaption(wxDC &dc, wxWindow *window, const wxString &text, const wxRect &rect, wxAuiPaneInfo &pane) override;
            virtual void DrawSash(wxDC &dc, wxWindow *window, int orientation, const wxRect &rect) override;

        };
    }
}

#endif //DEMUSE_MUSEAUIDOCKART_H
