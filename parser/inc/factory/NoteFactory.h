#ifndef DEMUSE_NOTEFACTORY_H
#define DEMUSE_NOTEFACTORY_H

#include <regex>
#include <deque>
#include "SymbolFactory.h"
#include "symbol/play/Note.h"

namespace dem {
    namespace parser {
        /**
         * \brief Produces a note
         *
         * Produces a note according to the definition in the EBNF. For any optional elements of a note a default value
         * is assumed, see Note for more information.
         *
         * NOTE: NoteFactory does not expect a ">" symbol to define a note literal. The note primitive symbol is merely
         * a tool for the lexer to know when to start lexing a note outside the scope of a demuse sequence.
         *
         * \ebnf note = ( ( "C" | "D" | "E" | "F" | "G" | "A" | "B" ) [ integer ] accidental | "R" ) [ "w" | "h" | "q" ] ;
         */
        class NoteFactory : public SymbolFactory {
        public:
            static Note *produce(std::deque<lexer::Token> &tokens, ParseResults &results);
        };
    }
}

#endif //DEMUSE_NOTEFACTORY_H
