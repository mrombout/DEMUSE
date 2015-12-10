#include <vector>
#include "exception/ParsingException.h"
#include "factory/VariableDeclarationFactory.h"
#include "factory/FunctionDefinitionFactory.h"
#include "factory/ProgramFactory.h"
#include "factory/TrackFactory.h"
#include "symbol/Program.h"
#include "symbol/expression/FunctionDefinition.h"
#include "symbol/VariableDeclaration.h"

namespace dem {
    namespace parser {
        Program *ProgramFactory::produce(std::deque<lexer::Token> &tokens) {
            // program = { function_def | track } ;

            std::vector<Statement*> statements;

            while(!tokens.empty()) {
                Statement *statement = nullptr;
                if(tokens.front().is(lexer::TokenType::FUNCTION)) {
                    statement = FunctionDefinitionFactory::produce(tokens);
                } else if(tokens.front().is(lexer::TokenType::VAR)) {
                    statement = VariableDeclarationFactory::produce(tokens);
                    expect(tokens, lexer::TokenType::TERMINATOR); // TODO: Remove this expect, duplicate with statement factory. Possibly move this check to factory for each statement so they can be used separately like this
                } else if(tokens.front().is(lexer::TokenType::TRACK)) {
                    statement = TrackFactory::produce(tokens);
                }
                if(!statement)
                    break;
                statements.push_back(statement);
            }

            if(!tokens.empty()) {
                std::stringstream ss;
                ss << "Expected function definition or track, but got '" << tokens.front().content() << "'.";
                throw ParsingException(tokens.front(), ss.str());
            }

            return new Program(statements);
        }
    }
}
