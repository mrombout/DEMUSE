#include "MuseAuiDockArt.h"
#include <wx/dc.h>

namespace dem {
    namespace ide {
        MuseAuiDockArt::MuseAuiDockArt() {
            SetMetric(wxAUI_DOCKART_CAPTION_SIZE, 27);
        }

        void MuseAuiDockArt::DrawCaption(wxDC &dc, wxWindow *window, const wxString &text, const wxRect &rect, wxAuiPaneInfo &pane) {
            wxAuiDefaultDockArt::DrawCaption(dc, window, text, rect, pane);

            dc.SetPen(wxPen(wxColour(155, 155, 155, 255)));
            dc.SetBrush(wxBrush(wxColour(155, 155, 155, 255)));
            dc.DrawRectangle(rect.x, rect.y + rect.height - 1, rect.width, rect.height);
        }

        void MuseAuiDockArt::DrawSash(wxDC &dc, wxWindow *window, int orientation, const wxRect &rect) {
            dc.SetPen(wxPen(wxColour(155, 155, 155, 255)));
            dc.SetBrush(wxBrush(wxColour(155, 155, 155, 255)));
            dc.DrawRectangle(rect);
        }

        void MuseAuiDockArt::DrawBackground(wxDC &dc, wxWindow *window, int orientation, const wxRect &rect) {
            dc.SetPen(*wxRED_PEN);
            dc.SetBrush(*wxRED_BRUSH);
            dc.DrawRectangle(rect);
        }
    }
}
