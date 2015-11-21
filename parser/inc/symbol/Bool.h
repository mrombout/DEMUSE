#ifndef DEMUSE_BOOL_H
#define DEMUSE_BOOL_H

#include <string>
#include "Primitive.h"

namespace dem {
    namespace parser {
        class Bool : public Primitive {
        public:
            Bool(bool value);

            virtual bool accept(Visitor &visitor);

            bool value() const;

        private:
            bool mValue;
        };
    }
}

#endif //DEMUSE_BOOL_H
