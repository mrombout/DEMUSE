#include <vector>
#include "MuseStyledTextEditor.h"
#include "Token.h"

namespace dem {
    namespace ide {
        std::map<lexer::TokenType, int> MuseStyledTextEditor::mTokenTypeStyles = {
            { lexer::TokenType::BOOL,     demSTC_DEMUSE_BOOL },
            { lexer::TokenType::TEXT,     demSTC_DEMUSE_TEXT },
            { lexer::TokenType::NUMBER,   demSTC_DEMUSE_NUMBER },
            { lexer::TokenType::COMMA,    demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::PERIOD,   demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::POSITIVE, demSTC_DEMUSE_UNARY },
            { lexer::TokenType::NEGATIVE, demSTC_DEMUSE_UNARY },
            { lexer::TokenType::PLUS,     demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::MINUS,    demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::TIMES,    demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::DIVIDE,   demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::MOD,      demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::EXP,      demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::EQ,       demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::TEQ,      demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::NEQ,      demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::TNEQ,     demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::SM,       demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::SMEQ,     demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::LR,       demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::LREQ,     demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::NOT,      demSTC_DEMUSE_UNARY },
            { lexer::TokenType::OR,       demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::AND,      demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::FOR,      demSTC_DEMUSE_STATEMENT },
            { lexer::TokenType::IN_ARRAY, demSTC_DEMUSE_STATEMENT },
            { lexer::TokenType::ELSE,     demSTC_DEMUSE_STATEMENT },
            { lexer::TokenType::NEW,      demSTC_DEMUSE_STATEMENT },
            { lexer::TokenType::IF,       demSTC_DEMUSE_STATEMENT },
            { lexer::TokenType::WHILE,    demSTC_DEMUSE_STATEMENT },
            { lexer::TokenType::CONTINUE, demSTC_DEMUSE_STATEMENT },
            { lexer::TokenType::BREAK,    demSTC_DEMUSE_STATEMENT },
            { lexer::TokenType::RETURN,   demSTC_DEMUSE_STATEMENT },
            { lexer::TokenType::TRACK,    demSTC_DEMUSE_TRACK },
            { lexer::TokenType::NOTE,     demSTC_DEMUSE_NOTE },
            { lexer::TokenType::ACCIDENTAL, demSTC_DEMUSE_ACCIDENTAL },
            { lexer::TokenType::OCTAVE,     demSTC_DEMUSE_OCTAVE },
            { lexer::TokenType::CHORD,      demSTC_DEMUSE_CHORD },
            { lexer::TokenType::DURATION,   0 },
            { lexer::TokenType::HARMONY,    0 },
            { lexer::TokenType::MEASURE,    0 },
            { lexer::TokenType::TUPLET,     0 },
            { lexer::TokenType::TIE,        0 },
            { lexer::TokenType::ATTACK,     0 },
            { lexer::TokenType::DECAY,      0 },
            { lexer::TokenType::COMBINE,    0 },
            { lexer::TokenType::KEY,        0 },
            { lexer::TokenType::INSTRUMENT, 0 },
            { lexer::TokenType::VOICE,      0 },
            { lexer::TokenType::LAYER,      0 },
            { lexer::TokenType::TEMPO,      0 },
            { lexer::TokenType::PITCH,      0 },
            { lexer::TokenType::PRESSURE,   0 },
            { lexer::TokenType::POLY_PRESSURE, 0 },
            { lexer::TokenType::CONTROLLER,    0 },
            { lexer::TokenType::TIME,          0 },
            { lexer::TokenType::START,         0 },
            { lexer::TokenType::END,           0 },
            { lexer::TokenType::OPEN,          0 },
            { lexer::TokenType::CLOSE,         0 },
            { lexer::TokenType::BRACKET_OPEN,  0 },
            { lexer::TokenType::BRACKET_CLOSE, 0 },
            { lexer::TokenType::PLAY_START, demSTC_DEMUSE_PLAY },
            { lexer::TokenType::PLAY_END,   demSTC_DEMUSE_PLAY },
            { lexer::TokenType::FUNCTION,   demSTC_DEMUSE_STATEMENT },
            { lexer::TokenType::VAR,        demSTC_DEMUSE_STATEMENT },
            { lexer::TokenType::TERMINATOR, demSTC_DEMUSE_TERMINATOR },
            { lexer::TokenType::ASSIGNMENT, demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::IDENTIFIER, demSTC_DEMUSE_IDENTIFIER },
            { lexer::TokenType::UNKNOWN,    0 },
        };

        MuseStyledTextEditor::MuseStyledTextEditor(wxWindow *parent, lexer::MuseLexer *museLexer) :
                wxStyledTextCtrl(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER),
                mLexer(museLexer) {
            SetStyleBits(8);

            // defaults
            //SetViewEOL(false);
            //SetIndentationGuides(true);
            //SetEdgeMode(wxSTC_EDGE_LINE);
            //SetViewWhiteSpace(false);
            //SetOvertype(false);
            //SetReadOnly(false);
            //SetWrapMode(wxSTC_WRAP_NONE);

            //SetTabWidth(4);
            //SetUseTabs(false);
            //SetTabIndents(true);
            //SetBackSpaceUnIndents(true);

            //wxFont font(wxFontInfo(10).Family(wxFONTFAMILY_MODERN));
            //StyleSetFont(wxSTC_STYLE_DEFAULT, font);
            //StyleSetForeground(wxSTC_STYLE_DEFAULT, *wxBLACK);
            //StyleSetBackground(wxSTC_STYLE_DEFAULT, *wxWHITE);
            //StyleSetForeground(wxSTC_STYLE_INDENTGUIDE, wxColour(wxT("DARK GREY")));

            // line margin
            //SetMarginWidth(MARGIN_LINE_NUMBERS, 50);
            // TODO: Set text color to darkred
            //SetMarginType(MARGIN_LINE_NUMBERS, wxSTC_MARGIN_NUMBER);

            // TODO: Folding
            // TODO: Brace match
            // TODO: Autoindent

            // syntax highlighting
            StyleClearAll();
            SetLexer(wxSTC_LEX_CONTAINER);
            StyleSetForeground(0, wxColour(255, 255, 0));
            StyleSetBackground(0, wxColour(255, 0, 0));
            StyleSetForeground(demSTC_DEMUSE_BOOL, wxColour(0, 255, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::TEXT), wxColour(0, 0, 255));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::NUMBER), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::COMMA), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::PERIOD), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::POSITIVE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::NEGATIVE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::PLUS), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::MINUS), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::TIMES), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::DIVIDE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::MOD), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::EXP), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::EQ), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::TEQ), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::NEQ), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::TNEQ), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::SM), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::SMEQ), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::LR), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::LREQ), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::NOT), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::OR), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::AND), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::FOR), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::IN_ARRAY), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::ELSE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::NEW), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::IF), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::WHILE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::CONTINUE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::BREAK), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::RETURN), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::TRACK), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::NOTE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::ACCIDENTAL), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::OCTAVE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::CHORD), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::DURATION), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::HARMONY), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::MEASURE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::TUPLET), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::TIE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::ATTACK), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::DECAY), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::COMBINE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::KEY), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::INSTRUMENT), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::VOICE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::LAYER), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::TEMPO), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::PITCH), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::PRESSURE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::POLY_PRESSURE), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::CONTROLLER), wxColour(255, 0, 0));
//            StyleSetForeground(static_cast<int>(lexer::TokenType::TIME), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::START), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::END), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::OPEN), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::CLOSE), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::BRACKET_OPEN), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::BRACKET_CLOSE), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::PLAY_START), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::PLAY_END), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::FUNCTION), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::VAR), wxColour(0, 255, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::TERMINATOR), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::ASSIGNMENT), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::IDENTIFIER), wxColour(255, 0, 0));
            //StyleSetForeground(static_cast<int>(lexer::TokenType::UNKNOWN), wxColour(255, 0, 0));

            //Connect(wxEVT_STC_MARGINCLICK, wxStyledTextEventHandler(MuseStyledTextEditor::onMarginClick), nullptr, this);
            //Connect(wxEVT_STC_CHANGE, wxStyledTextEventHandler(MuseStyledTextEditor::onChange), nullptr, this);
            Connect(wxEVT_STC_STYLENEEDED, wxStyledTextEventHandler(MuseStyledTextEditor::onStyleNeeded), nullptr, this);
        }

        MuseStyledTextEditor::~MuseStyledTextEditor() {
            delete mLexer;
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

        void MuseStyledTextEditor::onChange(wxStyledTextEvent &event) {
            std::cout << "changed" << std::endl;
        }

        void MuseStyledTextEditor::onStyleNeeded(wxStyledTextEvent &event) {
            std::cout << "style needed" << std::endl;

            std::string text{GetText().c_str()};
            auto textBegin = text.begin();
            auto textEnd = text.end();

            std::vector<lexer::Token> tokens = mLexer->lex(textBegin, textEnd);

            int startPos = GetEndStyled();

            std::cout << "Start styling at " << startPos << std::endl;
            for(lexer::Token &token : tokens) {
                int style = mTokenTypeStyles[token.type()];
                int length = token.content().length();
                std::cout << "Styling " << token.type() << "(" << style << ") from " << GetEndStyled() << " to " << length << std::endl;
                StartStyling(token.startIndex(), 0x3f);
                SetStyling(length, style);
            }

            int style = GetStyleAt(3);
            std::cout << "Style at 3 is " << style << std::endl;
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