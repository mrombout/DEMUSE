#include <vector>
#include "factory/ParameterListFactory.h"
#include "factory/IdentifierFactory.h"
#include "symbol/Identifier.h"
#include "symbol/ParameterList.h"

namespace dem {
    namespace parser {
        ParameterList *ParameterListFactory::produce(std::deque<lexer::Token> &tokens) {
            // parameter_list = identifier | parameter_list "," identifier ;

            std::vector<Identifier*> identifiers;

            do {
                identifiers.push_back(IdentifierFactory::produce(tokens));
            } while(accept(tokens, lexer::TokenType::COMMA));

            return new ParameterList(identifiers);
        }
    }
}
