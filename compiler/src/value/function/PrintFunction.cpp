#include <iostream>
#include "value/function/PrintFunction.h"
#include "value/Variable.h"

namespace dem {
    namespace compiler {
        Value *PrintFunction::operator()(Scope &scope) {
            std::cout << scope.variable(new parser::Identifier(lexer::Token(lexer::TokenType::IDENTIFIER, "1", lexer::TokenPosition()), "1")).asString() << std::endl;

            return Value::operator()(scope);
        }
    }
}
