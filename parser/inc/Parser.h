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
        /**
         * \brief Represents an error that occurred during the parsing of a script.
         *
         * ParseError are created and added to the ParseResults when they occur. During the parsing of a script the
         * parser should try to fix the error and continue parsing. This allows the parser to create as much useful
         * errors as it can, without the user having to resort to fixing a single error and compiling again.
         */
        struct ParseError {
            /**
             * Type of the error.
             *
             * - A T_WARNING should be used for possibly errors, or suggestions
             * - A T_ERROR should be used for syntax errors.
             */
            enum class Type {
                T_WARNING,
                T_ERROR
            };

            /**
             * \brief Constructs a new ParseError
             *
             * \param type        type of the error, see Type
             * \param token       token at which this error occurs
             * \param description description of the error
             */
            ParseError(Type type, lexer::Token token, std::string description) :
                    type(type),
                    token(token),
                    description(description) {

            }

            Type type;
            lexer::Token token;
            std::string description;
        };

        /**
         * \brief Results of a parse
         */
        struct ParseResults {
        public:
            ParseResults() :
                    mAstRoot(nullptr) {

            }

            /**
             * \brief Sets the root symbol of a parse, generally a Program symbol
             */
            void setAstRoot(std::shared_ptr<Symbol> symbol) {
                mAstRoot.swap(symbol);
            }

            /**
             * \return the root symbol of a parse, generally a Program
             */
            const std::shared_ptr<Symbol> astRoot() const {
                return mAstRoot;
            }

            /**
             * \return list of errors that occured during the parse
             */
            const std::vector<ParseError> &errors() const {
                return mErrors;
            }

            /**
             * \brief Adds a new error to the list
             */
            void addError(const ParseError &parseError) {
                mErrors.push_back(parseError);
            }

            /**
             * \return wether this parse was succesfull (i.e. no errors occured)
             */
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
