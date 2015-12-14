#include "symbol/ArgumentList.h"
#include "symbol/ArgumentList.h"
#include "factory/ArgumentListFactory.h"
#include "factory/IdentifierFactory.h"
#include "factory/NewInstanceFactory.h"

namespace dem {
    namespace parser {
        NewInstance *NewInstanceFactory::produce(std::deque<lexer::Token> &tokens) {
            // new_instance = "new" identfier "(" argument_list ")" ;

            // "new"
            expect(tokens, lexer::TokenType::NEW);

            // identifier
            Identifier *identifier = IdentifierFactory::produce(tokens);

            // "("
            expect(tokens, lexer::TokenType::OPEN);

            // argument_list
            ArgumentList *argumentList = new ArgumentList(std::vector<Expression*>());
            if(!tokens.front().is(lexer::TokenType::CLOSE)) {
                argumentList = ArgumentListFactory::produce(tokens);
            }

            // ")"
            expect(tokens, lexer::TokenType::CLOSE);

            return new NewInstance(identifier, argumentList);
        }
    }
}
