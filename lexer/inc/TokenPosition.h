#ifndef DEMUSE_TOKENPOSITION_H
#define DEMUSE_TOKENPOSITION_H

namespace dem {
    namespace lexer {
        struct TokenPosition {
            unsigned int line = 1;
            unsigned int column = 1;
            unsigned int index = 0;
        };
    }
}

#endif //DEMUSE_TOKENPOSITION_H
