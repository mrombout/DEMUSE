#ifndef DEMUSE_PARSER_H
#define DEMUSE_PARSER_H

#include <memory>
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
        public:
            ParseResults() :
                    mAstRoot(nullptr) {

            }

            void setAstRoot(std::shared_ptr<Symbol> symbol) {
                mAstRoot.swap(symbol);
            }

            const std::shared_ptr<Symbol> astRoot() const {
                return mAstRoot;
            }

            const std::vector<ParseError> &errors() const {
                return mErrors;
            }

            void addError(const ParseError &parseError) {
                mErrors.push_back(parseError);
            }

            bool successful() {
                return mErrors.empty();
            }

        private:
            std::shared_ptr<Symbol> mAstRoot;
            std::vector<ParseError> mErrors;
        };

        class Parser {
        public:
            virtual ParseResults parse(std::vector<lexer::Token> &symbols) = 0;
        };
    }
}

#endif //DEMUSE_PARSER_H
