#ifndef DEMUSE_INSTRUMENT_H
#define DEMUSE_INSTRUMENT_H

#include "Playable.h"

namespace dem {
    namespace parser {
        class Instrument : public Playable {
        public:
            Instrument(Expression *instrumentExpression);

            Expression *instrumentExpression();

            virtual bool accept(Visitor &visitor);

        private:
            Expression *mInstrumentExpression;
        };
    }
}

#endif //DEMUSE_INSTRUMENT_H
