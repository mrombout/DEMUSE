#ifndef DEMUSE_MUSEAUITABART_H
#define DEMUSE_MUSEAUITABART_H

#include <wx/aui/aui.h>

namespace dem {
    namespace ide {
        class MuseAuiTabArt : public wxAuiTabArt {
        public:
            MuseAuiTabArt();
            virtual ~MuseAuiTabArt();

            wxAuiTabArt* Clone();
            void SetFlags(unsigned int flags);
            void SetSizingInfo(const wxSize& tabCtrlSize,
                               size_t tabCount);

            void SetNormalFont(const wxFont& font);
            void SetSelectedFont(const wxFont& font);
            void SetMeasuringFont(const wxFont& font);
            void SetColour(const wxColour& colour);
            void SetActiveColour(const wxColour& colour);

            void DrawBorder(
                    wxDC& dc,
                    wxWindow* wnd,
                    const wxRect& rect);

            void DrawBackground(
                    wxDC& dc,
                    wxWindow* wnd,
                    const wxRect& rect);

            void DrawTab(wxDC& dc,
                         wxWindow* wnd,
                         const wxAuiNotebookPage& pane,
                         const wxRect& inRect,
                         int closeButtonState,
                         wxRect* outTabRect,
                         wxRect* outButtonRect,
                         int* xExtent);

            void DrawButton(
                    wxDC& dc,
                    wxWindow* wnd,
                    const wxRect& inRect,
                    int bitmapId,
                    int buttonState,
                    int orientation,
                    wxRect* outRect);

            int GetIndentSize();

            int GetBorderWidth(
                    wxWindow* wnd);

            int GetAdditionalBorderSpace(
                    wxWindow* wnd);

            wxSize GetTabSize(
                    wxDC& dc,
                    wxWindow* wnd,
                    const wxString& caption,
                    const wxBitmap& bitmap,
                    bool active,
                    int closeButtonState,
                    int* xExtent);

            int ShowDropDown(
                    wxWindow* wnd,
                    const wxAuiNotebookPageArray& items,
                    int activeIdx);

            int GetBestTabCtrlSize(wxWindow* wnd,
                                   const wxAuiNotebookPageArray& pages,
                                   const wxSize& requiredBmpSize);

        protected:

            wxFont m_normalFont;
            wxFont m_selectedFont;
            wxFont m_measuringFont;
            wxColour m_baseColour;
            wxPen m_baseColourPen;
            wxPen m_borderPen;
            wxBrush m_baseColourBrush;
            wxColour m_activeColour;
            wxBitmap m_activeCloseBmp;
            wxBitmap m_disabledCloseBmp;
            wxBitmap m_activeLeftBmp;
            wxBitmap m_disabledLeftBmp;
            wxBitmap m_activeRightBmp;
            wxBitmap m_disabledRightBmp;
            wxBitmap m_activeWindowListBmp;
            wxBitmap m_disabledWindowListBmp;

            wxPen mMainPen;
            wxBrush mMainBrush;

            wxColour mBackgroundColor;
            wxColour mInactiveBackgroundColor;
            wxColour mActiveBackgroundColor;
            wxColour mBorderColor;

            int m_fixedTabWidth;
            int m_tabCtrlHeight;
            unsigned int m_flags;
        };
    }
}


#endif //DEMUSE_MUSEAUITABART_H
