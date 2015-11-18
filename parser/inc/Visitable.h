#ifndef DEMUSE_VISITABLE_H
#define DEMUSE_VISITABLE_H

namespace dem {
    namespace parser {
        class Visitor;
    }
}

namespace dem {
    namespace parser {
        class Visitable {
        public:
            virtual bool accept(Visitor &visitor) = 0;
        };
    }
}

#endif //DEMUSE_VISITABLE_H
