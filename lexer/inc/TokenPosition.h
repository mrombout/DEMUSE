#ifndef DEMUSE_TOKENPOSITION_H
#define DEMUSE_TOKENPOSITION_H

namespace dem {
    namespace lexer {
        /**
         * \brief Contains the position of within a DEMUSE script.
         */
        struct TokenPosition {
            /**
             * \brief Constructs a new token position.
             */
            TokenPosition();

            /**
             * \brief Constructs a new token position.
             *
             * \param line   the line within the file, starting at 1
             * \param column the column within the file, starting at 1
             * \param index  the character index within the file, starting at 0
             */
            TokenPosition(unsigned int line, unsigned int column, unsigned int index);

            unsigned int line;
            unsigned int column;
            unsigned int index;
        };
    }
}

#endif //DEMUSE_TOKENPOSITION_H
