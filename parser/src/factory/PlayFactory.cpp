#include <vector>
#include "factory/InstrumentFactory.h"
#include "factory/IdentifierFactory.h"
#include "factory/PlayFactory.h"
#include "factory/NoteFactory.h"
#include "symbol/play/Harmony.h"
#include "symbol/play/Note.h"
#include "symbol/Identifier.h"

namespace dem {
    namespace parser {
        Play *PlayFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // play_stmt = "<<" { note | identifier } ">>" ;

            // "<<"
            expect(tokens, lexer::TokenType::PLAY_START, results);

            // { note }
            std::vector<Expression*> playables;
            do {
                // playable
                Expression *playable = nullptr;
                playable = parsePart(tokens, results);

                // is it a harmony?
                if(tokens.front().is(lexer::TokenType::HARMONY)) {
                    Harmony *harmony = new Harmony(playable->token());
                    harmony->addNote(playable);
                    do {
                        expect(tokens, lexer::TokenType::HARMONY, results);
                        playable = playable = parsePart(tokens, results);
                        if(playable)
                            harmony->addNote(playable);
                    } while(tokens.front().is(lexer::TokenType::HARMONY) && !tokens.front().is(lexer::TokenType::PLAY_END));
                    playables.push_back(harmony);
                } else {
                    if(playable)
                        playables.push_back(playable);
                }
            } while(!tokens.front().is(lexer::TokenType::PLAY_END));

            // ">>"
            expect(tokens, lexer::TokenType::PLAY_END, results);

            return new Play(playables);
        }

        Expression *PlayFactory::parsePart(std::deque<lexer::Token> &tokens, ParseResults &results) {
            if(tokens.front().is(lexer::TokenType::INSTRUMENT)) {
                return InstrumentFactory::produce(tokens, results);
            } else if(tokens.front().is(lexer::TokenType::IDENTIFIER)) {
                return IdentifierFactory::produce(tokens, results);
            } else {
                return NoteFactory::produce(tokens, results);
            }
        }
    }
}
