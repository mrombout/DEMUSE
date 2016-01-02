#include <iostream>
#include "symbol/Identifiable.h"
#include "exception/RuntimeException.h"
#include "ExpressionEvaluator.h"
#include "value/NumberValue.h"
#include "value/BooleanValue.h"
#include "value/TextValue.h"
#include "value/ArrayValue.h"
#include "value/NoteValue.h"
#include "value/function/FunctionValue.h"
#include "value/function/UserFunction.h"

namespace dem {
    namespace compiler {
        ExpressionEvaluator::ExpressionEvaluator(Compiler &compiler) :
            mCompiler(compiler) {

        }

        Value *ExpressionEvaluator::evaluate(ObjectValue *objectScope, parser::Expression &expression) {
            mObjectScope = objectScope;

            // evaluate
            expression.accept(*this);

            // get result
            Value *result = mStack.top();
            mStack.pop();

            std::clog << "Returning result " << result->asString() << std::endl;
            return result;
        }

        bool ExpressionEvaluator::visitEnter(parser::AssignmentExpression &assignmentExpression) {
            std::clog << "ENTER - Evaluating AssignmentExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::AssignmentExpression &assignmentExpression) {
            std::clog << "LEAVE - Evaluating AssignmentExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Variable *a = dynamic_cast<Variable*>(mStack.top());
            mStack.pop();

            if(!a) {
                throw RuntimeException("Lefthand value must be lvalue.");
            }

            // assign b to a
            std::clog << "ASSIGN - " << a->identifier()->name() << " = " << b->asString() << std::endl;
            a->setValue(b);

            mStack.push(a);

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::AdditionExpression &additionExpression) {
            std::clog << "ENTER - Evaluating AdditionExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::AdditionExpression &additionExpression) {
            std::clog << "LEAVE - Evaluating AdditionExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // add b to a
            try {
                std::clog << "Executing " << a->asString() << " + " << b->asString() << std::endl;
                Value *c = a->add(b);
                mStack.push(c);
            } catch(const RuntimeException &e) {
                throw RuntimeException(additionExpression.token(), e.what());
            }

            return false;
        }

        bool ExpressionEvaluator::visitEnter(parser::SubtractionExpression &subtractionExpression) {
            std::clog << "ENTER - Evaluating SubtractionExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::SubtractionExpression &subtractionExpression) {
            std::clog << "LEAVE - Evaluating SubtractionExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // subtract b from a
            try {
                std::clog << "Executing " << a->asString() << " - " << b->asString() << std::endl;
                Value *c = a->subtract(b);
                mStack.push(c);
            } catch(const RuntimeException &e) {
                throw RuntimeException(subtractionExpression.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::MultiplicationExpression &multiplicationExpression) {
            std::clog << "ENTER - Evaluating MultiplicationExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::MultiplicationExpression &multiplicationExpression) {
            std::clog << "LEAVE - Evaluating MultiplicationExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // multiply b by a
            try {
                std::clog << "Executing " << a->asString() << " * " << b->asString() << std::endl;
                Value *c = a->multiply(b);
                mStack.push(c);
            } catch(const RuntimeException &e) {
                throw RuntimeException(multiplicationExpression.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::DivisionExpression &divisionExpression) {
            std::clog << "ENTER - Evaluating DivisionExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::DivisionExpression &divisionExpression) {
            std::clog << "LEAVE - Evaluating DivisionExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // divide b by a
            try {
                std::clog << "Executing " << a->asString() << " / " << b->asString() << std::endl;
                Value *c = a->divide(b);
                mStack.push(c);
            } catch(const RuntimeException &e) {
                throw RuntimeException(divisionExpression.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::ModuloExpression &moduloExpression) {
            std::clog << "ENTER - Evaluating ModuloExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::ModuloExpression &moduloExpression) {
            std::clog << "LEAVE - Evaluating ModuloExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // divide b by a
            try {
                std::clog << "Executing " << a->asString() << " % " << b->asString() << std::endl;
                Value *c = a->modulo(b);
                mStack.push(c);
            } catch(const RuntimeException &e) {
                throw RuntimeException(moduloExpression.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::ExponentExpression &exponentExpression) {
            std::clog << "ENTER - Evaluating ExponentExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::ExponentExpression &exponentExpression) {
            std::clog << "LEAVE - Evaluating ExponentExpression" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // divide b by a
            try {
                std::clog << "Executing " << a->asString() << " ^ " << b->asString() << std::endl;
                Value *c = a->exponent(b);
                mStack.push(c);
            } catch(const RuntimeException &e) {
                throw RuntimeException(exponentExpression.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::EqualCondition &equalCondition) {
            std::clog << "ENTER - Evaluating EqualCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::EqualCondition &equalCondition) {
            std::clog << "LEAVE - Evaluating EqualCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare equality
            try {
                mStack.push(new BooleanValue(*a == *b));
            } catch(const RuntimeException &e) {
                throw RuntimeException(equalCondition.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::NotEqualCondition &notEqualCondition) {
            std::clog << "ENTER - Evaluating NotEqualCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::NotEqualCondition &notEqualCondition) {
            std::clog << "LEAVE - Evaluating NotEqualCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare not equal
            try {
                mStack.push(new BooleanValue(*a != *b));
            } catch(const RuntimeException &e) {
                throw RuntimeException(notEqualCondition.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::SmallerThanCondition &smallerThanCondition) {
            std::clog << "ENTER - Evaluating SmallerThanCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::SmallerThanCondition &smallerThanCondition) {
            std::clog << "LEAVE - Evaluating SmallerThanCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare smaller than
            try {
                mStack.push(new BooleanValue(*a < *b));
            } catch(const RuntimeException &e) {
                throw RuntimeException(smallerThanCondition.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition) {
            std::clog << "ENTER - Evaluating SmallerThanOrEqualCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition) {
            std::clog << "LEAVE - Evaluating SmallerThanOrEqualCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare smaller or equal than
            try {
                mStack.push(new BooleanValue(*a <= *b));
            } catch(const RuntimeException &e) {
                throw RuntimeException(smallerThanOrEqualCondition.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::LargerThanCondition &largerThanCondition) {
            std::clog << "ENTER - Evaluating LargerThanCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::LargerThanCondition &largerThanCondition) {
            std::clog << "LEAVE - Evaluating LargerThanCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare larger than
            try {
                mStack.push(new BooleanValue(*a > *b));
            } catch(const RuntimeException &e) {
                throw RuntimeException(largerThanCondition.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition) {
            std::clog << "ENTER - Evaluating LargerThanOrEqualCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition) {
            std::clog << "LEAVE - Evaluating LargerThanOrEqualCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare larger than or equal
            try {
                mStack.push(new BooleanValue(*a >= *b));
            } catch(const RuntimeException &e) {
                throw RuntimeException(largerThanOrEqualCondition.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::StrictEqualCondition &strictEqualCondition) {
            std::clog << "ENTER - Evaluating StrictEqualCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::StrictEqualCondition &strictEqualCondition) {
            std::clog << "LEAVE - Evaluating StrictEqualCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare larger than or equal
            try {
                mStack.push(new BooleanValue(a->strictEqual(*b)));
            } catch(const RuntimeException &e) {
                throw RuntimeException(strictEqualCondition.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::StrictNotEqualCondition &strictNotEqualCondition) {
            std::clog << "ENTER - Evaluating StrictEqualCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::StrictNotEqualCondition &strictNotEqualCondition) {
            std::clog << "LEAVE - Evaluating StrictEqualCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            // compare larger than or equal
            try {
                mStack.push(new BooleanValue(a->strictNotEqual(*b)));
            } catch(const RuntimeException &e) {
                throw RuntimeException(strictNotEqualCondition.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::AndCondition &andCondition) {
            std::clog << "ENTER - Evaluating AndCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::AndCondition &andCondition) {
            std::clog << "LEAVE - Evaluating AndCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            try {
                mStack.push(new BooleanValue(a->asBool() && b->asBool()));
            } catch(const RuntimeException &e) {
                throw RuntimeException(andCondition.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::OrCondition &orCondition) {
            std::clog << "ENTER - Evaluating OrCondition" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::OrCondition &orCondition) {
            std::clog << "LEAVE - Evaluating OrCondition" << std::endl;

            Value *b = mStack.top();
            mStack.pop();

            Value *a = mStack.top();
            mStack.pop();

            try {
                mStack.push(new BooleanValue(a->asBool() || b->asBool()));
            } catch(const RuntimeException &e) {
                throw RuntimeException(orCondition.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::ArrayLiteral &array) {
            std::clog << "ENTER - Evaluating Array" << std::endl;

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
            std::clog << "ENTER - Evaluating Identifier" << std::endl;

            Variable &variable = mObjectScope->variable(&identifier);

            std::clog << "(I)PUSH - " << variable.asString() << std::endl;
            mStack.push(&variable);

            return true;
        }


        bool ExpressionEvaluator::visit(parser::NumberLiteral &number) {
            std::clog << "ENTER - Evaluating Number" << std::endl;

            NumberValue *value = new NumberValue(number.value());

            std::clog << "PUSH - " << value->asString() << std::endl;
            mStack.push(value);

            return true;
        }

        bool ExpressionEvaluator::visit(parser::BoolLiteral &boolSymbol) {
            std::clog << "ENTER - Evaluating Bool" << std::endl;

            BooleanValue *value = new BooleanValue(boolSymbol.value());

            std::clog << "PUSH - " << value->asString() << std::endl;
            mStack.push(value);

            return true;
        }

        bool ExpressionEvaluator::visit(parser::TextLiteral &text) {
            std::clog << "ENTER - Evaluating Text" << std::endl;

            TextValue *value = new TextValue(text.value());

            std::clog << "PUSH - " << value->asString() << std::endl;
            mStack.push(value);

            return true;
        }
        
        bool ExpressionEvaluator::visit(parser::Note& note) {
            std::clog << "ENTER - Evaluating Note" << std::endl;

            NoteValue *value = new NoteValue(note);

            std::clog << "PUSH - " << value->asString() << std::endl;
            mStack.push(value);

            return true;
        }
        
        bool ExpressionEvaluator::visitEnter(parser::UnaryExpression &unaryExpression) {
            std::clog << "ENTER - UnaryExpression" << std::endl;

            // evaluate argument
            unaryExpression.argument().accept(*this);

            // take value
            Value *value = mStack.top();
            mStack.pop();

            // apply unary expression
            try {
                Value *newValue = nullptr;
                if(unaryExpression.op() == "+") {
                    newValue = new NumberValue(+(value->asNumber()));
                } else if(unaryExpression.op() == "-") {
                    newValue = new NumberValue(-(value->asNumber()));
                } else if(unaryExpression.op() == "!") {
                    newValue = new BooleanValue(!(value->asBool()));
                } else {
                    newValue = value;
                }

                mStack.push(newValue);
            } catch(const RuntimeException &e) {
                throw RuntimeException(unaryExpression.token(), e.what());
            }
            
            return false;
        }
        
        bool ExpressionEvaluator::visitLeave(parser::UnaryExpression &unaryExpression) {
            std::clog << "LEAVE - UnaryExpression" << std::endl;
            
            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::FunctionDefinition &functionDefinition) {
            std::clog << "ENTER - Evaluating FunctionDefinition" << std::endl;

            UserFunction *value = new UserFunction(mCompiler, mObjectScope, functionDefinition.parameterList(), functionDefinition.block());

            std::clog << "PUSH - " << value->asString() << std::endl;
            mStack.push(value);

            return false;
        }

        bool ExpressionEvaluator::visitEnter(parser::ArrayAccessExpression &arrayAccessExpression) {
            std::clog << "ENTER - Evaluating ArrayAccessExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::ArrayAccessExpression &arrayAccessExpression) {
            std::clog << "LEAVE - Evaluating ArrayAccessExpression" << std::endl;

            // array index
            Value *b = mStack.top();
            mStack.pop();

            // array
            Value *a = mStack.top();
            mStack.pop();

            try {
                static_cast<int>(b->asNumber());
                Value *value = (*a)[b->asNumber()];
                mStack.push(value);
            } catch(const RuntimeException &e) {
                throw RuntimeException(arrayAccessExpression.token(), e.what());
            }

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::CallExpression &callExpression) {
            std::clog << "ENTER - CallExpression" << std::endl;

            parser::Expression &calleeExpr = callExpression.callee();
            const std::vector<parser::Expression*> arguments = callExpression.arguments();

            try {
                // evaluate callee
                calleeExpr.accept(*this);
                Value *callee = mStack.top();
                mStack.pop();

                // evaluate arguments
                std::vector<Value*> argumentValues;
                for(parser::Expression *expr : arguments) {
                    Value *result = this->evaluate(mObjectScope, *expr);
                    argumentValues.push_back(result);
                }

                // map to function scope
                // TODO: Find a way to get rid of these casts
                FunctionValue *functionValue = dynamic_cast<FunctionValue*>(callee);
                if(!functionValue) {
                    Variable *variable = dynamic_cast<Variable*>(callee);
                    if(variable)
                        functionValue = dynamic_cast<FunctionValue*>(variable->value());
                }
                if(functionValue) {
                    functionValue->mapScope(argumentValues);
                }

                // call function
                mCompiler.scopes().push_front(functionValue);
                Value *result = (*callee)();
                mCompiler.scopes().pop_front();

                mStack.push(result);
            } catch(const RuntimeException &e) {
                throw RuntimeException(callExpression.token(), e.what());
            }

            return false;
        }

        bool ExpressionEvaluator::visitLeave(parser::CallExpression &callExpression) {
            std::clog << "LEAVE - CallExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::PropertyAccessExpression &propertyAccessExpression) {
            std::clog << "ENTER - PropertyAccessExpression" << std::endl;

            propertyAccessExpression.left().accept(*this);

            Value *a = mStack.top();
            mStack.pop();

            parser::Identifiable *identifiable = dynamic_cast<parser::Identifiable*>(&propertyAccessExpression.right());
            if(!identifiable)
                throw RuntimeException("Can not access property of object \"" + a->asString() + "\".");

            try {
                Value *value = (*a)[identifiable->name()];
                mStack.push(value);
            } catch(const RuntimeException &e) {
                throw RuntimeException(propertyAccessExpression.token(), e.what());
            }

            return false;
        }

        bool ExpressionEvaluator::visitLeave(parser::PropertyAccessExpression &propertyAccessExpression) {
            std::clog << "LEAVE - PropertyAccessExpression" << std::endl;

            // TODO: only call when not identifier
            parser::Identifier *identifier = dynamic_cast<parser::Identifier*>(&propertyAccessExpression.right());
            if(!identifier)
                propertyAccessExpression.right().accept(*this);

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::MemberExpression &memberExpression) {
            std::clog << "ENTER - MemberExpression" << std::endl;

            // evaluate object
            memberExpression.object().accept(*this);

            Value *object = mStack.top();
            mStack.pop();

            // evaluate property
            // TODO: Why must we cast? Can't we change MemberExpression to accept an Identifier
            dem::parser::Identifier *identifier = dynamic_cast<dem::parser::Identifier*>(&memberExpression.property());
            if(!identifier)
                throw RuntimeException("Can't access property of object \"" + object->asString() + "\".");

            // fetch property
            try {
                Variable *var = (*object)[identifier->name()];
                mStack.push(var);
            } catch(const RuntimeException &e) {
                throw RuntimeException(memberExpression.token(), e.what());
            }

            return false;
        }

        bool ExpressionEvaluator::visitLeave(parser::MemberExpression &memberExpression) {
            std::clog << "LEAVE - MemberExpression" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitEnter(parser::NewInstance &newInstance) {
            std::clog << "ENTER - NewInstance" << std::endl;

            return true;
        }

        bool ExpressionEvaluator::visitLeave(parser::NewInstance &newInstance) {
            std::clog << "LEAVE - NewInstance" << std::endl;

            Value *value = mStack.top();
            mStack.pop();

            ObjectValue *parentObject = dynamic_cast<ObjectValue*>(value);
            if(dynamic_cast<Variable*>(value)) {
                Variable *variable = dynamic_cast<Variable*>(value);
                parentObject = dynamic_cast<ObjectValue*>(variable->realValue());
            }
            if(parentObject == nullptr)
                throw RuntimeException(newInstance.token(), "Can't create a new instance, \"" + newInstance.identifier().name() + "\" is not an object.");

            mStack.push(new ObjectValue(parentObject));

            return false;
        }
    }
}
