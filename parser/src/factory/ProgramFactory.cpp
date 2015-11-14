#include <vector>
#include "factory/ProgramFactory.h"
#include "Symbol.h"

namespace dem {
    namespace parser {
        Symbol ProgramFactory::produce(std::deque<lexer::Token> &tokens) {
            return parser::Symbol();
        }
    }
}
