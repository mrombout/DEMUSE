#include "symbol/play/Instrument.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Instrument::Instrument(Expression *instrumentExpression) :
            mInstrumentExpression(instrumentExpression) {

        }

        Expression *Instrument::instrumentExpression() {
            return mInstrumentExpression;
        }

        bool Instrument::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mInstrumentExpression->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
