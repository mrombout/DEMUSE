#include "MusicStringLexer.h"
#include "matcher/StringMatcher.h"
#include "matcher/NoteMatcher.h"
#include "matcher/AccidentalMatcher.h"
#include "matcher/OctaveMatcher.h"
#include "matcher/DurationMatcher.h"

namespace dem {
    namespace lexer {
        MusicStringLexer::MusicStringLexer() :
            Lexer(std::move(std::unique_ptr<Matcher>(new StringMatcher(">>")))) {
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::NOTE,          std::move(std::unique_ptr<Matcher>(new NoteMatcher()))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::NUMBER,        std::move(std::unique_ptr<Matcher>(new RegexMatcher("\\d+(?:\\.\\d+)?")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::ACCIDENTAL,    std::move(std::unique_ptr<Matcher>(new AccidentalMatcher()))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::CHORD,         std::move(std::unique_ptr<Matcher>(new RegexMatcher("maj|min")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::DURATION,      std::move(std::unique_ptr<Matcher>(new DurationMatcher()))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::PRESSURE,      std::move(std::unique_ptr<Matcher>(new RegexMatcher("\\+(?=\\d)")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::POLY_PRESSURE, std::move(std::unique_ptr<Matcher>(new RegexMatcher("\\*(?=\\d+,\\d+)")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::TUPLET,        std::move(std::unique_ptr<Matcher>(new CharMatcher('*')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::TIE,           std::move(std::unique_ptr<Matcher>(new CharMatcher('-')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::ATTACK,        std::move(std::unique_ptr<Matcher>(new RegexMatcher("a\\d*")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::DECAY,         std::move(std::unique_ptr<Matcher>(new RegexMatcher("d\\d*")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::HARMONY,       std::move(std::unique_ptr<Matcher>(new CharMatcher('+')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::COMBINE,       std::move(std::unique_ptr<Matcher>(new CharMatcher('_')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::MEASURE,       std::move(std::unique_ptr<Matcher>(new CharMatcher('|'))), true))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::KEY,           std::move(std::unique_ptr<Matcher>(new CharMatcher('K')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::INSTRUMENT,    std::move(std::unique_ptr<Matcher>(new CharMatcher('I')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::VOICE,         std::move(std::unique_ptr<Matcher>(new CharMatcher('V')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::LAYER,         std::move(std::unique_ptr<Matcher>(new CharMatcher('L')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::TEMPO,         std::move(std::unique_ptr<Matcher>(new CharMatcher('T')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::PITCH,         std::move(std::unique_ptr<Matcher>(new RegexMatcher("&(?=\\d)")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::CONTROLLER,    std::move(std::unique_ptr<Matcher>(new CharMatcher('X')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::TIME,          std::move(std::unique_ptr<Matcher>(new CharMatcher('@')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::BRACKET_OPEN,  std::move(std::unique_ptr<Matcher>(new CharMatcher('[')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::BRACKET_CLOSE, std::move(std::unique_ptr<Matcher>(new CharMatcher(']')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::IDENTIFIER,    std::move(std::unique_ptr<Matcher>(new RegexMatcher("\\w+")))))));

            // TODO: Percussion track syntax, V9 [Hi_Bongo]q
            // TODO: Allow not specifying attack/decay value for ATTACK and DECAY? (default to 0)
            // TODO: Manual notes [<frequency>]
            // TODO: Support more chords
            // TODO: Tuplet numbers
        }
    }
}