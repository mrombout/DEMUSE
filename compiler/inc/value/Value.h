#ifndef DEMUSE_VALUE_H
#define DEMUSE_VALUE_H

#include <string>

namespace dem {
    namespace compiler {
        class Value {
        public:
            virtual ~Value() { }

            virtual std::string toString() = 0;
        };
    }
}

#endif //DEMUSE_VALUE_H
