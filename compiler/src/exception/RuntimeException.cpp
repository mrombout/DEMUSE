#include "exception/RuntimeException.h"

namespace dem {
    namespace compiler {
        RuntimeException::RuntimeException(const std::string &msg) :
            mMsg(msg) {

        }

        const char *RuntimeException::what() const noexcept {
            return mMsg.c_str();
        }
    }
}
