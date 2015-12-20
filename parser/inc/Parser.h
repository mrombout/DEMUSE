#ifndef DEMUSE_PARSER_H
#define DEMUSE_PARSER_H

#include <vector>
#include "symbol/Symbol.h"
#include "Parser.h"
#include "Token.h"

namespace dem {
    namespace parser {
        class Symbol;
    }
}

namespace dem {
    namespace parser {
        struct ParseError {
            enum class Type {
                T_WARNING,
                T_ERROR
            };

            ParseError(Type type, lexer::Token token, std::string description) :
                    type(type),
                    token(token),
                    description(description) {

            }

            Type type;
            lexer::Token token;
            std::string description;
        };

        struct ParseResults {
            Symbol *astRoot;
            std::vector<ParseError> errors;

            bool successful() {
                return errors.empty();
            }
        };

        class Parser {
        public:
            virtual ParseResults parse(std::vector<lexer::Token> &symbols) = 0;
        };
    }
}

#endif //DEMUSE_PARSER_H
