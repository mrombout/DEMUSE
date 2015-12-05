#include "exception/RuntimeException.h"

namespace dem {
    namespace compiler {
        RuntimeException::RuntimeException(parser::Symbol &symbol, const std::string &msg) :
            mSymbol(symbol),
            mMsg(msg) {

        }

        const parser::Symbol &RuntimeException::symbol() const {
            return mSymbol;
        }

        const char *RuntimeException::what() const noexcept {
            return mMsg.c_str();
        }
    }
}
