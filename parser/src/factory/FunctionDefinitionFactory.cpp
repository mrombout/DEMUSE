#include "factory/FunctionDefinitionFactory.h"
#include "factory/IdentifierFactory.h"
#include "factory/BlockFactory.h"
#include "factory/ParameterListFactory.h"
#include "symbol/Identifier.h"
#include "symbol/Block.h"
#include "symbol/ParameterList.h"
#include "symbol/expression/FunctionDefinition.h"

namespace dem {
    namespace parser {
        FunctionDefinition *FunctionDefinitionFactory::produce(std::deque <lexer::Token> &tokens, ParseResults &results) {
            // function_def = "function" identifier "(" [ parameter_list ] ")" block ;

            // "function"
            lexer::Token token = tokens.front();
            expect(tokens, lexer::TokenType::FUNCTION, results);

            // identifier
            Identifier *identifier = nullptr;
            if(tokens.front().is(lexer::TokenType::IDENTIFIER))
                identifier = IdentifierFactory::produce(tokens, results);

            // "("
            expect(tokens, lexer::TokenType::OPEN, results);

            // [ parameter_list ]
            ParameterList *parameterList = nullptr;
            if(!tokens.front().is(lexer::TokenType::CLOSE)) {
                delete parameterList;
                parameterList = ParameterListFactory::produce(tokens, results);
            } else {
                parameterList = new ParameterList(tokens.front());
            }

            // ")"
            expect(tokens, lexer::TokenType::CLOSE, results);

            // block
            Block *block = BlockFactory::produce(tokens, results);

            return new FunctionDefinition(token, identifier, parameterList, block);
        }
    }
}
