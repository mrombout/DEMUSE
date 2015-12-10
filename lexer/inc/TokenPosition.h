#ifndef DEMUSE_TOKENPOSITION_H
#define DEMUSE_TOKENPOSITION_H

namespace dem {
    namespace lexer {
        struct TokenPosition {
            TokenPosition();
            TokenPosition(unsigned int line, unsigned int column, unsigned int index);

            unsigned int line;
            unsigned int column;
            unsigned int index;
        };
    }
}

#endif //DEMUSE_TOKENPOSITION_H
