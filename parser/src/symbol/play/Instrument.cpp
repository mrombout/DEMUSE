#include <stdexcept>
#include "symbol/play/Instrument.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        Instrument::Instrument(Expression *instrumentExpression) :
            Playable(instrumentExpression->token()),
            mInstrumentExpression(instrumentExpression) {
            if(!mInstrumentExpression)
                throw std::invalid_argument("Argument 'instrumentExpression' may not be null.");
        }

        Expression &Instrument::instrumentExpression() {
            return *mInstrumentExpression;
        }

        bool Instrument::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mInstrumentExpression->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }
    }
}
