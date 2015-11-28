#include <vector>
#include "factory/PlayFactory.h"
#include "factory/NoteFactory.h"
#include "symbol/play/Note.h"

namespace dem {
    namespace parser {
        Play *PlayFactory::produce(std::deque<lexer::Token> &tokens) {
            // play_stmt = "<<" { note } ">>" ;

            // "<<"
            expect(tokens, lexer::TokenType::PLAY_START);

            // { note }
            Note *note = nullptr;
            do {
                note = NoteFactory::produce(tokens);
            } while(!tokens.front().is(lexer::TokenType::PLAY_END));

            // ">>"
            expect(tokens, lexer::TokenType::PLAY_END);

            return new Play();
        }
    }
}
