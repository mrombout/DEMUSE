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
        class EditorPanel : public wxPanel {
        public:
            EditorPanel(wxWindow *parent) :
                    wxPanel(parent) {
                wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
                wxFlexGridSizer *fgs = new wxFlexGridSizer(7, 2, 9, 25);

                // TODO: Persist all preferences on EditorPanel

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
