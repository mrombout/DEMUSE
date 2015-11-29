#include <regex>
#include "factory/TrackFactory.h"
#include "factory/BlockFactory.h"
#include "exception/ParsingException.h"

namespace dem {
    namespace parser {
        std::regex TrackFactory::RGX_CHANNEL{"[0-9][0-6]?"};

        Track *TrackFactory::produce(std::deque <lexer::Token> &tokens) {
            // track = "track" (1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 ) block ;

            // "track"
            expect(tokens, lexer::TokenType::TRACK);

            // (1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 | 16 )
            lexer::Token token = tokens.front();
            if(!std::regex_match(token.content(), RGX_CHANNEL)) {
                throw ParsingException(); // TODO: Proper exception message
            }
            int channel = atoi(token.content().c_str());
            tokens.pop_front();

            // block
            Block *block = BlockFactory::produce(tokens);

            return new Track(channel, block);
        }
    }
}