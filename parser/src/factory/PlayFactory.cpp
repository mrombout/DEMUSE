#include <vector>
#include "factory/PlayFactory.h"
#include "symbol/play/Note.h"

namespace dem {
    namespace parser {
        Play *PlayFactory::produce(std::deque<lexer::Token> &tokens) {
            // play_stmt = "<<" { note } ">>" ;



            return new Play();
        }
    }
}
