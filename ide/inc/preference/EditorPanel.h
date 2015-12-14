#ifndef DEMUSE_EDITORPANEL_H
#define DEMUSE_EDITORPANEL_H

#include <wx/panel.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>

namespace dem {
    namespace ide {
        static const char *const KEY_EDITOR_SHOW_WHITESPACE = "editor/show_whitespace";
        static const char *const KEY_EDITOR_HIGHLIGHT_CURRENT_LINE = "editor/highlight_current_line";
        static const char *const KEY_EDITOR_USE_TABS = "editor/use_tabs";
        static const char *const KEY_EDITOR_SHOW_MAX_COLUMN_LINE = "editor/show_max_column_line";
        static const char *const KEY_EDITOR_TAB_WIDTH = "editor/tab_width";
        static const char *const KEY_EDITOR_MAX_COLUMN = "editor/max_column";
        static const char *const KEY_EDITOR_WRAP = "editor/wrap";

        class EditorPanel : public wxPanel {
        public:
            EditorPanel(wxWindow *parent);

            virtual bool TransferDataToWindow() override;
            virtual bool TransferDataFromWindow() override;

        private:
            void changedShowWhitespace(wxCommandEvent &e);
            void changedHighlightCurrentLine(wxCommandEvent &e);
            void changedUseTabs(wxCommandEvent &e);
            void changedShowMaxColumnLine(wxCommandEvent &e);
            void changedTabWidth(wxCommandEvent &e);
            void changedMaxColumn(wxCommandEvent &e);
            void changedWrap(wxCommandEvent &e);

        private:
            wxCheckBox *mShowWhitespace;
            wxCheckBox *mHighlightCurrentLine;
            wxCheckBox *mUseTabs;
            wxCheckBox *mShowMaxColumnLine;
            wxTextCtrl *mTabWidth;
            wxTextCtrl *mMaxColumn;
            wxCheckBox *mWrap;
        };
    }
}

#endif //DEMUSE_EDITORPANEL_H
