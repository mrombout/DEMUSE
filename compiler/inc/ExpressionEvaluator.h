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

            virtual bool visit(parser::Identifier &identifier) override;
            virtual bool visit(parser::Number &number) override;
            virtual bool visit(parser::Bool &boolSymbol) override;

        private:
            Compiler &mCompiler;

            std::stack<Value*> mStack;
            Scope *mScope;
        };
    }
}

#endif //DEMUSE_EXPRESSIONEVALUATOR_H
