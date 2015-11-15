#ifndef DEMUSE_EXPRESSIONFACTORY_H
#define DEMUSE_EXPRESSIONFACTORY_H

#include <deque>
#include <map>
#include "SymbolFactory.h"
#include "symbol/Expression.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class ExpressionFactory : public SymbolFactory {
        public:
            enum class Associativity {
                LEFT,
                RIGHT
            };

            static Expression *produce(std::deque<lexer::Token> &tokens);
            static Expression *processExpression(std::deque<lexer::Token> &deque, int i);
            static Expression *producePrimary(std::deque<lexer::Token> &deque);

            static bool continueProcessingTokens(std::deque<lexer::Token> &tokens, int i);

            static const std::map<lexer::TokenType, int> mOperatorPrecedence;
            static const std::map<lexer::TokenType, Associativity> mOperatorAssociativity;

            static Expression *produceExpression(lexer::Token token, Symbol *pSymbol, Symbol *rhs);
        };
    }
}

#endif //DEMUSE_EXPRESSIONFACTORY_H
