#include <exception/ParsingException.h>
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
#include "factory/VariableDeclarationFactory.h"
#include "factory/PlayFactory.h"
#include "symbol/Return.h"
#include "symbol/Break.h"
#include "symbol/Continue.h"
#include "symbol/VariableDeclaration.h"
#include "symbol/If.h"
#include "symbol/While.h"
#include "symbol/For.h"
#include "symbol/FunctionDefinition.h"

namespace dem {
    namespace parser {
        Statement *StatementFactory::produce(std::deque<lexer::Token> &tokens) {
            // statement = ( simple_statement | compound_statement ) terminator ;
            Statement *statement = nullptr;

            // simple_stmt = return_stmt | break_stmt | continue_stmt | variable_def_stmt | expression_stmt ;
            if(tokens.front().is(lexer::TokenType::RETURN)) {
                // return_stmt
                statement = ReturnFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::BREAK)) {
                // break_stmt
                statement = BreakFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::CONTINUE)) {
                // continue_stmt
                statement = ContinueFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::VAR)) {
                // variable_def_stmt
                statement = VariableDeclarationFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::IDENTIFIER)) {
                // expression_stmt
                statement = ExpressionFactory::produce(tokens);
            }

            // compound_stmt = if_stmt | while_stmt | for_stmt | function_def | play_stmt ;
            else if(tokens.front().is(lexer::TokenType::IF)) {
                // if_stmt
                statement = IfFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::WHILE)) {
                // while_stmt
                statement = WhileFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::FOR)) {
                // for_stmt
                statement = ForFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::FUNCTION)) {
                // function_def
                statement = FunctionDefinitionFactory::produce(tokens);
            } else if(tokens.front().is(lexer::TokenType::PLAY_START)) {
                // play_stmt
                statement = PlayFactory::produce(tokens);
            }

            if(statement == nullptr)
                throw ParsingException(); // TODO: Add clear error message

            // terminator
            expect(tokens, lexer::TokenType::TERMINATOR);

            // TODO: play_stmt
            // TODO: Throw some error, since this does not seem to be a statement

            return statement;
        }
    }
}