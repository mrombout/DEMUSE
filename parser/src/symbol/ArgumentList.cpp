#include "symbol/ArgumentList.h"

namespace dem {
    namespace parser {
        ArgumentList::ArgumentList(std::vector<Expression*> arguments) :
                mArguments(arguments) {

        }

        std::vector<Expression *> &ArgumentList::arguments() {
            return mArguments;
        }

        int ArgumentList::numArguments() {
            return mArguments.size();
        }
    }
}
