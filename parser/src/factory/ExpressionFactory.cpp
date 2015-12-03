#include <exception/ParsingException.h>
#include "factory/IdentifierFactory.h"
#include "factory/ExpressionFactory.h"
#include "factory/PrimitiveFactory.h"
#include "factory/FunctionCallFactory.h"
#include "symbol/expression/AdditionExpression.h"
#include "symbol/expression/SubtractionExpression.h"
#include "symbol/expression/MultiplicationExpression.h"
#include "symbol/expression/DivisionExpression.h"
#include "symbol/expression/ModuloExpression.h"
#include "symbol/expression/AssignmentExpression.h"
#include "symbol/expression/ExponentExpression.h"
#include "symbol/expression/SmallerThanCondition.h"
#include "symbol/expression/SmallerThanOrEqualCondition.h"
#include "symbol/expression/LargerThanCondition.h"
#include "symbol/expression/LargerThanOrEqualCondition.h"
#include "symbol/expression/EqualCondition.h"
#include "symbol/expression/StrictEqualCondition.h"
#include "symbol/expression/NotEqualCondition.h"
#include "symbol/expression/StrictNotEqualCondition.h"
#include "symbol/expression/AndCondition.h"
#include "symbol/expression/OrCondition.h"
#include "symbol/Identifier.h"
#include "symbol/Primitive.h"

namespace dem {
    namespace parser {
        const std::map<lexer::TokenType, int> ExpressionFactory::mOperatorPrecedence = {
            // TODO: (), []  -- 1
            { lexer::TokenType::PERIOD,     1 },
            // TODO: ! ~ - + ++ -- -- 2
            { lexer::TokenType::EXP,        2 },
            { lexer::TokenType::TIMES,      3 },
            { lexer::TokenType::DIVIDE,     3 },
            { lexer::TokenType::MOD,        3 },
            { lexer::TokenType::PLUS,       4 },
            { lexer::TokenType::MINUS,      4 },
            { lexer::TokenType::SM,         6 },
            { lexer::TokenType::SMEQ,       6 },
            { lexer::TokenType::LR,         6 },
            { lexer::TokenType::LREQ,       6 },
            { lexer::TokenType::EQ,         7 },
            { lexer::TokenType::TEQ,        7 },
            { lexer::TokenType::NEQ,        7 },
            { lexer::TokenType::TNEQ,       7 },
            { lexer::TokenType::AND,        11 },
            { lexer::TokenType::OR,         12 },
            { lexer::TokenType::ASSIGNMENT, 14 },
            // TODO: += -= *= /= %= &= |= ^= -- 14
            // TODO: , -- 15
        };

        const std::map<lexer::TokenType, ExpressionFactory::Associativity> ExpressionFactory::mOperatorAssociativity = {
            { lexer::TokenType::PERIOD,     ExpressionFactory::Associativity::RIGHT },
            { lexer::TokenType::EXP,        ExpressionFactory::Associativity::RIGHT },
            { lexer::TokenType::TIMES,      ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::DIVIDE,     ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::MOD,        ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::PLUS,       ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::MINUS,      ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::SM,         ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::SMEQ,       ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::LR,         ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::LREQ,       ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::EQ,         ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::TEQ,        ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::NEQ,        ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::TNEQ,       ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::AND,        ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::OR,         ExpressionFactory::Associativity::LEFT },
            { lexer::TokenType::ASSIGNMENT, ExpressionFactory::Associativity::LEFT }
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
                || token.is(lexer::TokenType::EXP)
                || token.is(lexer::TokenType::TIMES)
                || token.is(lexer::TokenType::DIVIDE)
                || token.is(lexer::TokenType::MOD)
                || token.is(lexer::TokenType::ASSIGNMENT)
                || token.is(lexer::TokenType::EQ)
                || token.is(lexer::TokenType::NEQ)
                || token.is(lexer::TokenType::TEQ)
                || token.is(lexer::TokenType::TNEQ)
                || token.is(lexer::TokenType::SM)
                || token.is(lexer::TokenType::SMEQ)
                || token.is(lexer::TokenType::LR)
                || token.is(lexer::TokenType::LREQ)
                || token.is(lexer::TokenType::AND)
                || token.is(lexer::TokenType::OR)
                || token.is(lexer::TokenType::SM);
            // TODO: Modulo

            bool smallerOrEqual = isBinaryOperator ? mOperatorPrecedence.at(token.type()) <= minPrecedence : false;

            return isBinaryOperator && smallerOrEqual;
        }

        Expression *ExpressionFactory::producePrimary(std::deque<lexer::Token> &tokens) {
            if(accept(tokens, lexer::TokenType::OPEN)) {
                // nested expression
                Expression *expression = processExpression(tokens, 15);
                expect(tokens, lexer::TokenType::CLOSE);

                return expression;
            } else if(tokens.front().is(lexer::TokenType::IDENTIFIER)) {
                // identifier | call
                Expression *expression = FunctionCallFactory::produce(tokens);
                if(expression)
                    return expression;
                return IdentifierFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::NUMBER)
                   || tokens.front().is(lexer::TokenType::TEXT)
                   || tokens.front().is(lexer::TokenType::BOOL)
                   || tokens.front().is(lexer::TokenType::POSITIVE)
                   || tokens.front().is(lexer::TokenType::NEGATIVE)) {
                // primitive
                return PrimitiveFactory::produce(tokens);
            }

            throw ParsingException(tokens.front(), "Unrecognized primary '" + tokens.front().content() + "' in expression.");
        }

        Expression *ExpressionFactory::produceExpression(lexer::Token token, Expression *lhs, Expression *rhs) {
            switch(token.type()) {
                case lexer::TokenType::PLUS:
                    return new AdditionExpression(lhs, rhs);
                case lexer::TokenType::MINUS:
                    return new SubtractionExpression(lhs, rhs);
                case lexer::TokenType::EXP:
                    return new ExponentExpression(lhs, rhs);
                case lexer::TokenType::TIMES:
                    return new MultiplicationExpression(lhs, rhs);
                case lexer::TokenType::DIVIDE:
                    return new DivisionExpression(lhs, rhs);
                case lexer::TokenType::MOD:
                    return new ModuloExpression(lhs, rhs);
                case lexer::TokenType::ASSIGNMENT: {
                    Identifier *identifier = dynamic_cast<Identifier*>(lhs);
                    if(identifier == nullptr)
                        throw ParsingException(token, "Expected identifier in expression.");
                    return new AssignmentExpression(identifier, rhs);
                }
                case lexer::TokenType::SM:
                    return new SmallerThanCondition(lhs, rhs);
                case lexer::TokenType::SMEQ:
                    return new SmallerThanOrEqualCondition(lhs, rhs);
                case lexer::TokenType::LR:
                    return new LargerThanCondition(lhs, rhs);
                case lexer::TokenType::LREQ:
                    return new LargerThanOrEqualCondition(lhs, rhs);
                case lexer::TokenType::EQ:
                    return new EqualCondition(lhs, rhs);
                case lexer::TokenType::TEQ:
                    return new StrictEqualCondition(lhs, rhs);
                case lexer::TokenType::NEQ:
                    return new NotEqualCondition(lhs, rhs);
                case lexer::TokenType::TNEQ:
                    return new StrictNotEqualCondition(lhs, rhs);
                case lexer::TokenType::AND:
                    return new AndCondition(lhs, rhs);
                case lexer::TokenType::OR:
                    return new OrCondition(lhs, rhs);
            }
        }
    }
}