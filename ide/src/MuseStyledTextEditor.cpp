#include <vector>
#include "preference/ColorsPanel.h"
#include "preference/EditorPanel.h"
#include "App.h"
#include "MuseStyledTextEditor.h"
#include "Token.h"

namespace dem {
    namespace ide {
        std::map<lexer::TokenType, int> MuseStyledTextEditor::mTokenTypeStyles = {
            { lexer::TokenType::BOOL,       demSTC_DEMUSE_BOOL },
            { lexer::TokenType::TEXT,       demSTC_DEMUSE_TEXT },
            { lexer::TokenType::NUMBER,     demSTC_DEMUSE_NUMBER },
            { lexer::TokenType::COMMA,      demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::PERIOD,     demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::PLUS,       demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::MINUS,      demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::TIMES,      demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::DIVIDE,     demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::MOD,        demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::EXP,        demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::EQ,         demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::TEQ,        demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::NEQ,        demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::TNEQ,       demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::SM,         demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::SMEQ,       demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::LR,         demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::LREQ,       demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::NOT,        demSTC_DEMUSE_UNARY },
            { lexer::TokenType::OR,         demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::AND,        demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::FOR,        demSTC_DEMUSE_KEYWORD },
            { lexer::TokenType::IN_ARRAY,   demSTC_DEMUSE_KEYWORD },
            { lexer::TokenType::ELSE,       demSTC_DEMUSE_KEYWORD },
            { lexer::TokenType::NEW,        demSTC_DEMUSE_KEYWORD },
            { lexer::TokenType::IF,         demSTC_DEMUSE_KEYWORD },
            { lexer::TokenType::WHILE,      demSTC_DEMUSE_KEYWORD },
            { lexer::TokenType::CONTINUE,   demSTC_DEMUSE_KEYWORD },
            { lexer::TokenType::BREAK,      demSTC_DEMUSE_KEYWORD },
            { lexer::TokenType::RETURN,     demSTC_DEMUSE_KEYWORD },
            { lexer::TokenType::TRACK,      demSTC_DEMUSE_TRACK },
            { lexer::TokenType::NOTE,       demSTC_DEMUSE_NOTE },
            { lexer::TokenType::ACCIDENTAL, demSTC_DEMUSE_ACCIDENTAL },
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
            { lexer::TokenType::SINGLECOMMENT, demSTC_DEMUSE_COMMENT },
            { lexer::TokenType::MULTICOMMENT,  demSTC_DEMUSE_COMMENT },
            { lexer::TokenType::START,         demSTC_DEMUSE_BLOCK },
            { lexer::TokenType::END,           demSTC_DEMUSE_BLOCK },
            { lexer::TokenType::OPEN,          demSTC_DEMUSE_PARENTHESIS },
            { lexer::TokenType::CLOSE,         demSTC_DEMUSE_PARENTHESIS },
            { lexer::TokenType::BRACKET_OPEN,  demSTC_DEMUSE_BRACKET },
            { lexer::TokenType::BRACKET_CLOSE, demSTC_DEMUSE_BRACKET },
            { lexer::TokenType::PLAY_START, demSTC_DEMUSE_PLAY },
            { lexer::TokenType::PLAY_END,   demSTC_DEMUSE_PLAY },
            { lexer::TokenType::FUNCTION,   demSTC_DEMUSE_FUNCTION },
            { lexer::TokenType::VAR,        demSTC_DEMUSE_VAR },
            { lexer::TokenType::TERMINATOR, demSTC_DEMUSE_TERMINATOR },
            { lexer::TokenType::ASSIGNMENT, demSTC_DEMUSE_OPERATOR },
            { lexer::TokenType::IDENTIFIER, demSTC_DEMUSE_IDENTIFIER },
            { lexer::TokenType::UNKNOWN,    0 },
        };

        MuseStyledTextEditor::MuseStyledTextEditor(wxWindow *parent, lexer::MuseLexer *museLexer) :
                wxStyledTextCtrl(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxNO_BORDER),
                mLexer(museLexer) {
            SetStyleBits(8);

            Connect(wxEVT_STC_MARGINCLICK, wxStyledTextEventHandler(MuseStyledTextEditor::onMarginClick), nullptr, this);
            Connect(wxEVT_STC_CHANGE, wxStyledTextEventHandler(MuseStyledTextEditor::onChange), nullptr, this);
            Connect(wxEVT_STC_STYLENEEDED, wxStyledTextEventHandler(MuseStyledTextEditor::onStyleNeeded), nullptr, this);
            Connect(wxEVT_STC_UPDATEUI, wxStyledTextEventHandler(MuseStyledTextEditor::onUpdateUI), nullptr, this);
            Connect(wxEVT_STC_CHARADDED, wxStyledTextEventHandler(MuseStyledTextEditor::onCharAdded), nullptr, this);

            initialize();
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
            //std::cout << "changed" << std::endl;
        }

        void MuseStyledTextEditor::onStyleNeeded(wxStyledTextEvent &event) {
            //std::cout << "style needed" << std::endl;

            // start pos at the beginning of the end styled line
            int startPos = PositionFromLine(LineFromPosition(GetEndStyled()));;

            // retrieve text
            std::string text{GetText().c_str()};
            auto textBegin = text.begin();
            std::advance(textBegin, startPos);
            auto textEnd = text.begin();
            std::advance(textEnd, event.GetPosition());

            //std::cout << "Styling: " << std::string(textBegin, textEnd) << std::endl;

            // tokenize
            std::vector<lexer::Token> tokens = mLexer->lex(textBegin, textEnd, false);

            // prepare styling and indicators
            SetIndicatorCurrent(demSTC_INDIC_UNKNOWN);
            IndicatorClearRange(0, GetTextLength());

            std::vector<lexer::Token> autocompleteTokens;
            for(lexer::Token &token : tokens) {
                int startIndex = startPos + token.startIndex();

                // unknown tokens are not styled, but displayed using an indicator
                if(token.type() == lexer::TokenType::UNKNOWN) {
                    IndicatorFillRange(startIndex, token.content().size());
                }

                // style token
                int style = mTokenTypeStyles[token.type()];
                int length = token.content().length() + 1;

                //std::cout << "Styling " << token.type() << "(" << style << ") from " << startIndex << " to " << startIndex + length << std::endl;

                StartStyling(startIndex, 0x1f);
                SetStyling(length, style);
            }
        }

        void MuseStyledTextEditor::onUpdateUI(wxStyledTextEvent &event) {
            int caretPos = GetCurrentPos();
            if(mLastCaretPos != caretPos) {
                mLastCaretPos = caretPos;
                int bracePos1 = -1;
                int bracePos2 = -1;

                if(caretPos > 0 && isBrace(GetCharAt(caretPos - 1)))
                    bracePos1 = (caretPos - 1);
                else if(isBrace(GetCharAt(caretPos)))
                    bracePos1 = caretPos;

                if(bracePos1 >= 0) {
                    bracePos2 = BraceMatch(bracePos1);
                    if(bracePos2 == wxSTC_INVALID_POSITION) {
                        BraceBadLight(bracePos1);
                        SetHighlightGuide(0);
                    } else {
                        BraceHighlight(bracePos1, bracePos2);
                        SetHighlightGuide(GetColumn(bracePos1));
                    }
                } else {
                    BraceHighlight(wxSTC_INVALID_POSITION, wxSTC_INVALID_POSITION);
                    SetHighlightGuide(0);
                }
            }
        }

        void MuseStyledTextEditor::onCharAdded(wxStyledTextEvent &event) {
            int curPos = GetCurrentPos();
            int c = GetCharAt(curPos - 1);

            if(c == '{'  || c == '[' || c == '(') {
                // auto-match brace
                AddText(opposite(c));
                SetAnchor(curPos);
                SetCurrentPos(curPos);
            } else if(c == '\r' || c == '\n') {
                // auto-indentation
                int curLine = GetCurrentLine();
                int curLineLength = GetLineLength(curLine);
                int prevIndentation = GetLineIndentation(curLine - 1);

                if(curLine > 0 && curLineLength <= 2 && prevIndentation != 0) {
                    SetLineIndentation(curLine, prevIndentation);
                    LineEndDisplay();
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

        bool MuseStyledTextEditor::isBrace(int c) {
            switch(c) {
                case '(':
                case ')':
                case '[':
                case ']':
                case '{':
                case '}':
                case '<':
                case '>':
                    return true;
            }

            return false;
        }

        const wxString MuseStyledTextEditor::opposite(int c) {
            int offset = 0;
            if(c == '{' || c == '[' || c == '<')
                offset = 2;
            else if(c == '(')
                offset = 1;
            return wxString::FromAscii(c + offset);
        }

        void MuseStyledTextEditor::initialize() {
            wxFileConfig &config = wxGetApp().config();

            // defaults
            SetViewWhiteSpace(config.ReadBool(KEY_EDITOR_SHOW_WHITESPACE, false) ? wxSTC_WS_VISIBLEALWAYS : wxSTC_WS_INVISIBLE);
            SetViewEOL(false);
            SetCaretLineVisible(config.ReadBool(KEY_EDITOR_HIGHLIGHT_CURRENT_LINE, false));
            SetCaretLineBackground(wxColour(255, 250, 227)); // Make caret line colour configurable
            // TODO: Show annotations for compiler errors
            SetIndent(config.ReadLong(KEY_EDITOR_TAB_WIDTH, 4));
            SetTabWidth(config.ReadLong(KEY_EDITOR_TAB_WIDTH, 4));
            SetUseTabs(config.ReadBool(KEY_EDITOR_USE_TABS, false));
            SetTabIndents(true);
            SetBackSpaceUnIndents(true);
            SetIndentationGuides(wxSTC_IV_LOOKBOTH);
            SetEdgeMode(config.ReadBool(KEY_EDITOR_SHOW_MAX_COLUMN_LINE, true) ? wxSTC_EDGE_LINE : wxSTC_EDGE_NONE);
            SetEdgeColumn(config.ReadLong(KEY_EDITOR_MAX_COLUMN, 120));
            // TODO: Check if edge column is at correct column (is seems off)
            SetWrapMode(config.ReadBool(KEY_EDITOR_WRAP, false) ? wxSTC_WRAP_WORD : wxSTC_WRAP_NONE);
            // TODO: Autocompletion (read from AST)
            // TODO: Implement find functionality
            // TODO: Show error marker on tokenization errors, compilation errors and vm errors
            // TODO: Support zooming in/out

            // TODO: Call-tips
            // TODO: Folding (update lexer with levels for this)

            // fonts
            // TODO: Make configurable
            StyleClearAll();

            wxFont font(wxFontInfo(10).Family(wxFONTFAMILY_MODERN));
            StyleSetFont(wxSTC_STYLE_DEFAULT, font);
            StyleSetForeground(wxSTC_STYLE_INDENTGUIDE, wxColour(wxT("DARK GREY")));

            // line margin
            SetMarginWidth(MARGIN_LINE_NUMBERS, 30);
            SetMarginType(MARGIN_LINE_NUMBERS, wxSTC_MARGIN_NUMBER);
            StyleSetForeground(wxSTC_STYLE_LINENUMBER, wxColour(128, 0, 0));
            StyleSetBackground(wxSTC_STYLE_LINENUMBER, wxColour(240, 240, 240));

            // TODO: Folding

            // syntax highlighting
            SetLexer(wxSTC_LEX_CONTAINER);
            StyleSetForeground(demSTC_DEMUSE_UNKNOWN,     wxColour(255, 0, 0));
            StyleSetBackground(demSTC_DEMUSE_UNKNOWN,     wxColour(128, 0, 0));

            for(auto it = ColorsPanel::DEFAULTS.cbegin(); it != ColorsPanel::DEFAULTS.cend(); ++it) {
                wxString key = "colors/" + it->first.Lower();

                // background color
                wxColour backgroundColor;
                if(config.Exists(key + "/background"))
                    backgroundColor.Set(config.Read(key + "/background"));
                else
                    backgroundColor = it->second.background;

                StyleSetBackground(it->second.styleType, backgroundColor);

                // foreground color
                wxColour foregroundColor;
                if(config.Exists(key + "/foreground"))
                    foregroundColor.Set(config.Read(key + "/foreground"));
                else
                    foregroundColor = it->second.foreground;

                StyleSetForeground(it->second.styleType, foregroundColor);

                // font effects
                StyleSetBold(it->second.styleType, config.ReadBool("colors/" + it->first.Lower() + "/bold", it->second.bold));
                StyleSetItalic(it->second.styleType, config.ReadBool("colors/" + it->first.Lower() + "/italic", it->second.italic));
                StyleSetUnderline(it->second.styleType, config.ReadBool("colors/" + it->first.Lower() + "/underline", it->second.underline));
            }

            // indicators
            IndicatorSetStyle(demSTC_INDIC_UNKNOWN, wxSTC_INDIC_SQUIGGLE);
            IndicatorSetForeground(demSTC_INDIC_UNKNOWN, wxColour(255, 0, 0));
            IndicatorSetUnder(demSTC_INDIC_UNKNOWN, false);
            IndicatorSetOutlineAlpha(demSTC_INDIC_UNKNOWN, 50);
            IndicatorSetAlpha(demSTC_INDIC_UNKNOWN, 30);

            // brace style
            StyleSetBackground(wxSTC_STYLE_BRACELIGHT, wxColour(153, 204, 255));
            StyleSetForeground(wxSTC_STYLE_BRACELIGHT, wxColour(0, 0, 0));
            StyleSetForeground(wxSTC_STYLE_BRACEBAD,   wxColour(100, 0, 0));

            // markers
            MarkerDefine(demSTC_MARK_ERROR, wxSTC_MARK_LEFTRECT, wxNullColour, *wxRED);
        }
    }
}