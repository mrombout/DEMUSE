#include "factory/IdentifierFactory.h"
#include "factory/ExpressionFactory.h"
#include "factory/PrimitiveFactory.h"
#include "symbol/expression/AddExpression.h"
#include "symbol/expression/SubtractionExpression.h"
#include "symbol/expression/MultiplicationExpression.h"
#include "symbol/expression/DivisionExpression.h"
#include "symbol/expression/ModuloExpression.h"

namespace dem {
    namespace parser {
        const std::map<lexer::TokenType, int> ExpressionFactory::mOperatorPrecedence = {
            // TODO: (), []  -- 1
            { lexer::TokenType::PERIOD, 1 },
            // TODO: ! ~ - + ++ -- -- 2
            { lexer::TokenType::TIMES,  3 },
            { lexer::TokenType::DIVIDE, 3 },
            { lexer::TokenType::MOD,    3 },
            { lexer::TokenType::PLUS,   4 },
            { lexer::TokenType::MINUS,  4 },
            { lexer::TokenType::SM,     6 },
            { lexer::TokenType::SMEQ,   6 },
            { lexer::TokenType::LR,     6 },
            { lexer::TokenType::LREQ,   6 },
            { lexer::TokenType::EQ,     7 },
            { lexer::TokenType::NEQ,    7 },
            { lexer::TokenType::AND,    11 },
            { lexer::TokenType::OR,     12 },
            // TODO: = += -= *= /= %= &= |= ^= -- 14
            // TODO: , -- 15
        };

        const std::map<lexer::TokenType, ExpressionFactory::Associativity> ExpressionFactory::mOperatorAssociativity = {
            { lexer::TokenType::PERIOD, ExpressionFactory::Associativity::RIGHT },
            { lexer::TokenType::TIMES,  ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::DIVIDE, ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::MOD,    ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::PLUS,   ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::MINUS,  ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::SM,     ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::SMEQ,   ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::LR,     ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::LREQ,   ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::EQ,     ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::NEQ,    ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::AND,    ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::OR,     ExpressionFactory::Associativity::LEFT },
        };

        Expression *ExpressionFactory::produce(std::deque <lexer::Token> &tokens) {
            // expression        = array_init | conditional ;
            // conditional       = or_test ;

            // or_test           = and_test | or_test "||" and_test ;
            // and_test          = not_test | and_test "&&" not_test ;
            // not_test          = comparison | "!" not_test ;

            // comparison        = addition_expr [ { comparison_operator addition_expr } ] ;
            // addition_expr     = multiply_expr | addition_expr addition_op addition_expr ;
            // multiply_expr     = unary_expr | multiply_expr multiply_op multiply_expr ;
            // unary_expr        = primary | unary_op unary_expr ;
            // primary           = identifier | primitive | call_stmt ;
            // new_instance      = "new" identfier "(" argument_list ")" ;
            // array_access      = identifier "[" ( identifier | integer ) "]" ;

            // comparison_op     = eq | neq | sm | smeq | lr | lreq
            // eq                = "==" ;
            // neq               = "!=" ;
            // sm                = "<" ;
            // smeq              = "<=" ;
            // lr                = ">" ;
            // lreq              = ">=" ;
            // addition_op       = "+" | "-" ;
            // multiply_op       = "*" | "/" ;
            // unary_operator    = "-" | "+" ;

            return processExpression(tokens, 15);
        }

        Expression *ExpressionFactory::processExpression(std::deque<lexer::Token> &tokens, int minPrecedence) {
            Expression *lhs = producePrimary(tokens);
            Expression *rhs = nullptr;

            while(shouldContinueProcessingTokens(tokens, minPrecedence)) {
                lexer::Token op = tokens.front();
                tokens.pop_front();

                int precedence = mOperatorPrecedence.at(op.type());
                Associativity associativity = mOperatorAssociativity.at(op.type());

                int nextMinPrecedence = associativity == Associativity::LEFT ? precedence + 1 : precedence;

                rhs = processExpression(tokens, nextMinPrecedence);
                Expression *expression = produceExpression(op, lhs, rhs);
                lhs = expression;
            }

            return lhs;
        }

        bool ExpressionFactory::shouldContinueProcessingTokens(std::deque<lexer::Token> &tokens, int minPrecedence) {
            if(tokens.empty())
                return false;

            lexer::Token token = tokens.front();

            bool isBinaryOperator = token.is(lexer::TokenType::PLUS)
                || token.is(lexer::TokenType::MINUS)
                || token.is(lexer::TokenType::TIMES)
                || token.is(lexer::TokenType::DIVIDE)
                || token.is(lexer::TokenType::MOD)
                || token.is(lexer::TokenType::AND)
                || token.is(lexer::TokenType::OR);
            // TODO: Modulo

            bool smallerOrEqual = isBinaryOperator ? mOperatorPrecedence.at(token.type()) <= minPrecedence : false;

            return isBinaryOperator && smallerOrEqual;
        }

        Expression *ExpressionFactory::producePrimary(std::deque<lexer::Token> &tokens) {
            if(accept(tokens, lexer::TokenType::OPEN)) {
                // nested expression
                Expression *expression = processExpression(tokens, 0);
                expect(tokens, lexer::TokenType::CLOSE);

                return expression;
            } else if(tokens.front().is(lexer::TokenType::IDENTIFIER)) {
                // identifier | call
                // TODO: Function call
                return IdentifierFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::NUMBER)
                   || tokens.front().is(lexer::TokenType::TEXT)
                   || tokens.front().is(lexer::TokenType::BOOL)) {
                // primitive
                return PrimitiveFactory::produce(tokens);
            }
        }

        Expression *ExpressionFactory::produceExpression(lexer::Token token, Expression *lhs, Expression *rhs) {
            switch(token.type()) {
                case lexer::TokenType::PLUS:
                    return new AddExpression(lhs, rhs);
                case lexer::TokenType::MINUS:
                    return new SubtractionExpression(lhs, rhs);
                case lexer::TokenType::TIMES:
                    return new MultiplicationExpression(lhs, rhs);
                case lexer::TokenType::DIVIDE:
                    return new DivisionExpression(lhs, rhs);
                case lexer::TokenType::MOD:
                    return new ModuloExpression(lhs, rhs);
            }
        }
    }
}