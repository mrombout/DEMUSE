#ifndef DEMUSE_OBJECTVALUE_H
#define DEMUSE_OBJECTVALUE_H

#include <map>
#include "value/Value.h"

namespace dem {
    namespace compiler {
        class ObjectValue : public Value {
        public:
            virtual Value *operator[](const std::string &index);

        protected:
            std::map<std::string, Value*> mProperties;
        };
    }
}

#endif //DEMUSE_OBJECTVALUE_H
