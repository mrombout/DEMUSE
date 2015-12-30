#include "symbol/play/Harmony.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Harmony::Harmony(const lexer::Token &token) :
                Playable(token) {

        }

        void Harmony::addNote(Expression *note) {
            mNotes.push_back(note);
        }

        bool Harmony::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                for(Expression *note : mNotes) {
                    note->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }

        const std::vector<Expression*> &Harmony::notes() const {
            return mNotes;
        }
    }
}
