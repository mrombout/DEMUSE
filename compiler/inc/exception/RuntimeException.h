#ifndef DEMUSE_PARSINGEXCEPTION_H
#define DEMUSE_PARSINGEXCEPTION_H

#include <exception>
#include "Token.h"
#include "symbol/Symbol.h"

namespace dem {
    namespace compiler {
        class RuntimeException : public std::exception {
        public:
            RuntimeException(const std::string &msg);

            virtual const char *what() const noexcept override;

        private:
            const std::string mMsg;
        };
    }
}

#endif //DEMUSE_PARSINGEXCEPTION_H
