#include <iostream>
#include "exception/RuntimeException.h"
#include "ExpressionEvaluator.h"
#include "value/NumberValue.h"
#include "value/BooleanValue.h"
#include "value/TextValue.h"
#include "value/NullValue.h"
#include "value/ArrayValue.h"
#include "value/function/FunctionValue.h"
#include "value/function/UserFunction.h"
#include "value/Variable.h"

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

            std::cout << "Returning result " << result->asString() << std::endl;
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

        bool ExpressionEvaluator::visitEnter(parser::PropertyAccessExpression &propertyAccessExpression) {
            std::cout << "ENTER - Evaluating PropertyAccess" << std::endl;

            propertyAccessExpression.left().accept(*this);

            Value *a = mStack.top();
            mStack.pop();

            parser::Identifier *identifier = dynamic_cast<parser::Identifier*>(&propertyAccessExpression.right());
            if(!identifier)
                throw "Can not access property."; // TODO: Throw proper error

            Value *value = (*a)[identifier->name()];
            mStack.push(value);

            return false;
        }

        bool ExpressionEvaluator::visitLeave(parser::PropertyAccessExpression &propertyAccessExpression) {
            std::cout << "LEAVE - Evaluating PropertyAccess" << std::endl;
        }

        bool ExpressionEvaluator::visitEnter(parser::Array &array) {
            std::cout << "ENTER - Evaluating Array" << std::endl;

            std::vector<parser::Expression*> &expressions = array.expressions();
            std::vector<Value*> values;

            for(auto it = expressions.begin(); it != expressions.end(); ++it) {
                // evaluate, new value should be on the stack
                (*it)->accept(*this);

                // add to values
                values.push_back(mStack.top());
                mStack.pop();
            }

            mStack.push(new ArrayValue(values));

            return false;
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

        bool ExpressionEvaluator::visitEnter(parser::FunctionDefinition &functionDefinition) {
            std::cout << "ENTER - Evaluating FunctionDefinition" << std::endl;

            UserFunction *value = new UserFunction(mCompiler, functionDefinition.parameterList(), functionDefinition.block());

            std::cout << "PUSH - " << value->asString() << std::endl;
            mStack.push(value);

            return false;
        }

        bool ExpressionEvaluator::visit(parser::FunctionCall &functionCall) {
            std::cout << "ENTER - Evaluating FunctionCall" << std::endl;

            Variable &variable = mScope->variable(&functionCall.identifier());
            parser::ArgumentList *argumentList = functionCall.argumentList();

            // evaluate arguments
            std::vector<Value*> arguments;
            for(parser::Expression *expr : argumentList->arguments()) {
                std::cout << "evaling expr" << std::endl;
                Value *result = this->evaluate(mScope, *expr);
                arguments.push_back(result);
            }

            // map to function scope
            Scope functionScope(mScope);
            if(FunctionValue *functionValue = dynamic_cast<FunctionValue*>(variable.value())) {
                functionValue->mapScope(functionScope, arguments);
            }
            mCompiler.scopes().push_front(&functionScope);

            // call function
            Value *value = variable(functionScope);
            mCompiler.scopes().pop_front();

            if(!dynamic_cast<NullValue*>(value))
                std::cout << "PUSH - " << value->asString() << std::endl;
            mStack.push(value);

            return false;
        }

        bool ExpressionEvaluator::visitLeave(parser::ArrayAccessExpression &arrayAccessExpression) {
            std::cout << "LEAVE - Evaluating ArrayAccessExpression" << std::endl;

            // array index
            Value *b = mStack.top();
            mStack.pop();

            // array
            Value *a = mStack.top();
            mStack.pop();

            static_cast<int>(b->asNumber());
            Value *value = (*a)[b->asNumber()];
            mStack.push(value);

            return true;
        }
    }
}
