#include "factory/StatementFactory.h"
#include "factory/AssignmentFactory.h"
#include "factory/ExpressionFactory.h"
#include "factory/ReturnFactory.h"
#include "factory/BreakFactory.h"
#include "factory/ContinueFactory.h"
#include "factory/IfFactory.h"
#include "factory/WhileFactory.h"
#include "factory/ForFactory.h"
#include "factory/FunctionDefinitionFactory.h"

namespace dem {
    namespace parser {
        Statement *StatementFactory::produce(std::deque<lexer::Token> &tokens) {
            // statement = ( simple_statement | compound_statement ) terminator ;

            // simple_stmt = return_stmt | break_stmt | continue_stmt | assignment_stmt | expression_stmt ;
            if(tokens.front().is(lexer::TokenType::RETURN)) {
                // return_stmt
                return ReturnFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::BREAK)) {
                // break_stmt
                return BreakFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::CONTINUE)) {
                // continue_stmt
                return ContinueFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::IDENTIFIER)) {
                // assignment_stmt
                Assignment *assignment = AssignmentFactory::produce(tokens);
                if(assignment)
                    return assignment;

                // expression_stmt
                Expression *expression = ExpressionFactory::produce(tokens);
                if(expression)
                    return expression;
            }

            // compound_stmt = if_stmt | while_stmt | for_stmt | function_def | play_stmt ;
            if(tokens.front().is(lexer::TokenType::IF)) {
                // if_stmt
                return IfFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::WHILE)) {
                // while_stmt
                return WhileFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::FOR)) {
                // for_stmt
                return ForFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::FUNCTION)) {
                // function_def
                return FunctionDefinitionFactory::produce(tokens);
            }

            // TODO: play_stmt
            // TODO: Throw some error, since this does not seem to be a statement
        }
    }
}