#ifndef DEMUSE_MUSESTYLEDTEXTEDITOR_H
#define DEMUSE_MUSESTYLEDTEXTEDITOR_H

#include <map>
#include <wx/stc/stc.h>
#include <wx/window.h>
#include "MuseLexer.h"

#define demSTC_DEMUSE_BOOL 1
#define demSTC_DEMUSE_TEXT 2
#define demSTC_DEMUSE_NUMBER 3
#define demSTC_DEMUSE_OPERATOR 4
#define demSTC_DEMUSE_CONDITION 5
#define demSTC_DEMUSE_UNARY 6
#define demSTC_DEMUSE_KEYWORD 7
#define demSTC_DEMUSE_TRACK 8
#define demSTC_DEMUSE_NOTE 9
#define demSTC_DEMUSE_ACCIDENTAL 10
#define demSTC_DEMUSE_OCTAVE 11
#define demSTC_DEMUSE_CHORD 11
#define demSTC_DEMUSE_DURATION 11
#define demSTC_DEMUSE_BLOCK 12
#define demSTC_DEMUSE_PARENTHESIS 13
#define demSTC_DEMUSE_BRACKET 14
#define demSTC_DEMUSE_PLAY 15
#define demSTC_DEMUSE_FUNCTION 16
#define demSTC_DEMUSE_VAR 17
#define demSTC_DEMUSE_TERMINATOR 18
#define demSTC_DEMUSE_IDENTIFIER 19

#define demSTC_INDIC_UNKNOWN 8
#define demSTC_INDIC_BRACE 9

namespace dem {
    namespace ide {
        enum {
            MARGIN_LINE_NUMBERS,
            MARGIN_FOLD
        };


        class MuseStyledTextEditor : public wxStyledTextCtrl {
        public:
            MuseStyledTextEditor(wxWindow *parent, lexer::MuseLexer *museLexer);
            ~MuseStyledTextEditor();

            bool loadFile(const wxString &fileName);
            bool saveFile();
            bool saveAsFile(const wxString &fileName);

            wxString filePath() const;

        private:
            void onMarginClick(wxStyledTextEvent &event);
            void onChange(wxStyledTextEvent &event);
            void onStyleNeeded(wxStyledTextEvent &event);
            void onUpdateUI(wxStyledTextEvent &event);
            void onCharAdded(wxStyledTextEvent &event);

            bool isBrace(int c);

            wxString mFilePath;
            lexer::MuseLexer *mLexer;

            static std::map<lexer::TokenType, int> mTokenTypeStyles;

            int mLastCaretPos;
        };
    }
}

#endif //DEMUSE_MUSESTYLEDTEXTEDITOR_H