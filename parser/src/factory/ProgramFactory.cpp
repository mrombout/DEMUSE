#include <vector>
#include "factory/StatementFactory.h"
#include "factory/ProgramFactory.h"
#include "factory/TrackFactory.h"
#include "symbol/Program.h"

namespace dem {
    namespace parser {
        std::unique_ptr<Program> ProgramFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // program = { statement | track } ;

            std::vector<Statement*> statements;

            while(!tokens.front().isEOF()) {
                Statement *statement = nullptr;

                if(tokens.front().is(lexer::TokenType::TRACK)) {
                    statement = TrackFactory::produce(tokens, results);
                } else {
                    statement = StatementFactory::produce(tokens, results);
                }

                if(!statement)
                    break;
                statements.push_back(statement);
            }

            if(!tokens.front().isEOF()) {
                std::stringstream ss;
                ss << "Unexpected '" << tokens.front().content() << "'.";
                addError(results, tokens.front(), ss.str());
            }

            return std::move(std::unique_ptr<Program>(new Program(statements)));
        }
    }
}
