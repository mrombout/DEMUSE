#ifndef DEMUSE_DEMUSEVISITOR_H
#define DEMUSE_DEMUSEVISITOR_H

namespace dem {
    namespace parser {
        class ArgumentList;
        class Assignment;
        class Block;
        class Bool;
        class Break;
        class Continue;
        class For;
        class FunctionDefinition;
        class Identifier;
        class If;
        class Number;
        class ParameterList;
        class Program;
        class Return;
        class Statement;
        class Symbol;
        class Text;
        class VariableDefinition;
        class While;
        class AdditionExpression;
        class AndCondition;
        class BinaryExpression;
        class Condition;
        class DivisionExpression;
        class EqualCondition;
        class Expression;
        class LargerThanCondition;
        class LargerThanOrEqualCondition;
        class ModuloExpression;
        class MultiplicationExpression;
        class NotEqualCondition;
        class OrCondition;
        class SmallerThanCondition;
        class SmallerThanOrEqualCondition;
        class StrictEqualCondition;
        class StrictNotEqualCondition;
        class SubtractionExpression;
    }
}

namespace dem {
    namespace parser {
        class Visitor {
        public:
            bool visitEnter(parser::ArgumentList &argumentList);
            bool visit(parser::ArgumentList &argumentList);
            bool visitLeave(parser::ArgumentList &argumentList);

            bool visitEnter(parser::Assignment &assignment);
            bool visit(parser::Assignment &assignment);
            bool visitLeave(parser::Assignment &assignment);

            bool visitEnter(parser::Block &block);
            bool visit(parser::Block &block);
            bool visitLeave(parser::Block &block);

            bool visit(parser::Bool &boolSymbol);

            bool visit(parser::Break &breakSymbol);

            bool visit(parser::Continue &continueSymbol);

            bool visitEnter(parser::For &forSymbol);
            bool visit(parser::For &forSymbol);
            bool visitLeave(parser::For &forSymbol);

            bool visitEnter(parser::FunctionDefinition &functionDefinition);
            bool visit(parser::FunctionDefinition &functionDefinition);
            bool visitLeave(parser::FunctionDefinition &functionDefinition);

            bool visit(parser::Identifier &identifier);

            bool visitEnter(parser::If &ifSymbol);
            bool visit(parser::If &ifSymbol);
            bool visitLeave(parser::If &ifSymbol);

            bool visit(parser::Number &number);

            bool visitEnter(parser::ParameterList &parameterList);
            bool visit(parser::ParameterList &parameterList);
            bool visitLeave(parser::ParameterList &parameterList);

            bool visitEnter(parser::Program &program);
            bool visit(parser::Program &program);
            bool visitLeave(parser::Program &program);

            bool visitEnter(parser::Return &returnSymbol);
            bool visit(parser::Return &returnSymbol);
            bool visitLeave(parser::Return &returnSymbol);

            bool visitEnter(parser::Statement &statement);
            bool visit(parser::Statement &statement);
            bool visitLeave(parser::Statement &statement);

            bool visitEnter(parser::Symbol &symbol);
            bool visit(parser::Symbol &symbol);
            bool visitLeave(parser::Symbol &symbol);

            bool visit(parser::Text &text);

            bool visitEnter(parser::VariableDefinition &variableDefinition);
            bool visit(parser::VariableDefinition &variableDefinition);
            bool visitLeave(parser::VariableDefinition &variableDefinition);

            bool visitEnter(parser::While &whileSymbol);
            bool visit(parser::While &whileSymbol);
            bool visitLeave(parser::While &whileSymbol);

            bool visitEnter(parser::AdditionExpression &additionExpression);
            bool visit(parser::AdditionExpression &additionExpression);
            bool visitLeave(parser::AdditionExpression &additionExpression);

            bool visitEnter(parser::AndCondition &andCondition);
            bool visit(parser::AndCondition &andCondition);
            bool visitLeave(parser::AndCondition &andCondition);

            bool visitEnter(parser::BinaryExpression &binaryExpression);
            bool visit(parser::BinaryExpression &binaryExpression);
            bool visitLeave(parser::BinaryExpression &binaryExpression);

            bool visitEnter(parser::Condition &condition);
            bool visit(parser::Condition &condition);
            bool visitLeave(parser::Condition &condition);

            bool visitEnter(parser::DivisionExpression &divisionExpression);
            bool visit(parser::DivisionExpression &divisionExpression);
            bool visitLeave(parser::DivisionExpression &divisionExpression);

            bool visitEnter(parser::EqualCondition &equalCondition);
            bool visit(parser::EqualCondition &equalCondition);
            bool visitLeave(parser::EqualCondition &equalCondition);

            bool visitEnter(parser::Expression &expression);
            bool visit(parser::Expression &expression);
            bool visitLeave(parser::Expression &expression);

            bool visitEnter(parser::LargerThanCondition &largerThanCondition);
            bool visit(parser::LargerThanCondition &largerThanCondition);
            bool visitLeave(parser::LargerThanCondition &largerThanCondition);

            bool visitEnter(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition);
            bool visit(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition);
            bool visitLeave(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition);

            bool visitEnter(parser::ModuloExpression &moduloExpression);
            bool visit(parser::ModuloExpression &moduloExpression);
            bool visitLeave(parser::ModuloExpression &moduloExpression);

            bool visitEnter(parser::MultiplicationExpression &multiplicationExpression);
            bool visit(parser::MultiplicationExpression &multiplicationExpression);
            bool visitLeave(parser::MultiplicationExpression &multiplicationExpression);

            bool visitEnter(parser::NotEqualCondition &notEqualCondition);
            bool visit(parser::NotEqualCondition &notEqualCondition);
            bool visitLeave(parser::NotEqualCondition &notEqualCondition);

            bool visitEnter(parser::OrCondition &orCondition);
            bool visit(parser::OrCondition &orCondition);
            bool visitLeave(parser::OrCondition &orCondition);

            bool visitEnter(parser::SmallerThanCondition &smallerThanCondition);
            bool visit(parser::SmallerThanCondition &smallerThanCondition);
            bool visitLeave(parser::SmallerThanCondition &smallerThanCondition);

            bool visitEnter(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition);
            bool visit(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition);
            bool visitLeave(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition);

            bool visitEnter(parser::StrictEqualCondition &strictEqualCondition);
            bool visit(parser::StrictEqualCondition &strictEqualCondition);
            bool visitLeave(parser::StrictEqualCondition &strictEqualCondition);

            bool visitEnter(parser::StrictNotEqualCondition &strictNotEqualCondition);
            bool visit(parser::StrictNotEqualCondition &strictNotEqualCondition);
            bool visitLeave(parser::StrictNotEqualCondition &strictNotEqualCondition);

            bool visitEnter(parser::SubtractionExpression &subtractionExpression);
            bool visit(parser::SubtractionExpression &subtractionExpression);
            bool visitLeave(parser::SubtractionExpression &subtractionExpression);
        };
    }
}

#endif //DEMUSE_DEMUSEVISITOR_H
