#ifndef DEMUSE_PRINTVISITOR_H
#define DEMUSE_PRINTVISITOR_H

#include "Visitor.h"

namespace dem {
    namespace parser {
        class PrintVisitor : public Visitor {
        public:
            PrintVisitor();

            void print(Symbol *symbol);

            virtual bool visitEnter(parser::AdditionExpression &additionExpression) override;
            virtual bool visitEnter(parser::SubtractionExpression &subtractionExpression) override;
            virtual bool visitEnter(parser::MultiplicationExpression &multiplicationExpression) override;
            virtual bool visitEnter(parser::DivisionExpression &divisionExpression) override;
            virtual bool visitEnter(parser::ModuloExpression &moduloExpression) override;

            virtual bool visitEnter(parser::AndCondition &andCondition) override;
            virtual bool visitEnter(parser::EqualCondition &equalCondition) override;
            virtual bool visitEnter(parser::LargerThanCondition &largerThanCondition) override;
            virtual bool visitEnter(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition) override;
            virtual bool visitEnter(parser::NotEqualCondition &notEqualCondition) override;
            virtual bool visitEnter(parser::SmallerThanCondition &smallerThanCondition) override;
            virtual bool visitEnter(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition) override;
            virtual bool visitEnter(parser::StrictEqualCondition &strictEqualCondition) override;
            virtual bool visitEnter(parser::StrictNotEqualCondition &strictNotEqualCondition) override;

            virtual bool visitEnter(parser::CallExpression &continueSymbol) override;
            virtual bool visitEnter(parser::MemberExpression &memberExpression) override;
            virtual bool visitEnter(parser::UnaryExpression &unaryExpression) override;

            virtual bool visit(parser::Identifier &identifier) override;
            virtual bool visit(parser::NumberLiteral &number) override;
            virtual bool visit(parser::TextLiteral &text) override;
            virtual bool visit(parser::BoolLiteral &boolSymbol) override;

        private:
            int mIndentation;
        };
    }
}

#endif //DEMUSE_PRINTVISITOR_H
