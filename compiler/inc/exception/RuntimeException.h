#ifndef DEMUSE_RUNTIMEEXCEPTION_H
#define DEMUSE_RUNTIMEEXCEPTION_H

#include <exception>
#include "Token.h"
#include "symbol/Symbol.h"

namespace dem {
    namespace compiler {
        /**
         * \brief Exception thrown when an error occurs during runtime
         *
         * TODO: Rename to CompileException for consistency
         */
        class RuntimeException : public std::exception {
        public:
            RuntimeException(const std::string &msg);
            RuntimeException(const lexer::Token token, const std::string &msg);

            virtual const char *what() const noexcept override;

            const lexer::Token token() const;

        private:
            const std::string mMsg;
            const lexer::Token mToken;
        };
    }
}

#endif //DEMUSE_RUNTIMEEXCEPTION_H
