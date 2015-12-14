#include <App.h>
#include "preference/EditorPanel.h"

namespace dem {
    namespace ide {
        EditorPanel::EditorPanel(wxWindow *parent) : wxPanel(parent) {
            wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
            wxFlexGridSizer *fgs = new wxFlexGridSizer(7, 2, 9, 25);

            mShowWhitespace = new wxCheckBox(this, wxID_ANY, "Show whitespace characters");

            mHighlightCurrentLine = new wxCheckBox(this, wxID_ANY, "Highlight current line");

            mUseTabs = new wxCheckBox(this, wxID_ANY, "Use tabs instead of spaces");

            wxStaticText *tabWidthLabel = new wxStaticText(this, wxID_ANY, wxT("Tab width"));
            mTabWidth = new wxTextCtrl(this, wxID_ANY, "4");

            mShowMaxColumnLine = new wxCheckBox(this, wxID_ANY, "Show max column line");

            wxStaticText *maxColumnLabel = new wxStaticText(this, wxID_ANY, wxT("Max column"));
            mMaxColumn = new wxTextCtrl(this, wxID_ANY, "4");

            mWrap = new wxCheckBox(this, wxID_ANY, "Wrap text");

            fgs->Add(mShowWhitespace);
            fgs->AddSpacer(1);
            fgs->Add(mHighlightCurrentLine);
            fgs->AddSpacer(1);
            fgs->Add(mUseTabs);
            fgs->AddSpacer(1);
            fgs->Add(tabWidthLabel);
            fgs->Add(mTabWidth);
            fgs->Add(mShowMaxColumnLine);
            fgs->AddSpacer(1);
            fgs->Add(maxColumnLabel);
            fgs->Add(mMaxColumn);
            fgs->Add(mWrap);
            fgs->AddSpacer(1);

            fgs->AddGrowableRow(2, 1);
            fgs->AddGrowableCol(1, 1);

            hbox->Add(fgs, 1, wxALL | wxEXPAND, 15);

            SetSizerAndFit(hbox);
        }

        bool EditorPanel::TransferDataToWindow() {
            wxFileConfig &config = wxGetApp().config();

            bool showWhitespace       = config.ReadBool(KEY_EDITOR_SHOW_WHITESPACE, false);
            bool highlightCurrentLine = config.ReadBool(KEY_EDITOR_HIGHLIGHT_CURRENT_LINE, true);
            bool useTabs              = config.ReadBool(KEY_EDITOR_USE_TABS, false);
            bool showMaxColumnLine    = config.ReadBool(KEY_EDITOR_SHOW_MAX_COLUMN_LINE, true);
            long tabWidth             = config.ReadLong(KEY_EDITOR_TAB_WIDTH, 4);
            long maxColumn            = config.ReadLong(KEY_EDITOR_MAX_COLUMN, 120);
            bool wrap                 = config.ReadBool(KEY_EDITOR_WRAP, false);

            mShowWhitespace->SetValue(showWhitespace);
            mHighlightCurrentLine->SetValue(highlightCurrentLine);
            mUseTabs->SetValue(useTabs);
            mShowMaxColumnLine->SetValue(showMaxColumnLine);
            mTabWidth->SetValue(wxString::Format(wxT("%ld"), tabWidth));
            mMaxColumn->SetValue(wxString::Format(wxT("%ld"), maxColumn));
            mWrap->SetValue(wrap);

            return true;
        }

        bool EditorPanel::TransferDataFromWindow() {
            wxCommandEvent dummy;
            changedShowWhitespace(dummy);
            changedHighlightCurrentLine(dummy);
            changedUseTabs(dummy);
            changedShowMaxColumnLine(dummy);
            changedTabWidth(dummy);
            changedMaxColumn(dummy);
            changedWrap(dummy);

            return true;
        }

        void EditorPanel::changedShowWhitespace(wxCommandEvent &e) {
            wxFileConfig &config = wxGetApp().config();
            config.Write(KEY_EDITOR_SHOW_WHITESPACE, mShowWhitespace->GetValue());
        }

        void EditorPanel::changedHighlightCurrentLine(wxCommandEvent &e) {
            wxFileConfig &config = wxGetApp().config();
            config.Write(KEY_EDITOR_HIGHLIGHT_CURRENT_LINE, mHighlightCurrentLine->GetValue());
        }

        void EditorPanel::changedUseTabs(wxCommandEvent &e) {
            wxFileConfig &config = wxGetApp().config();
            config.Write(KEY_EDITOR_USE_TABS, mUseTabs->GetValue());
        }

        void EditorPanel::changedShowMaxColumnLine(wxCommandEvent &e) {
            wxFileConfig &config = wxGetApp().config();
            config.Write(KEY_EDITOR_SHOW_MAX_COLUMN_LINE, mShowMaxColumnLine->GetValue());
        }

        void EditorPanel::changedTabWidth(wxCommandEvent &e) {
            wxFileConfig &config = wxGetApp().config();
            config.Write(KEY_EDITOR_TAB_WIDTH, mTabWidth->GetValue());
        }

        void EditorPanel::changedMaxColumn(wxCommandEvent &e) {
            wxFileConfig &config = wxGetApp().config();
            config.Write(KEY_EDITOR_MAX_COLUMN, mMaxColumn->GetValue());
        }

        void EditorPanel::changedWrap(wxCommandEvent &e) {
            wxFileConfig &config = wxGetApp().config();
            config.Write(KEY_EDITOR_WRAP, mWrap->GetValue());
        }
    }
}
