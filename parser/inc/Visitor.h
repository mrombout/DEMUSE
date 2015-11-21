#ifndef DEMUSE_DEMUSEVISITOR_H
#define DEMUSE_DEMUSEVISITOR_H

#include "symbol/expression/AssignmentExpression.h"
#include "symbol/ArgumentList.h"
#include "symbol/Assignment.h"
#include "symbol/Block.h"
#include "symbol/Bool.h"
#include "symbol/Break.h"
#include "symbol/Continue.h"
#include "symbol/For.h"
#include "symbol/FunctionDefinition.h"
#include "symbol/Identifier.h"
#include "symbol/If.h"
#include "symbol/Number.h"
#include "symbol/ParameterList.h"
#include "symbol/Program.h"
#include "symbol/Return.h"
#include "symbol/Statement.h"
#include "symbol/Symbol.h"
#include "symbol/Text.h"
#include "symbol/VariableDeclaration.h"
#include "symbol/While.h"
#include "symbol/expression/AdditionExpression.h"
#include "symbol/expression/AndCondition.h"
#include "symbol/expression/BinaryExpression.h"
#include "symbol/expression/Condition.h"
#include "symbol/expression/DivisionExpression.h"
#include "symbol/expression/EqualCondition.h"
#include "symbol/expression/Expression.h"
#include "symbol/expression/LargerThanCondition.h"
#include "symbol/expression/LargerThanOrEqualCondition.h"
#include "symbol/expression/ModuloExpression.h"
#include "symbol/expression/MultiplicationExpression.h"
#include "symbol/expression/NotEqualCondition.h"
#include "symbol/expression/OrCondition.h"
#include "symbol/expression/SmallerThanCondition.h"
#include "symbol/expression/SmallerThanOrEqualCondition.h"
#include "symbol/expression/StrictEqualCondition.h"
#include "symbol/expression/StrictNotEqualCondition.h"
#include "symbol/expression/SubtractionExpression.h"

namespace dem {
    namespace parser {
        class Visitor {
        public:
            bool visitEnter(parser::ArgumentList &argumentList);
            bool visitLeave(parser::ArgumentList &argumentList);

            bool visitEnter(parser::Assignment &assignment);
            bool visitLeave(parser::Assignment &assignment);

            virtual bool visitEnter(parser::Block &block);
            bool visitLeave(parser::Block &block);

            virtual bool visit(parser::Bool &boolSymbol);

            bool visit(parser::Break &breakSymbol);

            bool visit(parser::Continue &continueSymbol);

            bool visitEnter(parser::For &forSymbol);
            bool visitLeave(parser::For &forSymbol);

            virtual bool visitEnter(parser::FunctionDefinition &functionDefinition);
            bool visitLeave(parser::FunctionDefinition &functionDefinition);

            virtual bool visit(parser::Identifier &identifier);

            bool visitEnter(parser::If &ifSymbol);
            bool visitLeave(parser::If &ifSymbol);

            virtual bool visit(parser::Number &number);

            bool visitEnter(parser::ParameterList &parameterList);
            bool visitLeave(parser::ParameterList &parameterList);

            virtual bool visitEnter(parser::Program &program);

            virtual bool visitLeave(parser::Program &program);

            bool visitEnter(parser::Return &returnSymbol);
            bool visitLeave(parser::Return &returnSymbol);

            bool visitEnter(parser::Statement &statement);
            bool visit(parser::Statement &statement);
            bool visitLeave(parser::Statement &statement);

            bool visitEnter(parser::Symbol &symbol);
            bool visit(parser::Symbol &symbol);
            bool visitLeave(parser::Symbol &symbol);

            bool visit(parser::Text &text);

            virtual bool visitEnter(parser::VariableDeclaration &variableDefinition);
            bool visitLeave(parser::VariableDeclaration &variableDefinition);

            virtual bool visitEnter(parser::While &whileSymbol);
            bool visitLeave(parser::While &whileSymbol);

            virtual bool visitEnter(parser::AdditionExpression &additionExpression);

            virtual bool visitLeave(parser::AdditionExpression &additionExpression);

            bool visitEnter(parser::AndCondition &andCondition);
            bool visitLeave(parser::AndCondition &andCondition);

            virtual bool visitEnter(parser::AssignmentExpression &assignmentExpression);

            virtual bool visitLeave(parser::AssignmentExpression &assignmentExpression);

            bool visitEnter(parser::Condition &condition);
            bool visit(parser::Condition &condition);
            bool visitLeave(parser::Condition &condition);

            virtual bool visitEnter(parser::DivisionExpression &divisionExpression);

            virtual bool visitLeave(parser::DivisionExpression &divisionExpression);

            virtual bool visitEnter(parser::EqualCondition &equalCondition);

            virtual bool visitLeave(parser::EqualCondition &equalCondition);

            bool visitEnter(parser::Expression &expression);
            bool visit(parser::Expression &expression);
            bool visitLeave(parser::Expression &expression);

            bool visitEnter(parser::LargerThanCondition &largerThanCondition);
            bool visitLeave(parser::LargerThanCondition &largerThanCondition);

            bool visitEnter(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition);
            bool visitLeave(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition);

            virtual bool visitEnter(parser::ModuloExpression &moduloExpression);

            virtual bool visitLeave(parser::ModuloExpression &moduloExpression);

            virtual bool visitEnter(parser::MultiplicationExpression &multiplicationExpression);

            virtual bool visitLeave(parser::MultiplicationExpression &multiplicationExpression);

            bool visitEnter(parser::NotEqualCondition &notEqualCondition);
            bool visitLeave(parser::NotEqualCondition &notEqualCondition);

            bool visitEnter(parser::OrCondition &orCondition);
            bool visitLeave(parser::OrCondition &orCondition);

            bool visitEnter(parser::SmallerThanCondition &smallerThanCondition);
            bool visitLeave(parser::SmallerThanCondition &smallerThanCondition);

            bool visitEnter(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition);
            bool visitLeave(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition);

            bool visitEnter(parser::StrictEqualCondition &strictEqualCondition);
            bool visitLeave(parser::StrictEqualCondition &strictEqualCondition);

            bool visitEnter(parser::StrictNotEqualCondition &strictNotEqualCondition);
            bool visitLeave(parser::StrictNotEqualCondition &strictNotEqualCondition);

            virtual bool visitEnter(parser::SubtractionExpression &subtractionExpression);

            virtual bool visitLeave(parser::SubtractionExpression &subtractionExpression);
        };
    }
}

#endif //DEMUSE_DEMUSEVISITOR_H
