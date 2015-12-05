#include "matcher/NotePrimitiveMatcher.h"

namespace dem {
    namespace lexer {
        NotePrimitiveMatcher::NotePrimitiveMatcher() :
            mNotePrimitiveMatcher(">") {

        }

        std::string NotePrimitiveMatcher::match(std::string::iterator &begin, std::string::iterator &end, std::vector<Token> &tokens) const {
            int advanced = 0;

            // match start
            std::string notePrimitiveStart = mNotePrimitiveMatcher.match(begin, end, tokens);
            if(notePrimitiveStart.empty()) {
                return "";
            }
            std::advance(begin, 1);

            // match note
            std::string noteToken = mNoteMatcher.match(begin, end, tokens);
            if(!noteToken.empty()) {
                advanced += noteToken.length();
                std::advance(begin, noteToken.length());
                tokens.push_back(Token(TokenType::NOTE, noteToken, 0, 0, 0));
            }

            // match octave
            std::string octaveToken = mOctaveMatcher.match(begin, end, tokens);
            if(!octaveToken.empty()) {
                std::advance(begin, octaveToken.length());
                advanced += octaveToken.length();
                tokens.push_back(Token(TokenType::OCTAVE, octaveToken, 0, 0, 0));
            }

            // match accidental
            std::string accidentalToken = mAccidentalMatcher.match(begin, end, tokens);
            if(!accidentalToken.empty()) {
                std::advance(begin, accidentalToken.length());
                advanced += accidentalToken.length();
                tokens.push_back(Token(TokenType::ACCIDENTAL, accidentalToken, 0, 0, 0));
            }

            // match duration
            std::string durationToken = mDurationMatcher.match(begin, end, tokens);
            if(!durationToken.empty()) {
                std::advance(begin, durationToken.length());
                advanced += durationToken.length();
                tokens.push_back(Token(TokenType::DURATION, durationToken, 0, 0, 0));
            }

            // expect a terminator

            return "";
        }
    }
}
