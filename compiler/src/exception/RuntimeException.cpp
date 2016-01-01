#include "exception/RuntimeException.h"

namespace dem {
    namespace compiler {
        RuntimeException::RuntimeException(const std::string &msg) :
            mToken(lexer::TokenType::UNKNOWN, "", lexer::TokenPosition()),
            mMsg(msg) {

        }

        RuntimeException::RuntimeException(const lexer::Token token, const std::string &msg) :
            mToken(token),
            mMsg(msg) {

        }

        const char *RuntimeException::what() const noexcept {
            return mMsg.c_str();
        }

        const lexer::Token RuntimeException::token() const {
            return mToken;
        }
    }
}
