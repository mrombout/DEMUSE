#include "factory/ContinueFactory.h"

namespace dem {
    namespace parser {
        Continue *ContinueFactory::produce(std::deque<lexer::Token> &tokens) {
            return new Continue();
        }
    }
}
