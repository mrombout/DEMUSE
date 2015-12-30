#include <vector>
#include "value/function/InternalFunction.h"

namespace dem {
    namespace compiler {
        void InternalFunction::mapScope(Scope &scope, std::vector<Value*> &arguments) {
            int curIndex = 0;
            for(Value *value : arguments) {
                std::string name = std::to_string(++curIndex);
                scope.declareVariable(new parser::Identifier(lexer::Token(lexer::TokenType::IDENTIFIER, name, lexer::TokenPosition()), name), value);
            }
        }
    }
}
