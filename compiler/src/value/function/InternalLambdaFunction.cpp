#include "value/function/InternalLambdaFunction.h"

namespace dem {
    namespace compiler {
        InternalLambdaFunction::InternalLambdaFunction(ObjectValue *parent, FunctionBody body) :
                InternalFunction(parent),
                mBody(body) {

        }

        Value *InternalLambdaFunction::operator()(ObjectValue &scope) {
            mBody(*this, scope);
        }
    }
}
