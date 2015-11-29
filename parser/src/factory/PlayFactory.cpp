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
            std::vector<Note*> notes;
            do {
                Note *note = NoteFactory::produce(tokens);
                if(note)
                    notes.push_back(note);
            } while(!tokens.front().is(lexer::TokenType::PLAY_END));

            // ">>"
            expect(tokens, lexer::TokenType::PLAY_END);

            return new Play(notes);
        }
    }
}
