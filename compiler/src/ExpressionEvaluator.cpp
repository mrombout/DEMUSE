#include <iostream>
#include "ExpressionEvaluator.h"
#include "value/NumberValue.h"

namespace dem {
    namespace compiler {
        ExpressionEvaluator::ExpressionEvaluator(Compiler &compiler) :
            mCompiler(compiler) {

        }

        Value *ExpressionEvaluator::evaluate(Scope *scope, parser::Expression &expression) {
            mScope = scope;

            // evaluate
            expression.accept(*this);

            // get result
            Value *result = mStack.top();
            while(!mStack.empty())
                mStack.pop();

            return result;
        }

        bool ExpressionEvaluator::visitEnter(parser::AssignmentExpression &assignmentExpression) {
            std::cout << "ENTER - Evaluating AssignmentExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::AssignmentExpression &assignmentExpression) {
            std::cout << "LEAVE - Evaluating AssignmentExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Variable *a = dynamic_cast<Variable*>(mStack.top());
            mStack.pop();

            if(!a) {
                throw "Lefthand value must be lvalue."; // TODO: Throw proper error
            }

            // assign b to a
            std::cout << "Assigning " << a->identifier()->name() << " = " << b->toString() << std::endl;
            a->setValue(b);

            mStack.push(a);

            return true;
        }

        bool ExpressionEvaluator::visit(parser::Identifier &identifier) {
            std::cout << "ENTER - Evaluating Identifier" << std::endl;

            Variable &variable = mScope->variable(&identifier);
            mStack.push(&variable);

            return true;
        }


        bool ExpressionEvaluator::visit(parser::Number &number) {
            std::cout << "ENTER - Evaluating Number" << std::endl;

            mStack.push(new NumberValue(number.value()));

            return true;
        }
    }
}
