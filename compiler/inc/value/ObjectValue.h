#ifndef DEMUSE_OBJECTVALUE_H
#define DEMUSE_OBJECTVALUE_H

#include <map>
#include "value/Value.h"

namespace dem {
    namespace compiler {
        class ObjectValue : public Value {
        private:
            std::map<std::string, Value*> mProperties;
        };
    }
}

#endif //DEMUSE_OBJECTVALUE_H
