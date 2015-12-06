#include "matcher/NotePrimitiveMatcher.h"

namespace dem {
    namespace lexer {
        NotePrimitiveMatcher::NotePrimitiveMatcher() :
            mNotePrimitiveMatcher(">") {

        }

        std::string NotePrimitiveMatcher::match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens, TokenPosition &tokenPosition) const {
            int advanced = 0;

            // match start
            std::string notePrimitiveStart = mNotePrimitiveMatcher.match(begin, end, tokens, tokenPosition);
            if(notePrimitiveStart.empty()) {
                return "";
            }
            std::advance(begin, 1);
            tokenPosition.column += notePrimitiveStart.length();
            tokenPosition.index += notePrimitiveStart.length();

            // match note
            std::string noteToken = mNoteMatcher.match(begin, end, tokens, tokenPosition);
            if(!noteToken.empty()) {
                advanced += noteToken.length();
                std::advance(begin, noteToken.length());
                tokens.push_back(Token(TokenType::NOTE, noteToken, tokenPosition));
                tokenPosition.column += noteToken.length();
                tokenPosition.index += noteToken.length();
            }

            // match octave
            std::string octaveToken = mOctaveMatcher.match(begin, end, tokens, tokenPosition);
            if(!octaveToken.empty()) {
                std::advance(begin, octaveToken.length());
                advanced += octaveToken.length();
                tokens.push_back(Token(TokenType::OCTAVE, octaveToken, tokenPosition));
                tokenPosition.column += octaveToken.length();
            }

            // match accidental
            std::string accidentalToken = mAccidentalMatcher.match(begin, end, tokens, tokenPosition);
            if(!accidentalToken.empty()) {
                std::advance(begin, accidentalToken.length());
                advanced += accidentalToken.length();
                tokens.push_back(Token(TokenType::ACCIDENTAL, accidentalToken, tokenPosition));
                tokenPosition.column += accidentalToken.length();
            }

            // match duration
            std::string durationToken = mDurationMatcher.match(begin, end, tokens, tokenPosition);
            if(!durationToken.empty()) {
                std::advance(begin, durationToken.length());
                advanced += durationToken.length();
                tokens.push_back(Token(TokenType::DURATION, durationToken, tokenPosition));
                tokenPosition.column += durationToken.length();
            }

            return "";
        }
    }
}
