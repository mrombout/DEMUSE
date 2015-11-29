#include <vector>
#include "factory/ProgramFactory.h"
#include "factory/TrackFactory.h"
#include "symbol/Program.h"

namespace dem {
    namespace parser {
        Program *ProgramFactory::produce(std::deque<lexer::Token> &tokens) {
            // program = { track } ;

            std::vector<Track*> tracks;

            while(!tokens.empty()) {
                Track *track = TrackFactory::produce(tokens);
                if(track == nullptr)
                    break;
                tracks.push_back(track);
            }

            // TODO: Error when tokens !empty, tokens should be empty since all tokens should have been processed. Possible change line 16

            return new Program(tracks);
        }
    }
}
