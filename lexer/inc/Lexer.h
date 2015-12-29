#ifndef DEMUSE_TOKENIZER_H
#define DEMUSE_TOKENIZER_H

#include <string>
#include <vector>
#include "matcher/NewLineMatcher.h"
#include "matcher/RegexMatcher.h"
#include "Token.h"
#include "TokenDefinition.h"
#include "TokenPosition.h"

namespace dem {
    namespace lexer {
        class Lexer {
        public:
            Lexer();
            Lexer(Matcher *stopMatcher);
            ~Lexer();

            void addDefinition(TokenDefinition *tokenDefinition);

            std::vector<Token> lex(std::string::iterator &begin, std::string::iterator &end, bool ignore = true) const;
            std::vector<Token> lex(std::string::iterator &begin, std::string::iterator &end, bool ignore, TokenPosition &tokenPosition) const;

        private:
            bool match(std::vector<Token> &tokens, std::string::iterator &begin, std::string::iterator &end, bool ignore, TokenPosition &tokenPosition) const;

        private:
            std::vector<TokenDefinition*> mTokenDefinitions;

            Matcher *mStopMatcher;
            NewLineMatcher mNewLineMatcher;
            RegexMatcher mSkipMatcher;
        };
    }
}

#endif //DEMUSE_TOKENIZER_H
