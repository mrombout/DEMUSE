#include <vector>
#include "factory/PlayFactory.h"
#include "symbol/play/Note.h"

namespace dem {
    namespace parser {
        Play *PlayFactory::produce(std::deque<lexer::Token> &tokens) {
            // play_stmt = "<<" { note } ">>" ;

            if(!tokens.front().is(lexer::TokenType::PLAY))
                throw "Some kind or error"; // TODO: Throw proper error

            lexer::Token playToken = tokens.front();
            tokens.pop_front();

            std::string content = playToken.content();
            auto it = content.begin();

            std::vector<parser::Note*> notes;

            // "<<"
            for(int i = 0; i < 2; ++i) {
                if((*it) != '<')
                    throw "No play start"; // TODO: Throw proper error
                ++it;
            }

            // { note }
            while(*it != '>') {
                // note
                if(*it == 'C') {
                    notes.push_back(new Note());
                }
                ++it;
            }

            // ">>"
            for(int i = 0; i < 2; ++i) {
                if((*it) != '>')
                    throw "No play end"; // TODO: Throw proper error
                ++it;
            }

            return new Play();
        }
    }
}
