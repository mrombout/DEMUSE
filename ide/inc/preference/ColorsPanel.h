#ifndef DEMUSE_COLORSPANEL_H
#define DEMUSE_COLORSPANEL_H

#include <wx/panel.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/filepicker.h>
#include <wx/propgrid/propgrid.h>
#include <wx/propgrid/advprops.h>

namespace dem {
    namespace ide {
        class ColorsPanel : public wxPanel {
        public:
            ColorsPanel(wxWindow *parent) :
                    wxPanel(parent) {
                wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);

                wxPropertyGrid *pg = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_AUTO_SORT | wxPG_SPLITTER_AUTO_CENTER | wxPG_DEFAULT_STYLE);

                vbox->Add(pg, 1, wxEXPAND | wxALL);

                // TODO: Persist preferences in ColorsPanel

                pg->Append(new wxPropertyCategory("Default"));
                pg->Append(new wxColourProperty("Background", "Default Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Default Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Default Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Default Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Default Underline", false));

                pg->Append(new wxPropertyCategory("Boolean"));
                pg->Append(new wxColourProperty("Background", "Boolean Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Boolean Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Boolean Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Boolean Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Boolean Underline", false));

                pg->Append(new wxPropertyCategory("Text"));
                pg->Append(new wxColourProperty("Background", "Text Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Text Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Text Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Text Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Text Underline", false));

                pg->Append(new wxPropertyCategory("Number"));
                pg->Append(new wxColourProperty("Background", "Number Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Number Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Number Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Number Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Number Underline", false));

                pg->Append(new wxPropertyCategory("Operator"));
                pg->Append(new wxColourProperty("Background", "Operator Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Operator Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Operator Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Operator Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Operator Underline", false));

                pg->Append(new wxPropertyCategory("Condition"));
                pg->Append(new wxColourProperty("Background", "Condition Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Condition Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Condition Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Condition Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Condition Underline", false));

                pg->Append(new wxPropertyCategory("Unary"));
                pg->Append(new wxColourProperty("Background", "Unary Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Unary Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Unary Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Unary Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Unary Underline", false));

                pg->Append(new wxPropertyCategory("Keyword"));
                pg->Append(new wxColourProperty("Background", "Keyword Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Keyword Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Keyword Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Keyword Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Keyword Underline", false));

                pg->Append(new wxPropertyCategory("Track"));
                pg->Append(new wxColourProperty("Background", "Track Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Track Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Track Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Track Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Track Underline", false));

                pg->Append(new wxPropertyCategory("Note"));
                pg->Append(new wxColourProperty("Background", "Note Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Note Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Note Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Note Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Note Underline", false));

                pg->Append(new wxPropertyCategory("Accidental"));
                pg->Append(new wxColourProperty("Background", "Accidental Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Accidental Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Accidental Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Accidental Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Accidental Underline", false));

                pg->Append(new wxPropertyCategory("Octave"));
                pg->Append(new wxColourProperty("Background", "Octave Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Octave Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Octave Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Octave Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Octave Underline", false));

                pg->Append(new wxPropertyCategory("Chord"));
                pg->Append(new wxColourProperty("Background", "Chord Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Chord Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Chord Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Chord Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Chord Underline", false));

                pg->Append(new wxPropertyCategory("Duration"));
                pg->Append(new wxColourProperty("Background", "Duration Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Duration Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Duration Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Duration Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Duration Underline", false));

                pg->Append(new wxPropertyCategory("Block"));
                pg->Append(new wxColourProperty("Background", "Block Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Block Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Block Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Block Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Block Underline", false));

                pg->Append(new wxPropertyCategory("Parenthesis"));
                pg->Append(new wxColourProperty("Background", "Parenthesis Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Parenthesis Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Parenthesis Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Parenthesis Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Parenthesis Underline", false));

                pg->Append(new wxPropertyCategory("Bracket"));
                pg->Append(new wxColourProperty("Background", "Bracket Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Bracket Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Bracket Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Bracket Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Bracket Underline", false));

                pg->Append(new wxPropertyCategory("Play"));
                pg->Append(new wxColourProperty("Background", "Play Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Play Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Play Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Play Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Play Underline", false));

                pg->Append(new wxPropertyCategory("Function"));
                pg->Append(new wxColourProperty("Background", "Function Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Function Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Function Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Function Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Function Underline", false));

                pg->Append(new wxPropertyCategory("Var"));
                pg->Append(new wxColourProperty("Background", "Var Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Var Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Var Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Var Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Var Underline", false));

                pg->Append(new wxPropertyCategory("Terminator"));
                pg->Append(new wxColourProperty("Background", "Terminator Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Terminator Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Terminator Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Terminator Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Terminator Underline", false));

                pg->Append(new wxPropertyCategory("Identifier"));
                pg->Append(new wxColourProperty("Background", "Identifier Background", wxColour(242, 109, 0)));
                pg->Append(new wxColourProperty("Foreground", "Identifier Foreground", wxColour(242, 109, 0)));
                pg->Append(new wxBoolProperty("Bold", "Identifier Bold", false));
                pg->Append(new wxBoolProperty("Italic", "Identifier Italic", false));
                pg->Append(new wxBoolProperty("Underline", "Identifier Underline", false));

                SetSizerAndFit(vbox);
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

#endif //DEMUSE_COLORSPANEL_H
