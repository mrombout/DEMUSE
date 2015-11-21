#ifndef DEMUSE_EXPRESSIONEVALUATOR_H
#define DEMUSE_EXPRESSIONEVALUATOR_H

#include <stack>
#include "Visitor.h"
#include "Compiler.h"
#include "value/Value.h"
#include "Scope.h"

namespace dem {
    namespace compiler {
        class ExpressionEvaluator : public parser::Visitor {
        public:
            ExpressionEvaluator(Compiler &compiler);

            Value *evaluate(Scope *scope, parser::Expression &expression);

            virtual bool visitEnter(parser::AssignmentExpression &assignmentExpression) override;
            virtual bool visitLeave(parser::AssignmentExpression &assignmentExpression) override;

            virtual bool visit(parser::Identifier &identifier) override;
            virtual bool visit(parser::Number &number) override;

        private:
            Compiler &mCompiler;

            std::stack<Value*> mStack;
            Scope *mScope;
        };
    }
}

#endif //DEMUSE_EXPRESSIONEVALUATOR_H
