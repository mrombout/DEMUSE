#include <iostream>
#include "ExpressionEvaluator.h"
#include "value/NumberValue.h"
#include "value/BooleanValue.h"

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

        bool ExpressionEvaluator::visitEnter(parser::AdditionExpression &additionExpression) {
            std::cout << "ENTER - Evaluating AdditionExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::AdditionExpression &additionExpression) {
            std::cout << "LEAVE - Evaluating AdditionExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // add b to a
            std::cout << "Executing " << a->toString() << " + " << b->toString() << std::endl;
            Value *c = a->add(b);
            mStack.push(c);
        }

        bool ExpressionEvaluator::visitEnter(parser::SubtractionExpression &subtractionExpression) {
            std::cout << "ENTER - Evaluating SubtractionExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::SubtractionExpression &subtractionExpression) {
            std::cout << "LEAVE - Evaluating SubtractionExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // subtract b from a
            std::cout << "Executing " << a->toString() << " - " << b->toString() << std::endl;
            Value *c = a->subtract(b);
            mStack.push(c);

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::MultiplicationExpression &multiplicationExpression) {
            std::cout << "ENTER - Evaluating MultiplicationExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::MultiplicationExpression &multiplicationExpression) {
            std::cout << "LEAVE - Evaluating MultiplicationExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // multiply b by a
            std::cout << "Executing " << a->toString() << " * " << b->toString() << std::endl;
            Value *c = a->multiply(b);
            mStack.push(c);

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::DivisionExpression &divisionExpression) {
            std::cout << "ENTER - Evaluating DivisionExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::DivisionExpression &divisionExpression) {
            std::cout << "LEAVE - Evaluating DivisionExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // divide b by a
            std::cout << "Executing " << a->toString() << " / " << b->toString() << std::endl;
            Value *c = a->divide(b);
            mStack.push(c);

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::ModuloExpression &moduloExpression) {
            std::cout << "ENTER - Evaluating ModuloExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::ModuloExpression &moduloExpression) {
            std::cout << "LEAVE - Evaluating ModuloExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // divide b by a
            std::cout << "Executing " << a->toString() << " % " << b->toString() << std::endl;
            Value *c = a->modulo(b);
            mStack.push(c);

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::EqualCondition &equalCondition) {
            std::cout << "ENTER - Evaluating EqualCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::EqualCondition &equalCondition) {
            std::cout << "LEAVE - Evaluating EqualCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare equality
            mStack.push(new BooleanValue(*a == *b));

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

        bool ExpressionEvaluator::visit(parser::Bool &boolSymbol) {
            std::cout << "ENTER - Evaluating Bool" << std::endl;

            mStack.push(new BooleanValue(boolSymbol.value()));

            return true;
        }
    }
}
