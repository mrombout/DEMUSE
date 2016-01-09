#include "MuseLexer.h"
#include "matcher/StringMatcher.h"
#include "matcher/CharMatcher.h"
#include "matcher/PlayMatcher.h"
#include "matcher/NotePrimitiveMatcher.h"
#include "matcher/SingleCommentMatcher.h"
#include "matcher/MultiCommentMatcher.h"

namespace dem {
    namespace lexer {
        MuseLexer::MuseLexer() {
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::NOTE,          std::move(std::unique_ptr<Matcher>(new NotePrimitiveMatcher())), true))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::COMMA,         std::move(std::unique_ptr<Matcher>(new CharMatcher(',')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::PERIOD,        std::move(std::unique_ptr<Matcher>(new CharMatcher('.')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::PLUS,          std::move(std::unique_ptr<Matcher>(new CharMatcher('+')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::MINUS,         std::move(std::unique_ptr<Matcher>(new CharMatcher('-')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::TIMES,         std::move(std::unique_ptr<Matcher>(new CharMatcher('*')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::MOD,           std::move(std::unique_ptr<Matcher>(new CharMatcher('%')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::EXP,           std::move(std::unique_ptr<Matcher>(new CharMatcher('^')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::TNEQ,          std::move(std::unique_ptr<Matcher>(new StringMatcher("!==")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::NEQ,           std::move(std::unique_ptr<Matcher>(new StringMatcher("!=")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::NOT,           std::move(std::unique_ptr<Matcher>(new CharMatcher('!')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::START,         std::move(std::unique_ptr<Matcher>(new CharMatcher('{')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::END,           std::move(std::unique_ptr<Matcher>(new CharMatcher('}')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::OPEN,          std::move(std::unique_ptr<Matcher>(new CharMatcher('(')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::CLOSE,         std::move(std::unique_ptr<Matcher>(new CharMatcher(')')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::BRACKET_OPEN,  std::move(std::unique_ptr<Matcher>(new CharMatcher('[')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::BRACKET_CLOSE, std::move(std::unique_ptr<Matcher>(new CharMatcher(']')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::TERMINATOR,    std::move(std::unique_ptr<Matcher>(new CharMatcher(';')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::TEQ,           std::move(std::unique_ptr<Matcher>(new StringMatcher("===")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::EQ,            std::move(std::unique_ptr<Matcher>(new StringMatcher("==")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::ASSIGNMENT,    std::move(std::unique_ptr<Matcher>(new CharMatcher('=')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::SMEQ,          std::move(std::unique_ptr<Matcher>(new StringMatcher("<=")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::LREQ,          std::move(std::unique_ptr<Matcher>(new StringMatcher(">=")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::AND,           std::move(std::unique_ptr<Matcher>(new StringMatcher("&&")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::OR,            std::move(std::unique_ptr<Matcher>(new StringMatcher("||")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::THIS_T,        std::move(std::unique_ptr<Matcher>(new StringMatcher("this")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::FOR,           std::move(std::unique_ptr<Matcher>(new StringMatcher("for")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::IN_ARRAY,      std::move(std::unique_ptr<Matcher>(new StringMatcher("in")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::ELSE,          std::move(std::unique_ptr<Matcher>(new StringMatcher("else")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::NEW,           std::move(std::unique_ptr<Matcher>(new StringMatcher("new")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::IF,            std::move(std::unique_ptr<Matcher>(new StringMatcher("if")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::WHILE,         std::move(std::unique_ptr<Matcher>(new StringMatcher("while")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::CONTINUE,      std::move(std::unique_ptr<Matcher>(new StringMatcher("continue")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::BREAK,         std::move(std::unique_ptr<Matcher>(new StringMatcher("break")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::RETURN,        std::move(std::unique_ptr<Matcher>(new StringMatcher("return")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::TRACK,         std::move(std::unique_ptr<Matcher>(new StringMatcher("track")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::FUNCTION,      std::move(std::unique_ptr<Matcher>(new StringMatcher("function")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::VAR,           std::move(std::unique_ptr<Matcher>(new StringMatcher("var")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::BOOL,          std::move(std::unique_ptr<Matcher>(new StringMatcher("true")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::BOOL,          std::move(std::unique_ptr<Matcher>(new StringMatcher("false")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::LR,            std::move(std::unique_ptr<Matcher>(new CharMatcher('>')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::SINGLECOMMENT, std::move(std::unique_ptr<Matcher>(new SingleCommentMatcher())), true))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::MULTICOMMENT,  std::move(std::unique_ptr<Matcher>(new MultiCommentMatcher())), true))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::DIVIDE,        std::move(std::unique_ptr<Matcher>(new CharMatcher('/')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::PLAY_END,      std::move(std::unique_ptr<Matcher>(new PlayMatcher()))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::SM,            std::move(std::unique_ptr<Matcher>(new CharMatcher('<')))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::TEXT,          std::move(std::unique_ptr<Matcher>(new RegexMatcher("\\\"(?:[^\\\"\\\\]|\\\\.)*\\\"")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::NUMBER,        std::move(std::unique_ptr<Matcher>(new RegexMatcher("\\d+(?:\\.\\d+)?")))))));
            addDefinition(std::move(std::unique_ptr<TokenDefinition>(new TokenDefinition(TokenType::IDENTIFIER,    std::move(std::unique_ptr<Matcher>(new RegexMatcher("\\w+")))))));
        }
    }
}
