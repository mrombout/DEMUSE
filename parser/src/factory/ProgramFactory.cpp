#include <vector>
#include "factory/ProgramFactory.h"
#include "factory/StatementFactory.h"
#include "symbol/Program.h"

namespace dem {
    namespace parser {
        Program *ProgramFactory::produce(std::deque<lexer::Token> &tokens) {
            // program = { statement } ;

            std::vector<Statement*> statements;

            while(!tokens.empty()) {
                Statement *statement = StatementFactory::produce(tokens);
                if(statement == nullptr)
                    break;
                statements.push_back(statement);
            }

            // TODO: Error when tokens !empty, tokens should be empty since all tokens should have been processed. Possible change line 16

            return new Program(statements);
        }
    }
}
