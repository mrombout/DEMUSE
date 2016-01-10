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

        enum class Associativity {
            LEFT,
            RIGHT
        };

        struct OperatorInfo {
            const unsigned int precedence;
            Associativity associativity;
        };

        /**
         * \brief Produces an expression
         *
         * Produces an expression for as long as it will find valid tokens for an expression. The produced Expression
         * will be a tree of Expression symbols and its subclasses in the correct order of precedence for each
         * operator.
         *
         * For example, an expression such as "1 + 2 * 3" would result in the following tree where each operator
         * represents an Expression subclass:
         *
         * ```
         *      +
         *     1 *
         *      2 3
         * ```
         *
         * When the order of precedence is overruled by the use of parenthesis to create the expression "(1 + 2) * 3)",
         * this would results in the following expression tree:
         *
         * ```
         *      *
         *     + 3
         *    1 2
         * ```
         */
        class ExpressionFactory : public SymbolFactory {
        public:
            static Expression *produce(std::deque<lexer::Token> &tokens, ParseResults &results);

        private:
            static Expression *gobbleExpression(std::deque<lexer::Token> &deque, ParseResults &results);
            static Expression *gobbleBinaryExpression(std::deque<lexer::Token> &deque, ParseResults &results);
            static Expression *gobbleToken(std::deque<lexer::Token> &deque, ParseResults &results);
            static lexer::TokenType gobbleBinaryOp(std::deque<lexer::Token> &deque);
            static NumberLiteral *gobbleNumericLiteral(std::deque<lexer::Token> &deque);
            static Expression *gobbleStringLiteral(std::deque<lexer::Token> &deque);
            static Expression *gobbleVariable(std::deque<lexer::Token> &deque, ParseResults &results);
            static Expression *gobbleGroup(std::deque<lexer::Token> &deque, ParseResults &results);
            static Expression *gobbleIdentifier(std::deque<lexer::Token> &deque);
            static std::vector<Expression*> gobbleArguments(std::deque<lexer::Token> &deque,
                                                                        lexer::TokenType termination,
                                                                        ParseResults &results);
            static ArrayLiteral *gobbleArray(std::deque<lexer::Token> &deque, ParseResults &results);

            static unsigned int binaryPrecedence(lexer::TokenType tokenType);
            static Associativity associativity(lexer::TokenType tokenType);

            static Expression *createBinaryExpression(lexer::TokenType op, Expression *left, Expression *right);

            static bool isUnaryOperator(lexer::Token &token);
            static Expression *gobbleBoolLiteral(std::deque<lexer::Token> &deque);

            static void replaceAll(std::string &subject, const std::string &search, const std::string &replace);

        private:
            static const std::map<lexer::TokenType, OperatorInfo> BINARY_OPS;
        };
    }
}

#endif //DEMUSE_EXPRESSIONFACTORY_H
