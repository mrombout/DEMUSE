#ifndef DEMUSE_HARMONY_H
#define DEMUSE_HARMONY_H

#include <vector>
#include "symbol/Primitive.h"
#include "symbol/expression/Expression.h"
#include "Note.h"

namespace dem {
    namespace parser {
        class Harmony : public Playable {
        public:
            void addNote(Expression* note);
            const std::vector<Expression*> &notes() const;

            int duration() const;

            virtual bool accept(Visitor &visitor);

        private:
            std::vector<Expression*> mNotes;
        };
    }
}

#endif //DEMUSE_HARMONY_H
