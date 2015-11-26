#include <iostream>
#include "ExpressionEvaluator.h"
#include "value/NumberValue.h"
#include "value/BooleanValue.h"
#include "value/TextValue.h"

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
            std::cout << "Assigning " << a->identifier()->name() << " = " << b->asString() << std::endl;
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
            std::cout << "Executing " << a->asString() << " + " << b->asString() << std::endl;
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
            std::cout << "Executing " << a->asString() << " - " << b->asString() << std::endl;
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
            std::cout << "Executing " << a->asString() << " * " << b->asString() << std::endl;
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
            std::cout << "Executing " << a->asString() << " / " << b->asString() << std::endl;
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
            std::cout << "Executing " << a->asString() << " % " << b->asString() << std::endl;
            Value *c = a->modulo(b);
            mStack.push(c);

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::ExponentExpression &exponentExpression) {
            std::cout << "ENTER - Evaluating ExponentExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::ExponentExpression &exponentExpression) {
            std::cout << "LEAVE - Evaluating ExponentExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // divide b by a
            std::cout << "Executing " << a->asString() << " ^ " << b->asString() << std::endl;
            Value *c = a->exponent(b);
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

        bool ExpressionEvaluator::visitEnter(parser::NotEqualCondition &notEqualCondition) {
            std::cout << "ENTER - Evaluating NotEqualCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::NotEqualCondition &notEqualCondition) {
            std::cout << "LEAVE - Evaluating NotEqualCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare not equal
            mStack.push(new BooleanValue(*a != *b));

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::SmallerThanCondition &smallerThanCondition) {
            std::cout << "ENTER - Evaluating SmallerThanCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::SmallerThanCondition &smallerThanCondition) {
            std::cout << "LEAVE - Evaluating SmallerThanCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare smaller than
            mStack.push(new BooleanValue(*a < *b));

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition) {
            std::cout << "ENTER - Evaluating SmallerThanOrEqualCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition) {
            std::cout << "LEAVE - Evaluating SmallerThanOrEqualCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare smaller or equal than
            mStack.push(new BooleanValue(*a <= *b));

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::LargerThanCondition &largerThanCondition) {
            std::cout << "ENTER - Evaluating LargerThanCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::LargerThanCondition &largerThanCondition) {
            std::cout << "LEAVE - Evaluating LargerThanCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare larger than
            mStack.push(new BooleanValue(*a > *b));

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition) {
            std::cout << "ENTER - Evaluating LargerThanOrEqualCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition) {
            std::cout << "LEAVE - Evaluating LargerThanOrEqualCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare larger than or equal
            mStack.push(new BooleanValue(*a >= *b));

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::StrictEqualCondition &strictEqualCondition) {
            std::cout << "ENTER - Evaluating StrictEqualCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::StrictEqualCondition &strictEqualCondition) {
            std::cout << "LEAVE - Evaluating StrictEqualCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare larger than or equal
            mStack.push(new BooleanValue(a->strictEqual(*b)));

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::StrictNotEqualCondition &strictNotEqualCondition) {
            std::cout << "ENTER - Evaluating StrictEqualCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::StrictNotEqualCondition &strictNotEqualCondition) {
            std::cout << "LEAVE - Evaluating StrictEqualCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare larger than or equal
            mStack.push(new BooleanValue(a->strictNotEqual(*b)));

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::AndCondition &andCondition) {
            std::cout << "ENTER - Evaluating AndCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::AndCondition &andCondition) {
            std::cout << "LEAVE - Evaluating AndCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            mStack.push(new BooleanValue(a->asBool() && b->asBool()));

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::OrCondition &orCondition) {
            std::cout << "ENTER - Evaluating OrCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::OrCondition &orCondition) {
            std::cout << "LEAVE - Evaluating OrCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            mStack.push(new BooleanValue(a->asBool() || b->asBool()));

            return true;
        }

        bool ExpressionEvaluator::visit(parser::Identifier &identifier) {
            std::cout << "ENTER - Evaluating Identifier" << std::endl;

            Variable &variable = mScope->variable(&identifier);

            std::cout << "PUSH - " << variable.asString() << std::endl;
            mStack.push(&variable);

            return true;
        }


        bool ExpressionEvaluator::visit(parser::Number &number) {
            std::cout << "ENTER - Evaluating Number" << std::endl;

            NumberValue *value = new NumberValue(number.value());

            std::cout << "PUSH - " << value->asString() << std::endl;
            mStack.push(value);

            return true;
        }

        bool ExpressionEvaluator::visit(parser::Bool &boolSymbol) {
            std::cout << "ENTER - Evaluating Bool" << std::endl;

            BooleanValue *value = new BooleanValue(boolSymbol.value());

            std::cout << "PUSH - " << value->asString() << std::endl;
            mStack.push(value);

            return true;
        }

        bool ExpressionEvaluator::visit(parser::Text &text) {
            std::cout << "ENTER - Evaluating Text" << std::endl;

            TextValue *value = new TextValue(text.value());

            std::cout << "PUSH - " << value->asString() << std::endl;
            mStack.push(value);

            return true;
        }


        bool ExpressionEvaluator::visit(parser::FunctionCall &functionCall) {
            std::cout << "ENTER - Evaluating FunctionCall" << std::endl;

            // TODO: Function call with arguments

            Function &function = mScope->function(&functionCall.identifier());
            Value *value = function.execute(*mScope);

            std::cout << "PUSH - " << value->asString() << std::endl;
            mStack.push(value);

            return true;
        }
    }
}
