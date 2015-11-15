#include "factory/IdentifierFactory.h"
#include "factory/ExpressionFactory.h"
#include "factory/PrimitiveFactory.h"

namespace dem {
    namespace parser {
        const std::map<lexer::TokenType, int> ExpressionFactory::mOperatorPrecedence = {
            // TODO: (), [], ->, ., ::  -- 1
            // TODO: ! ~ - + ++ -- -- 2
            { lexer::TokenType::TIMES,  3 },
            { lexer::TokenType::DIVIDE, 3 },
            // TODO: MOD, 3
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
            { lexer::TokenType::TIMES,  ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::DIVIDE, ExpressionFactory::Associativity::LEFT },
            // TODO: MOD, LEFT
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

            return processExpression(tokens, 0);
        }

        Expression *ExpressionFactory::processExpression(std::deque<lexer::Token> &tokens, int minPrecedence) {
            Expression *lhs = producePrimary(tokens);
            Expression *rhs = nullptr;

            while(continueProcessingTokens(tokens, minPrecedence)) {
                lexer::Token op = tokens.front();

                int precedence = mOperatorPrecedence.at(op.type());
                Associativity associativity = mOperatorAssociativity.at(op.type());

                int nextMinPrecedence = associativity == Associativity::LEFT ? precedence + 1 : precedence;

                rhs = processExpression(tokens, nextMinPrecedence);
                Expression *expression = produceExpression(op, lhs, rhs);
                lhs = expression;
            }

            return lhs;
        }

        bool ExpressionFactory::continueProcessingTokens(std::deque<lexer::Token> &tokens, int minPrecedence) {
            lexer::Token token = tokens.front();

            bool isBinaryOperator = !token.is(lexer::TokenType::PLUS)
                || !token.is(lexer::TokenType::MINUS)
                || !token.is(lexer::TokenType::TIMES)
                || !token.is(lexer::TokenType::DIVIDE)
                || !token.is(lexer::TokenType::AND)
                || !token.is(lexer::TokenType::OR);
            // TODO: Modulo

            bool largerOrEqualMinPrecedence = isBinaryOperator ? mOperatorPrecedence.at(token.type()) < minPrecedence : false;

            return !isBinaryOperator && largerOrEqualMinPrecedence;
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

        Expression *ExpressionFactory::produceExpression(lexer::Token token, Symbol *pSymbol, Symbol *rhs) {
            return nullptr;
        }
    }
}