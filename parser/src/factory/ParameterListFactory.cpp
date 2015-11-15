#include <vector>
#include "symbol/Identifier.h"
#include "factory/ParameterListFactory.h"
#include "factory/IdentifierFactory.h"

namespace dem {
    namespace parser {
        ParameterList *ParameterListFactory::produce(std::deque<lexer::Token> &tokens) {
            // parameter_list = identifier | parameter_list "," identifier ;

            std::vector<Identifier*> identifiers;

            // identifier
            Identifier *identifier = IdentifierFactory::produce(tokens);

            // "," identifier
            while(accept(tokens, lexer::TokenType::COMMA)) {
                identifiers.push_back(IdentifierFactory::produce(tokens));
            }

            return new ParameterList(identifiers);
        }
    }
}
