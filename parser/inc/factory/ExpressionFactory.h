#ifndef DEMUSE_EXPRESSIONFACTORY_H
#define DEMUSE_EXPRESSIONFACTORY_H

#include <deque>
#include <map>
#include <vector>
#include <functional>
#include <symbol/expression/ArrayLiteral.h>
#include "SymbolFactory.h"
#include "Token.h"
#include "symbol/expression/Expression.h"
#include "symbol/expression/NumberLiteral.h"

namespace dem {
    namespace parser {
        class Expression;
    }
}

namespace dem {
    namespace parser {
        struct ExprInfo {
            explicit ExprInfo(Expression *expression) :
                expression(expression),
                tokenType(lexer::TokenType::UNKNOWN){

            }

            explicit ExprInfo(lexer::TokenType tokenType) :
                expression(nullptr),
                tokenType(tokenType) {

            }

            Expression *expression;
            lexer::TokenType tokenType;
        };

        class ExpressionFactory : public SymbolFactory {
        public:
            static Expression *produce(std::deque<lexer::Token> &tokens);

            static Expression *gobbleExpression(std::deque<lexer::Token> &deque);
            static Expression *gobbleBinaryExpression(std::deque<lexer::Token> &deque);
            static Expression *gobbleToken(std::deque<lexer::Token> &deque);
            static lexer::TokenType gobbleBinaryOp(std::deque<lexer::Token> &deque);
            static NumberLiteral *gobbleNumericLiteral(std::deque<lexer::Token> &deque);
            static Expression *gobbleStringLiteral(std::deque<lexer::Token> &deque);
            static Expression *gobbleVariable(std::deque<lexer::Token> &deque);
            static Expression * gobbleGroup(std::deque<lexer::Token> &deque);
            static Expression * gobbleIdentifier(std::deque<lexer::Token> &deque);
            static std::vector<Expression*> gobbleArguments(std::deque<lexer::Token> &deque, lexer::TokenType termination);
            static ArrayLiteral * gobbleArray(std::deque<lexer::Token> &deque);

            static unsigned int binaryPrecedence(lexer::TokenType tokenType);
            static Expression * createBinaryExpression(lexer::TokenType op, Expression *left, Expression *right);

            static bool isUnaryOperator(lexer::Token &token);
            static Expression *gobbleBoolLiteral(std::deque<lexer::Token> &deque);

        private:
            static const std::map<lexer::TokenType, unsigned int> BINARY_OPS;
        };
    }
}

#endif //DEMUSE_EXPRESSIONFACTORY_H
