#include "factory/PrimitiveFactory.h"
#include "factory/NoteFactory.h"
#include "symbol/expression/BoolLiteral.h"
#include "symbol/expression/TextLiteral.h"
#include "symbol/expression/NumberLiteral.h"
#include "symbol/play/Note.h"

namespace dem {
    namespace parser {
        Primitive *PrimitiveFactory::produce(std::deque<lexer::Token> &tokens, ParseResults &results) {
            // primitive = bool | text | number | note
            // bool      = "true" | "false"
            // text      = '"' { ? any utf8_char except unescaped '"' ? | escape } '"' ;
            // number    = integer | double ;
            // integer   = nonzero { digit } | zero ;
            // double    = [ integer ] fraction ;
            // fraction  = "," { digit } ;
            // note      = ( ( "C" | "C#" | "D" | "D#" | "E" | "F" | "F#" | "G" | "G#" | "A" | "A#" | "B" ) [ integer ] | "R" ) [ "w" | "h" | "q" ] ;

            // bool
            lexer::Token token = tokens.front();
            std::string content = token.content();

            parser::Primitive *primitive = nullptr;
            if(tokens.front().is(lexer::TokenType::BOOL)) {
                tokens.pop_front();
                //primitive = new BoolLiteral(content == "true");
            } else if(tokens.front().is(lexer::TokenType::TEXT)) {
                tokens.pop_front();
                //primitive = new TextLiteral(content.substr(1, content.length() - 2));
            } else if(tokens.front().is(lexer::TokenType::NUMBER)) {
                tokens.pop_front();
                //primitive = new NumberLiteral(std::stod(content));
                // TODO: Fix me
            } else if(tokens.front().is(lexer::TokenType::NOTE)) {
                primitive = NoteFactory::produce(tokens, results);
            }

            // TODO: Support for POSITIVE/NEGATIVE
            // TODO: ! (not) unary operator
            // TODO: Note

            return primitive;
        }
    }
}
