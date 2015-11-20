#include "factory/FunctionDefinitionFactory.h"
#include "factory/IdentifierFactory.h"
#include "factory/BlockFactory.h"
#include "factory/ParameterListFactory.h"
#include "symbol/Identifier.h"
#include "symbol/Block.h"
#include "symbol/ParameterList.h"
#include "symbol/FunctionDefinition.h"

namespace dem {
    namespace parser {
        FunctionDefinition *FunctionDefinitionFactory::produce(std::deque <lexer::Token> &tokens) {
            // function_def = "function" identifier "(" [ parameter_list ] ")" block ;

            // "function"
            expect(tokens, lexer::TokenType::FUNCTION);

            // identifier
            Identifier *identifier = IdentifierFactory::produce(tokens);

            // "("
            expect(tokens, lexer::TokenType::OPEN);

            // [ parameter_list ]
            ParameterList *parameterList = new ParameterList();
            if(!tokens.front().is(lexer::TokenType::CLOSE)) {
                delete parameterList;
                parameterList = ParameterListFactory::produce(tokens);
            }

            // ")"
            expect(tokens, lexer::TokenType::CLOSE);

            // block
            Block *block = BlockFactory::produce(tokens);

            return new FunctionDefinition(identifier, parameterList, block);
        }
    }
}
