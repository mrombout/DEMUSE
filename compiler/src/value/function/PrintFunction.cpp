#include <iostream>
#include "value/function/PrintFunction.h"

namespace dem {
    namespace compiler {
        PrintFunction::PrintFunction(ObjectValue *parent) :
                InternalFunction(parent) {

        }

        Value *PrintFunction::operator()() {
            std::cout << variable(new parser::Identifier(lexer::Token(lexer::TokenType::IDENTIFIER, "1", lexer::TokenPosition()), "1")).asString() << std::endl;

            return Value::operator()();
        }
    }
}
