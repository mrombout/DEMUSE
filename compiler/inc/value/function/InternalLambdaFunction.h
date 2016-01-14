#ifndef DEMUSE_INTERNALLAMBDAFUNCTION_H
#define DEMUSE_INTERNALLAMBDAFUNCTION_H

#include <functional>
#include "InternalFunction.h"

namespace dem {
    namespace compiler {
        /**
         * \brief Similar to an InternalFunction this class uses a lambda as its function body
         */
        class InternalLambdaFunction;
        typedef std::function<Value*(InternalLambdaFunction &function, ObjectValue &scope)> FunctionBody;

        class InternalLambdaFunction : public InternalFunction {
        public:
            InternalLambdaFunction(ObjectValue *parent, FunctionBody body);

            virtual Value *operator()(ObjectValue &scope);

        private:
            FunctionBody mBody;
        };
    }
}

#endif //DEMUSE_INTERNALLAMBDAFUNCTION_H
