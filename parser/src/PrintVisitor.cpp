#include <iostream>
#include "PrintVisitor.h"

namespace dem {
    namespace parser {
        PrintVisitor::PrintVisitor() :
            mIndentation(0) {

        }

        void PrintVisitor::print(Symbol *symbol) {
            std::cout << std::endl;
            symbol->accept(*this);
        }

        bool PrintVisitor::visitEnter(parser::AdditionExpression &additionExpression) {
            std::cout << std::string(mIndentation, '\t') << "- type: AdditionExpression" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: +" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            additionExpression.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            additionExpression.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::SubtractionExpression &subtractionExpression) {
            std::cout << std::string(mIndentation, '\t') << "- type: SubtractionExpression" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: -" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            subtractionExpression.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            subtractionExpression.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::MultiplicationExpression &multiplicationExpression) {
            std::cout << std::string(mIndentation, '\t') << "- type: MultiplicationExpression" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: *" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            multiplicationExpression.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            multiplicationExpression.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::DivisionExpression &divisionExpression) {
            std::cout << std::string(mIndentation, '\t') << "- type: DivisionExpression" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: /" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            divisionExpression.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            divisionExpression.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::ModuloExpression &moduloExpression) {
            std::cout << std::string(mIndentation, '\t') << "- type: ModuloExpression" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: %" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            moduloExpression.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            moduloExpression.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::AndCondition &andCondition) {
            std::cout << std::string(mIndentation, '\t') << "- type: ModuloExpression" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: &&" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            andCondition.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            andCondition.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::EqualCondition &equalCondition) {
            std::cout << std::string(mIndentation, '\t') << "- type: EqualCondition" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: ==" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            equalCondition.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            equalCondition.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::LargerThanCondition &largerThanCondition) {
            std::cout << std::string(mIndentation, '\t') << "- type: LargerThanCondition" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: >" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            largerThanCondition.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            largerThanCondition.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition) {
            std::cout << std::string(mIndentation, '\t') << "- type: LargerThanOrEqualCondition" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: >=" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            largerThanOrEqualCondition.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            largerThanOrEqualCondition.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::NotEqualCondition &notEqualCondition) {
            std::cout << std::string(mIndentation, '\t') << "- type: NotEqualCondition" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: !=" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            notEqualCondition.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            notEqualCondition.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::SmallerThanCondition &smallerThanCondition) {
            std::cout << std::string(mIndentation, '\t') << "- type: SmallerThanCondition" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: <" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            smallerThanCondition.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            smallerThanCondition.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition) {
            std::cout << std::string(mIndentation, '\t') << "- type: SmallerThanOrEqualCondition" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: <=" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            smallerThanOrEqualCondition.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            smallerThanOrEqualCondition.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::StrictEqualCondition &strictEqualCondition) {
            std::cout << std::string(mIndentation, '\t') << "- type: StrictEqualCondition" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: ===" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            strictEqualCondition.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            strictEqualCondition.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::StrictNotEqualCondition &strictNotEqualCondition) {
            std::cout << std::string(mIndentation, '\t') << "- type: StrictNotEqualCondition" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: !==" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- left: " << std::endl;
            ++mIndentation;
            strictNotEqualCondition.left().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            strictNotEqualCondition.right().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::CallExpression &continueSymbol) {
            std::cout << std::string(mIndentation, '\t') << "- type: CallExpression" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- arguments: " << std::endl;
            ++mIndentation;
            for(Expression *expression : continueSymbol.arguments()) {
                expression->accept(*this);
            }
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- right: " << std::endl;
            ++mIndentation;
            continueSymbol.callee().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::MemberExpression &memberExpression) {
            std::cout << std::string(mIndentation, '\t') << "- type: MemberExpression" << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- object: " << std::endl;
            ++mIndentation;
            memberExpression.object().accept(*this);
            --mIndentation;

            std::cout << std::string(mIndentation, '\t') << "- property: " << std::endl;
            ++mIndentation;
            memberExpression.property().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visitEnter(parser::UnaryExpression &unaryExpression) {
            std::cout << std::string(mIndentation, '\t') << "- type: UnaryExpression" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- operator: " << unaryExpression.op() << std::endl;

            std::cout << std::string(mIndentation, '\t') << "- argument: " << std::endl;
            ++mIndentation;
            unaryExpression.argument().accept(*this);
            --mIndentation;

            return false;
        }

        bool PrintVisitor::visit(parser::Identifier &identifier) {
            std::cout << std::string(mIndentation, '\t') << "- type: Identifier" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- name: " << identifier.name() << std::endl;

            return true;
        }

        bool PrintVisitor::visit(parser::NumberLiteral &number) {
            std::cout << std::string(mIndentation, '\t') << "- type: NumberLiteral" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- value: " << number.value() << std::endl;

            return true;
        }

        bool PrintVisitor::visit(parser::TextLiteral &text) {
            std::cout << std::string(mIndentation, '\t') << "- type: TextLiteral" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- value: " << text.value() << std::endl;

            return true;
        }

        bool PrintVisitor::visit(parser::BoolLiteral &boolSymbol) {
            std::cout << std::string(mIndentation, '\t') << "- type: BoolLiteral" << std::endl;
            std::cout << std::string(mIndentation, '\t') << "- value: " << boolSymbol.value() << std::endl;

            return true;
        }
    }
}
