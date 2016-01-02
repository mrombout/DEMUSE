#ifndef DEMUSE_EXPRESSIONEVALUATOR_H
#define DEMUSE_EXPRESSIONEVALUATOR_H

#include <stack>
#include "Visitor.h"
#include "Compiler.h"
#include "value/Value.h"

namespace dem {
    namespace compiler {
        class ExpressionEvaluator : public parser::Visitor {
        public:
            ExpressionEvaluator(Compiler &compiler);

            Value *evaluate(ObjectValue *scope, parser::Expression &expression);

            virtual bool visitEnter(parser::AssignmentExpression &assignmentExpression) override;
            virtual bool visitLeave(parser::AssignmentExpression &assignmentExpression) override;

            virtual bool visitEnter(parser::AdditionExpression &additionExpression) override;
            virtual bool visitLeave(parser::AdditionExpression &additionExpression) override;

            virtual bool visitEnter(parser::SubtractionExpression &subtractionExpression) override;
            virtual bool visitLeave(parser::SubtractionExpression &subtractionExpression) override;

            virtual bool visitEnter(parser::MultiplicationExpression &multiplicationExpression) override;
            virtual bool visitLeave(parser::MultiplicationExpression &multiplicationExpression) override;

            virtual bool visitEnter(parser::DivisionExpression &divisionExpression) override;
            virtual bool visitLeave(parser::DivisionExpression &divisionExpression) override;

            virtual bool visitEnter(parser::ModuloExpression &moduloExpression) override;
            virtual bool visitLeave(parser::ModuloExpression &moduloExpression) override;

            virtual bool visitEnter(parser::ExponentExpression &exponentExpression) override;
            virtual bool visitLeave(parser::ExponentExpression &exponentExpression) override;

            virtual bool visitEnter(parser::EqualCondition &equalCondition) override;
            virtual bool visitLeave(parser::EqualCondition &equalCondition) override;

            virtual bool visitEnter(parser::NotEqualCondition &notEqualCondition) override;
            virtual bool visitLeave(parser::NotEqualCondition &notEqualCondition) override;

            virtual bool visitEnter(parser::SmallerThanCondition &smallerThanCondition) override;
            virtual bool visitLeave(parser::SmallerThanCondition &smallerThanCondition) override;

            virtual bool visitEnter(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition) override;
            virtual bool visitLeave(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition) override;

            virtual bool visitEnter(parser::LargerThanCondition &largerThanCondition) override;
            virtual bool visitLeave(parser::LargerThanCondition &largerThanCondition) override;

            virtual bool visitEnter(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition) override;
            virtual bool visitLeave(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition) override;

            virtual bool visitEnter(parser::StrictEqualCondition &strictEqualCondition) override;
            virtual bool visitLeave(parser::StrictEqualCondition &strictEqualCondition) override;

            virtual bool visitEnter(parser::StrictNotEqualCondition &strictNotEqualCondition) override;
            virtual bool visitLeave(parser::StrictNotEqualCondition &strictNotEqualCondition) override;

            virtual bool visitEnter(parser::AndCondition &andCondition) override;
            virtual bool visitLeave(parser::AndCondition &andCondition) override;

            virtual bool visitEnter(parser::OrCondition &orCondition) override;
            virtual bool visitLeave(parser::OrCondition &orCondition) override;

            virtual bool visitEnter(parser::ArrayLiteral &array) override;
            virtual bool visit(parser::Identifier &identifier) override;
            virtual bool visit(parser::NumberLiteral &number) override;
            virtual bool visit(parser::BoolLiteral &boolSymbol) override;
            virtual bool visit(parser::TextLiteral &text) override;
            virtual bool visit(parser::Note &note) override;
            virtual bool visitEnter(parser::UnaryExpression &unaryExpression) override;
            virtual bool visitLeave(parser::UnaryExpression &unaryExpression) override;
            virtual bool visitEnter(parser::FunctionDefinition &functionDefinition) override;

            virtual bool visitEnter(parser::ArrayAccessExpression &arrayAccessExpression);
            virtual bool visitLeave(parser::ArrayAccessExpression &arrayAccessExpression);

            virtual bool visitEnter(parser::CallExpression &continueSymbol) override;
            virtual bool visitLeave(parser::CallExpression &continueSymbol) override;

            virtual bool visitEnter(parser::PropertyAccessExpression &propertyAccessExpression) override;
            virtual bool visitLeave(parser::PropertyAccessExpression &propertyAccessExpression1) override;

            virtual bool visitEnter(parser::MemberExpression &memberExpression) override;
            virtual bool visitLeave(parser::MemberExpression &memberExpression) override;

            virtual bool visitEnter(parser::NewInstance &newInstance) override;
            virtual bool visitLeave(parser::NewInstance &newInstance) override;

        private:
            Compiler &mCompiler;

            std::stack<Value*> mStack;
            ObjectValue *mObjectScope;
        };
    }
}

#endif //DEMUSE_EXPRESSIONEVALUATOR_H
