#include "MuseStyledTextEditor.h"

namespace dem {
    namespace ide {
        MuseStyledTextEditor::MuseStyledTextEditor(wxWindow *parent) :
                wxStyledTextCtrl(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER) {
            SetStyleBits(8);

            // defaults
            SetViewEOL(false);
            SetIndentationGuides(true);
            SetEdgeMode(wxSTC_EDGE_LINE);
            SetViewWhiteSpace(false);
            SetOvertype(false);
            SetReadOnly(false);
            SetWrapMode(wxSTC_WRAP_NONE);

            SetTabWidth(4);
            SetUseTabs(false);
            SetTabIndents(true);
            SetBackSpaceUnIndents(true);

            wxFont font(wxFontInfo(10).Family(wxFONTFAMILY_MODERN));
            StyleSetFont(wxSTC_STYLE_DEFAULT, font);
            StyleSetForeground(wxSTC_STYLE_DEFAULT, *wxBLACK);
            StyleSetBackground(wxSTC_STYLE_DEFAULT, *wxWHITE);
            StyleSetForeground(wxSTC_STYLE_INDENTGUIDE, wxColour(wxT("DARK GREY")));

            // line margin
            SetMarginWidth(MARGIN_LINE_NUMBERS, 50);
            // TODO: Set text color to darkred
            SetMarginType(MARGIN_LINE_NUMBERS, wxSTC_MARGIN_NUMBER);

            // TODO: Folding
            // TODO: Brace match
            // TODO: Autoindent

            // syntax highlighting
            StyleClearAll();
            SetLexer(wxSTC_LEX_CPP);

            StyleSetForeground(wxSTC_C_STRING,                 wxColour(0, 150, 0));
            StyleSetForeground(wxSTC_C_CHARACTER,              wxColour(0, 150, 0));
            StyleSetForeground(wxSTC_C_COMMENT,                wxColour(100, 100, 100));
            StyleSetForeground(wxSTC_C_COMMENTDOC,             wxColour(100, 100, 100));
            StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORD,      wxColour(100, 100, 100));
            StyleSetForeground(wxSTC_C_COMMENTDOCKEYWORDERROR, wxColour(100, 100, 100));
            StyleSetForeground(wxSTC_C_COMMENTLINE,            wxColour(100, 100, 100));
            StyleSetForeground(wxSTC_C_COMMENTLINEDOC,         wxColour(100, 100, 100));
            StyleSetForeground(wxSTC_C_DEFAULT,                wxColour(0, 0, 0));
            StyleSetForeground(wxSTC_C_GLOBALCLASS,            wxColour(0, 0, 0));
            StyleSetForeground(wxSTC_C_HASHQUOTEDSTRING,       wxColour(0, 0, 0));
            StyleSetForeground(wxSTC_C_IDENTIFIER,             wxColour(0, 0, 0));
            StyleSetForeground(wxSTC_C_NUMBER,                 wxColour(0, 0, 150));
            StyleSetForeground(wxSTC_C_OPERATOR,               wxColour(0, 0, 0));
            StyleSetForeground(wxSTC_C_REGEX,                  wxColour(150, 0, 0));
            StyleSetForeground(wxSTC_C_STRINGEOL,              wxColour(150, 0, 0));
            StyleSetForeground(wxSTC_C_STRINGRAW,              wxColour(150, 0, 0));
            StyleSetForeground(wxSTC_C_TRIPLEVERBATIM,         wxColour(150, 0, 0));
            StyleSetForeground(wxSTC_C_UUID,                   wxColour(150, 0, 0));
            StyleSetForeground(wxSTC_C_VERBATIM,               wxColour(150, 0, 0));
            StyleSetForeground(wxSTC_C_WORD,                   wxColour(0, 0, 153));
            StyleSetForeground(wxSTC_C_WORD2,                  wxColour(102, 0, 102));
            StyleSetBold(wxSTC_C_WORD, true);
            StyleSetBold(wxSTC_C_WORD2, true);
            StyleSetBold(wxSTC_C_COMMENTDOCKEYWORD, true);
            StyleSetBold(wxSTC_C_IDENTIFIER, true);

            SetKeyWords(0, "var if return for while break continue");
            SetKeyWords(1, "true false");

            Connect(wxEVT_STC_MARGINCLICK, wxStyledTextEventHandler(MuseStyledTextEditor::onMarginClick), nullptr, this);
        }

        void MuseStyledTextEditor::onMarginClick(wxStyledTextEvent &event) {
            if(event.GetMargin() == MARGIN_FOLD) {
                int lineClick = LineFromPosition(event.GetPosition());
                int levelClick = GetFoldLevel(lineClick);

                if((levelClick & wxSTC_FOLDLEVELHEADERFLAG) > 0) {
                    ToggleFold(lineClick);
                }
            }
        }

        bool MuseStyledTextEditor::saveFile() {
            if(!IsModified()) return true;

            std::cout << "Saving file " << mFilePath << std::endl;

            return wxStyledTextCtrl::SaveFile(mFilePath);
        }

        bool MuseStyledTextEditor::saveAsFile(const wxString &fileName) {
            std::cout << "Saving file " << mFilePath << " as " << fileName << std::endl;

            mFilePath = fileName;

            return wxStyledTextCtrl::SaveFile(fileName);
        }

        bool MuseStyledTextEditor::loadFile(const wxString &fileName) {
            if(!fileName.empty()) mFilePath = fileName;

            wxStyledTextCtrl::LoadFile(fileName);

            EmptyUndoBuffer();

            return true;
        }

        wxString MuseStyledTextEditor::filePath() const {
            return mFilePath;
        }
    }
}