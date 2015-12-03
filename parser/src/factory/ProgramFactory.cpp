#include <vector>
#include <symbol/FunctionDefinition.h>
#include <factory/FunctionDefinitionFactory.h>
#include "factory/ProgramFactory.h"
#include "factory/TrackFactory.h"
#include "symbol/Program.h"

namespace dem {
    namespace parser {
        Program *ProgramFactory::produce(std::deque<lexer::Token> &tokens) {
            // program = { function_def | track } ;

            std::vector<Statement*> statements;

            while(!tokens.empty()) {
                Statement *statement = nullptr;
                if(tokens.front().is(lexer::TokenType::FUNCTION)) {
                    statement = FunctionDefinitionFactory::produce(tokens);
                } else if(tokens.front().is(lexer::TokenType::TRACK)) {
                    statement = TrackFactory::produce(tokens);
                }
                if(!statement)
                    break;
                statements.push_back(statement);
            }

            // TODO: Error when tokens !empty, tokens should be empty since all tokens should have been processed. Possible change line 16

            return new Program(statements);
        }
    }
}
