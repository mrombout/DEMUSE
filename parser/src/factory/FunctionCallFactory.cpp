#include "factory/FunctionCallFactory.h"
#include "factory/IdentifierFactory.h"
#include "factory/ArgumentListFactory.h"
#include "symbol/FunctionCall.h"
#include "symbol/ArgumentList.h"

namespace dem {
    namespace parser {
        FunctionCall *FunctionCallFactory::produce(std::deque <lexer::Token> &tokens) {
            // identifier "(" [ argument_list ] ")" ;

            // identifier
            lexer::Token identifierToken = tokens.front();
            Identifier *identifier = IdentifierFactory::produce(tokens);

            // "("
            if(!accept(tokens, lexer::TokenType::OPEN)) {
                tokens.push_front(identifierToken);
                return nullptr;
            }

            // [ argument_list ]
            ArgumentList *argumentList = new parser::ArgumentList(std::vector<Expression*>());
            if(!tokens.front().is(lexer::TokenType::CLOSE)) {
                argumentList = ArgumentListFactory::produce(tokens);
            }

            // ")"
            expect(tokens, lexer::TokenType::CLOSE);

            return new FunctionCall(identifier, argumentList);
        }
    }
}