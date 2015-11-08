#ifndef DEMUSE_TOKENIZER_H
#define DEMUSE_TOKENIZER_H

#include <string>
#include <vector>
#include "matcher/RegexMatcher.h"
#include "Token.h"
#include "TokenDefinition.h"

namespace dem {
    namespace lexer {
        class Lexer {
        public:
            Lexer();
            ~Lexer();

            void addDefinition(TokenDefinition *tokenDefinition);

            std::vector<Token> lex(std::string::iterator begin, std::string::iterator end);

        private:
            void match(std::vector<Token> &tokens, std::string::iterator &begin, std::string::iterator &end, int &curLine, int &curColumn, int &curIndex);

        private:
            std::vector<TokenDefinition*> mTokenDefinitions;
            RegexMatcher mNewLineMatcher;
            RegexMatcher mSkipWhitespaceMatcher;
        };
    }
}

#endif //DEMUSE_TOKENIZER_H
