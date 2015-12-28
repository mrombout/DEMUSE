#include "MusicStringLexer.h"
#include "matcher/StringMatcher.h"
#include "matcher/NoteMatcher.h"
#include "matcher/AccidentalMatcher.h"
#include "matcher/OctaveMatcher.h"
#include "matcher/DurationMatcher.h"

namespace dem {
    namespace lexer {
        MusicStringLexer::MusicStringLexer() :
            Lexer(new StringMatcher(">>")) {
            addDefinition(new TokenDefinition(TokenType::NOTE,          new NoteMatcher()));
            addDefinition(new TokenDefinition(TokenType::NUMBER,        new RegexMatcher("\\d+(?:\\.\\d+)?")));
            addDefinition(new TokenDefinition(TokenType::ACCIDENTAL,    new AccidentalMatcher()));
            addDefinition(new TokenDefinition(TokenType::CHORD,         new RegexMatcher("maj|min")));
            addDefinition(new TokenDefinition(TokenType::DURATION,      new DurationMatcher()));
            addDefinition(new TokenDefinition(TokenType::PRESSURE,      new RegexMatcher("\\+(?=\\d)")));
            addDefinition(new TokenDefinition(TokenType::POLY_PRESSURE, new RegexMatcher("\\*(?=\\d+,\\d+)")));
            addDefinition(new TokenDefinition(TokenType::TUPLET,        new CharMatcher('*')));
            addDefinition(new TokenDefinition(TokenType::TIE,           new CharMatcher('-')));
            addDefinition(new TokenDefinition(TokenType::ATTACK,        new RegexMatcher("a\\d*")));
            addDefinition(new TokenDefinition(TokenType::DECAY,         new RegexMatcher("d\\d*")));
            addDefinition(new TokenDefinition(TokenType::HARMONY,       new CharMatcher('+')));
            addDefinition(new TokenDefinition(TokenType::COMBINE,       new CharMatcher('_')));
            addDefinition(new TokenDefinition(TokenType::MEASURE,       new CharMatcher('|'), true));
            addDefinition(new TokenDefinition(TokenType::KEY,           new CharMatcher('K')));
            addDefinition(new TokenDefinition(TokenType::INSTRUMENT,    new CharMatcher('I')));
            addDefinition(new TokenDefinition(TokenType::VOICE,         new CharMatcher('V')));
            addDefinition(new TokenDefinition(TokenType::LAYER,         new CharMatcher('L')));
            addDefinition(new TokenDefinition(TokenType::TEMPO,         new CharMatcher('T')));
            addDefinition(new TokenDefinition(TokenType::PITCH,         new RegexMatcher("&(?=\\d)")));
            addDefinition(new TokenDefinition(TokenType::CONTROLLER,    new CharMatcher('X')));
            addDefinition(new TokenDefinition(TokenType::TIME,          new CharMatcher('@')));
            addDefinition(new TokenDefinition(TokenType::BRACKET_OPEN,  new CharMatcher('[')));
            addDefinition(new TokenDefinition(TokenType::BRACKET_CLOSE, new CharMatcher(']')));
            addDefinition(new TokenDefinition(TokenType::IDENTIFIER,    new RegexMatcher("\\w+")));

            // TODO: Percussion track syntax, V9 [Hi_Bongo]q
            // TODO: Allow not specifying attack/decay value for ATTACK and DECAY? (default to 0)
            // TODO: Manual notes [<frequency>]
            // TODO: Support more chords
            // TODO: Tuplet numbers
        }
    }
}