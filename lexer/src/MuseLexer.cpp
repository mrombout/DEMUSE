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
            addDefinition(new TokenDefinition(TokenType::NOTE,          new NotePrimitiveMatcher(), true));
            addDefinition(new TokenDefinition(TokenType::COMMA,         new CharMatcher(',')));
            addDefinition(new TokenDefinition(TokenType::PERIOD,        new CharMatcher('.')));
            addDefinition(new TokenDefinition(TokenType::PLUS,          new CharMatcher('+')));
            addDefinition(new TokenDefinition(TokenType::MINUS,         new CharMatcher('-')));
            addDefinition(new TokenDefinition(TokenType::TIMES,         new CharMatcher('*')));
            addDefinition(new TokenDefinition(TokenType::MOD,           new CharMatcher('%')));
            addDefinition(new TokenDefinition(TokenType::EXP,           new CharMatcher('^')));
            addDefinition(new TokenDefinition(TokenType::TNEQ,          new StringMatcher("!==")));
            addDefinition(new TokenDefinition(TokenType::NEQ,           new StringMatcher("!=")));
            addDefinition(new TokenDefinition(TokenType::NOT,           new CharMatcher('!')));
            addDefinition(new TokenDefinition(TokenType::START,         new CharMatcher('{')));
            addDefinition(new TokenDefinition(TokenType::END,           new CharMatcher('}')));
            addDefinition(new TokenDefinition(TokenType::OPEN,          new CharMatcher('(')));
            addDefinition(new TokenDefinition(TokenType::CLOSE,         new CharMatcher(')')));
            addDefinition(new TokenDefinition(TokenType::BRACKET_OPEN,  new CharMatcher('[')));
            addDefinition(new TokenDefinition(TokenType::BRACKET_CLOSE, new CharMatcher(']')));
            addDefinition(new TokenDefinition(TokenType::TERMINATOR,    new CharMatcher(';')));
            addDefinition(new TokenDefinition(TokenType::TEQ,           new StringMatcher("===")));
            addDefinition(new TokenDefinition(TokenType::EQ,            new StringMatcher("==")));
            addDefinition(new TokenDefinition(TokenType::ASSIGNMENT,    new CharMatcher('=')));
            addDefinition(new TokenDefinition(TokenType::SMEQ,          new StringMatcher("<=")));
            addDefinition(new TokenDefinition(TokenType::LREQ,          new StringMatcher(">=")));
            addDefinition(new TokenDefinition(TokenType::AND,           new StringMatcher("&&")));
            addDefinition(new TokenDefinition(TokenType::OR,            new StringMatcher("||")));
            addDefinition(new TokenDefinition(TokenType::THIS,          new StringMatcher("this")));
            addDefinition(new TokenDefinition(TokenType::FOR,           new StringMatcher("for")));
            addDefinition(new TokenDefinition(TokenType::IN_ARRAY,      new StringMatcher("in")));
            addDefinition(new TokenDefinition(TokenType::ELSE,          new StringMatcher("else")));
            addDefinition(new TokenDefinition(TokenType::NEW,           new StringMatcher("new")));
            addDefinition(new TokenDefinition(TokenType::IF,            new StringMatcher("if")));
            addDefinition(new TokenDefinition(TokenType::WHILE,         new StringMatcher("while")));
            addDefinition(new TokenDefinition(TokenType::CONTINUE,      new StringMatcher("continue")));
            addDefinition(new TokenDefinition(TokenType::BREAK,         new StringMatcher("break")));
            addDefinition(new TokenDefinition(TokenType::RETURN,        new StringMatcher("return")));
            addDefinition(new TokenDefinition(TokenType::TRACK,         new StringMatcher("track")));
            addDefinition(new TokenDefinition(TokenType::FUNCTION,      new StringMatcher("function")));
            addDefinition(new TokenDefinition(TokenType::VAR,           new StringMatcher("var")));
            addDefinition(new TokenDefinition(TokenType::BOOL,          new StringMatcher("true")));
            addDefinition(new TokenDefinition(TokenType::BOOL,          new StringMatcher("false")));
            addDefinition(new TokenDefinition(TokenType::LR,            new CharMatcher('>')));
            addDefinition(new TokenDefinition(TokenType::SINGLECOMMENT, new SingleCommentMatcher(), true));
            addDefinition(new TokenDefinition(TokenType::MULTICOMMENT,  new MultiCommentMatcher(),  true));
            addDefinition(new TokenDefinition(TokenType::DIVIDE,        new CharMatcher('/')));
            addDefinition(new TokenDefinition(TokenType::PLAY_END,      new PlayMatcher()));
            addDefinition(new TokenDefinition(TokenType::SM,            new CharMatcher('<')));
            addDefinition(new TokenDefinition(TokenType::TEXT,          new RegexMatcher("\\\"(?:[^\\\"\\\\]|\\\\.)*\\\"")));
            addDefinition(new TokenDefinition(TokenType::NUMBER,        new RegexMatcher("\\d+(?:\\.\\d+)?")));
            addDefinition(new TokenDefinition(TokenType::IDENTIFIER,    new RegexMatcher("\\w+")));
        }
    }
}
