#include "Visitor.h"

namespace dem {
    namespace parser {
        bool Visitor::visitEnter(ArgumentList &argumentList) { return true; }
        bool Visitor::visitLeave(ArgumentList &argumentList) { return true; }

        bool Visitor::visitEnter(ArrayLiteral &array) { return true; }
        bool Visitor::visitLeave(ArrayLiteral &array) { return true; }

        bool Visitor::visitEnter(Assignment &assignment) { return true; }
        bool Visitor::visitLeave(Assignment &assignment) { return true; }

        bool Visitor::visitEnter(Block &block) { return true; }
        bool Visitor::visitLeave(Block &block) { return true; }

        bool Visitor::visit(BoolLiteral &boolSymbol) { return true; }

        bool Visitor::visit(Break &breakSymbol) { return true; }

        bool Visitor::visit(Continue &continueSymbol) { return true; }

        bool Visitor::visitEnter(For &forSymbol) { return true; }
        bool Visitor::visitLeave(For &forSymbol) { return true; }

        bool Visitor::visitEnter(FunctionDefinition &functionDefinition) { return true; }
        bool Visitor::visitLeave(FunctionDefinition &functionDefinition) { return true; }

        bool Visitor::visit(Identifier &identifier) { return true; }

        bool Visitor::visitEnter(If &ifSymbol) { return true; }
        bool Visitor::visitLeave(If &ifSymbol) { return true; }

        bool Visitor::visit(NumberLiteral &number) { return true; }

        bool Visitor::visitEnter(ParameterList &parameterList) { return true; }
        bool Visitor::visitLeave(ParameterList &parameterList) { return true; }

        bool Visitor::visitEnter(Program &program) { return true; }
        bool Visitor::visitLeave(Program &program) { return true; }

        bool Visitor::visitEnter(Return &returnSymbol) { return true; }
        bool Visitor::visitLeave(Return &returnSymbol) { return true; }

        bool Visitor::visitEnter(Statement &statement) { return true; }
        bool Visitor::visit(Statement &statement) { return true; }
        bool Visitor::visitLeave(Statement &statement) { return true; }

        bool Visitor::visitEnter(Symbol &symbol) { return true; }
        bool Visitor::visit(Symbol &symbol) { return true; }
        bool Visitor::visitLeave(Symbol &symbol) { return true; }

        bool Visitor::visit(TextLiteral &text) { return true; }

        bool Visitor::visitEnter(parser::Track &track) { return true; }
        bool Visitor::visitLeave(parser::Track &track) { return true; }

        bool Visitor::visitEnter(VariableDeclaration &variableDefinition) { return true; }
        bool Visitor::visitLeave(VariableDeclaration &variableDefinition) { return true; }

        bool Visitor::visitEnter(While &whileSymbol) { return true; }
        bool Visitor::visitLeave(While &whileSymbol) { return true; }

        bool Visitor::visitEnter(AdditionExpression &additionExpression) { return true; }
        bool Visitor::visitLeave(AdditionExpression &additionExpression) { return true; }

        bool Visitor::visitEnter(AndCondition &andCondition) { return true; }
        bool Visitor::visitLeave(AndCondition &andCondition) { return true; }

        bool Visitor::visitEnter(ArrayAccessExpression &arrayAccessExpression) { return true; }
        bool Visitor::visitLeave(ArrayAccessExpression &arrayAccessExpression) { return true; }

        bool Visitor::visitEnter(AssignmentExpression &assignmentExpression) { return true; }
        bool Visitor::visitLeave(AssignmentExpression &assignmentExpression) { return true; }

        bool Visitor::visitEnter(Condition &condition) { return true; }
        bool Visitor::visit(Condition &condition) { return true; }
        bool Visitor::visitLeave(Condition &condition) { return true; }

        bool Visitor::visitEnter(DivisionExpression &divisionExpression) { return true; }
        bool Visitor::visitLeave(DivisionExpression &divisionExpression) { return true; }

        bool Visitor::visitEnter(EqualCondition &equalCondition) { return true; }
        bool Visitor::visitLeave(EqualCondition &equalCondition) { return true; }

        bool Visitor::visitEnter(parser::ExponentExpression &exponentExpression) { return true; }
        bool Visitor::visitLeave(parser::ExponentExpression &exponentExpression) { return true; }

        bool Visitor::visitEnter(Expression &expression) { return true; }
        bool Visitor::visitLeave(Expression &expression) { return true; }

        bool Visitor::visitEnter(LargerThanCondition &largerThanCondition) { return true; }
        bool Visitor::visitLeave(LargerThanCondition &largerThanCondition) { return true; }

        bool Visitor::visitEnter(LargerThanOrEqualCondition &largerThanOrEqualCondition) { return true; }
        bool Visitor::visitLeave(LargerThanOrEqualCondition &largerThanOrEqualCondition) { return true; }

        bool Visitor::visitEnter(ModuloExpression &moduloExpression) { return true; }
        bool Visitor::visitLeave(ModuloExpression &moduloExpression) { return true; }

        bool Visitor::visitEnter(MultiplicationExpression &multiplicationExpression) { return true; }
        bool Visitor::visitLeave(MultiplicationExpression &multiplicationExpression) { return true; }

        bool Visitor::visitEnter(NotEqualCondition &notEqualCondition) { return true; }
        bool Visitor::visitLeave(NotEqualCondition &notEqualCondition) { return true; }

        bool Visitor::visitEnter(OrCondition &orCondition) { return true; }
        bool Visitor::visitLeave(OrCondition &orCondition) { return true; }

        bool Visitor::visitEnter(PropertyAccessExpression &propertyAccessExpression) { return true; }
        bool Visitor::visitLeave(PropertyAccessExpression &propertyAccessExpression) { return true; }

        bool Visitor::visitEnter(SmallerThanCondition &smallerThanCondition) { return true; }
        bool Visitor::visitLeave(SmallerThanCondition &smallerThanCondition) { return true; }

        bool Visitor::visitEnter(SmallerThanOrEqualCondition &smallerThanOrEqualCondition) { return true; }
        bool Visitor::visitLeave(SmallerThanOrEqualCondition &smallerThanOrEqualCondition) { return true; }

        bool Visitor::visitEnter(StrictEqualCondition &strictEqualCondition) { return true; }
        bool Visitor::visitLeave(StrictEqualCondition &strictEqualCondition) { return true; }

        bool Visitor::visitEnter(StrictNotEqualCondition &strictNotEqualCondition) { return true; }
        bool Visitor::visitLeave(StrictNotEqualCondition &strictNotEqualCondition) { return true; }

        bool Visitor::visitEnter(SubtractionExpression &subtractionExpression) { return true; }
        bool Visitor::visitLeave(SubtractionExpression &subtractionExpression) { return true; }

        bool Visitor::visitEnter(parser::Play &play) { return true; }
        bool Visitor::visitLeave(parser::Play &play) { return true; }

        bool Visitor::visit(parser::Note &note) { return true; }

        bool Visitor::visitEnter(parser::FunctionCallExpression &functionCallExpression) { return true; }
        bool Visitor::visitLeave(parser::FunctionCallExpression &functionCallExpression) { return true; }

        bool Visitor::visitEnter(parser::CallExpression &callExpression) { return true; }
        bool Visitor::visitLeave(parser::CallExpression &callExpression) { return true; }

        bool Visitor::visitEnter(parser::MemberExpression &memberExpression) { return true; }
        bool Visitor::visitLeave(parser::MemberExpression &memberExpression) { return true; }

        bool Visitor::visitEnter(parser::UnaryExpression &unaryExpression) { return true; }
        bool Visitor::visitLeave(parser::UnaryExpression &unaryExpression) { return true; }

        bool Visitor::visitEnter(parser::ExpressionStatement &statement) { return true; }
        bool Visitor::visitLeave(parser::ExpressionStatement &statement) { return true; }

        bool Visitor::visitEnter(parser::Harmony &harmony) { return true; }
        bool Visitor::visitLeave(parser::Harmony &harmony) { return true; }

        bool Visitor::visitEnter(parser::Instrument &instrument) { return true; }
        bool Visitor::visitLeave(parser::Instrument &instrument) { return true; }

        bool Visitor::visitEnter(parser::NewInstance &newInstance) { return true; }
        bool Visitor::visitLeave(parser::NewInstance &newInstance) { return true; }
    }
}