#include "exception/ParsingException.h"

namespace dem {
    namespace parser {
        ParsingException::ParsingException(const lexer::Token &token, const std::string msg) :
            mToken(token),
            mMsg(msg) {

        }

        const lexer::Token &ParsingException::token() const {
            return mToken;
        }

        const char *ParsingException::what() const noexcept {
            return ("[" + std::to_string(mToken.column()) + ":" + std::to_string(mToken.line()) + "] " + mMsg).c_str();
        }
    }
}
