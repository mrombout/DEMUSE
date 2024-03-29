#include <vector>
#include "symbol/ArgumentList.h"
#include "factory/ArgumentListFactory.h"
#include "factory/IdentifierFactory.h"
#include "factory/NewInstanceFactory.h"

namespace dem {
    namespace parser {
        NewInstance *NewInstanceFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // new_instance = "new" identfier "(" argument_list ")" ;

            // "new"
            expect(tokens, lexer::TokenType::NEW, results);

            // identifier
            Identifier *identifier = IdentifierFactory::produce(tokens, results);

            // "("
            lexer::Token token = tokens.front();
            expect(tokens, lexer::TokenType::OPEN, results);

            // argument_list
            ArgumentList *argumentList = nullptr;
            if(!tokens.front().is(lexer::TokenType::CLOSE)) {
                argumentList = ArgumentListFactory::produce(tokens, results);
            } else {
                argumentList = new ArgumentList(token, std::vector<Expression*>());
            }

            // ")"
            expect(tokens, lexer::TokenType::CLOSE, results);

            return new NewInstance(identifier, argumentList);
        }
    }
}
