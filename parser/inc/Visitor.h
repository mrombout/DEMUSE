#ifndef DEMUSE_DEMUSEVISITOR_H
#define DEMUSE_DEMUSEVISITOR_H

#include "symbol/NewInstance.h"
#include "symbol/ArgumentList.h"
#include "symbol/Assignment.h"
#include "symbol/Block.h"
#include "symbol/Break.h"
#include "symbol/Continue.h"
#include "symbol/For.h"
#include "symbol/expression/FunctionDefinition.h"
#include "symbol/Identifier.h"
#include "symbol/If.h"
#include "symbol/ParameterList.h"
#include "symbol/Program.h"
#include "symbol/Return.h"
#include "symbol/Statement.h"
#include "symbol/Symbol.h"
#include "symbol/Track.h"
#include "symbol/VariableDeclaration.h"
#include "symbol/While.h"
#include "symbol/expression/BoolLiteral.h"
#include "symbol/expression/NumberLiteral.h"
#include "symbol/expression/TextLiteral.h"
#include "symbol/expression/ArrayLiteral.h"
#include "symbol/expression/AdditionExpression.h"
#include "symbol/expression/AndCondition.h"
#include "symbol/expression/ArrayAccessExpression.h"
#include "symbol/expression/BinaryExpression.h"
#include "symbol/expression/Condition.h"
#include "symbol/expression/DivisionExpression.h"
#include "symbol/expression/EqualCondition.h"
#include "symbol/expression/Expression.h"
#include "symbol/expression/LargerThanCondition.h"
#include "symbol/expression/LargerThanOrEqualCondition.h"
#include "symbol/expression/ModuloExpression.h"
#include "symbol/expression/MultiplicationExpression.h"
#include "symbol/expression/ExponentExpression.h"
#include "symbol/expression/NotEqualCondition.h"
#include "symbol/expression/OrCondition.h"
#include "symbol/expression/SmallerThanCondition.h"
#include "symbol/expression/SmallerThanOrEqualCondition.h"
#include "symbol/expression/StrictEqualCondition.h"
#include "symbol/expression/StrictNotEqualCondition.h"
#include "symbol/expression/SubtractionExpression.h"
#include "symbol/expression/CallExpression.h"
#include "symbol/expression/MemberExpression.h"
#include "symbol/expression/UnaryExpression.h"
#include "symbol/expression/ExpressionStatement.h"
#include "symbol/expression/PropertyAccessExpression.h"
#include "symbol/expression/FunctionCallExpression.h"
#include "symbol/expression/AssignmentExpression.h"
#include "symbol/expression/ThisExpression.h"
#include "symbol/play/Play.h"
#include "symbol/play/Note.h"
#include "symbol/play/Harmony.h"
#include "symbol/play/Instrument.h"

namespace dem {
    namespace parser {
        class Visitor {
        public:
            virtual bool visitEnter(parser::ArgumentList &argumentList);
            virtual bool visitLeave(parser::ArgumentList &argumentList);

            virtual bool visitEnter(parser::ArrayLiteral &array);
            virtual bool visitLeave(parser::ArrayLiteral &array);

            virtual bool visitEnter(parser::Assignment &assignment);
            virtual bool visitLeave(parser::Assignment &assignment);

            virtual bool visitEnter(parser::ExpressionStatement &statement);
            virtual bool visitLeave(parser::ExpressionStatement &statement);

            virtual bool visitEnter(parser::Block &block);
            virtual bool visitLeave(parser::Block &block);

            virtual bool visit(parser::BoolLiteral &boolSymbol);

            virtual bool visit(parser::Break &breakSymbol);

            virtual bool visit(parser::Continue &continueSymbol);

            virtual bool visitEnter(parser::CallExpression &callExpression);
            virtual bool visitLeave(parser::CallExpression &callExpression);

            virtual bool visitEnter(parser::For &forSymbol);
            virtual bool visitLeave(parser::For &forSymbol);

            virtual bool visitEnter(parser::FunctionDefinition &functionDefinition);
            virtual bool visitLeave(parser::FunctionDefinition &functionDefinition);

            virtual bool visit(parser::Identifier &identifier);

            virtual bool visitEnter(parser::If &ifSymbol);

            virtual bool visitLeave(parser::If &ifSymbol);

            virtual bool visit(parser::NumberLiteral &number);

            virtual bool visitEnter(parser::ParameterList &parameterList);
            virtual bool visitLeave(parser::ParameterList &parameterList);

            virtual bool visitEnter(parser::Program &program);

            virtual bool visitLeave(parser::Program &program);

            virtual bool visitEnter(parser::Return &returnSymbol);
            virtual bool visitLeave(parser::Return &returnSymbol);

            virtual bool visitEnter(parser::Statement &statement);
            virtual bool visit(parser::Statement &statement);
            virtual bool visitLeave(parser::Statement &statement);

            virtual bool visitEnter(parser::Symbol &symbol);
            virtual bool visit(parser::Symbol &symbol);
            virtual bool visitLeave(parser::Symbol &symbol);

            virtual bool visit(parser::TextLiteral &text);

            virtual bool visitEnter(parser::Track &track);
            virtual bool visitLeave(parser::Track &track);

            virtual bool visitEnter(parser::VariableDeclaration &variableDefinition);
            virtual bool visitLeave(parser::VariableDeclaration &variableDefinition);

            virtual bool visitEnter(parser::While &whileSymbol);
            virtual bool visitLeave(parser::While &whileSymbol);

            virtual bool visitEnter(parser::AdditionExpression &additionExpression);
            virtual bool visitLeave(parser::AdditionExpression &additionExpression);

            virtual bool visitEnter(parser::AndCondition &andCondition);
            virtual bool visitLeave(parser::AndCondition &andCondition);

            virtual bool visitEnter(parser::ArrayAccessExpression &arrayAccessExpression);
            virtual bool visitLeave(parser::ArrayAccessExpression &arrayAccessExpression);

            virtual bool visitEnter(parser::AssignmentExpression &assignmentExpression);
            virtual bool visitLeave(parser::AssignmentExpression &assignmentExpression);

            virtual bool visitEnter(parser::Condition &condition);
            virtual bool visit(parser::Condition &condition);
            virtual bool visitLeave(parser::Condition &condition);

            virtual bool visitEnter(parser::DivisionExpression &divisionExpression);
            virtual bool visitLeave(parser::DivisionExpression &divisionExpression);

            virtual bool visitEnter(parser::EqualCondition &equalCondition);
            virtual bool visitLeave(parser::EqualCondition &equalCondition);

            virtual bool visitEnter(parser::ExponentExpression &exponentExpression);
            virtual bool visitLeave(parser::ExponentExpression &exponentExpression);

            virtual bool visitEnter(parser::Expression &expression);
            virtual bool visitLeave(parser::Expression &expression);

            virtual bool visitEnter(parser::LargerThanCondition &largerThanCondition);
            virtual bool visitLeave(parser::LargerThanCondition &largerThanCondition);

            virtual bool visitEnter(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition);
            virtual bool visitLeave(parser::LargerThanOrEqualCondition &largerThanOrEqualCondition);

            virtual bool visitEnter(parser::ModuloExpression &moduloExpression);
            virtual bool visitLeave(parser::ModuloExpression &moduloExpression);

            virtual bool visitEnter(parser::MultiplicationExpression &multiplicationExpression);
            virtual bool visitLeave(parser::MultiplicationExpression &multiplicationExpression);

            virtual bool visitEnter(parser::NotEqualCondition &notEqualCondition);
            virtual bool visitLeave(parser::NotEqualCondition &notEqualCondition);

            virtual bool visitEnter(parser::OrCondition &orCondition);
            virtual bool visitLeave(parser::OrCondition &orCondition);

            virtual bool visitEnter(parser::PropertyAccessExpression &propertyAccessExpression);
            virtual bool visitLeave(parser::PropertyAccessExpression &propertyAccessExpression1);

            virtual bool visitEnter(parser::SmallerThanCondition &smallerThanCondition);
            virtual bool visitLeave(parser::SmallerThanCondition &smallerThanCondition);

            virtual bool visitEnter(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition);
            virtual bool visitLeave(parser::SmallerThanOrEqualCondition &smallerThanOrEqualCondition);

            virtual bool visitEnter(parser::StrictEqualCondition &strictEqualCondition);
            virtual bool visitLeave(parser::StrictEqualCondition &strictEqualCondition);

            virtual bool visitEnter(parser::StrictNotEqualCondition &strictNotEqualCondition);
            virtual bool visitLeave(parser::StrictNotEqualCondition &strictNotEqualCondition);

            virtual bool visitEnter(parser::SubtractionExpression &subtractionExpression);
            virtual bool visitLeave(parser::SubtractionExpression &subtractionExpression);

            virtual bool visitEnter(parser::Play &play);
            virtual bool visitLeave(parser::Play &play);

            virtual bool visitEnter(parser::FunctionCallExpression &functionCallExpression);
            virtual bool visitLeave(parser::FunctionCallExpression &functionCallExpression);

            virtual bool visitEnter(parser::MemberExpression &memberExpression);
            virtual bool visitLeave(parser::MemberExpression &memberExpression);

            virtual bool visitEnter(parser::UnaryExpression &unaryExpression);
            virtual bool visitLeave(parser::UnaryExpression &unaryExpression);

            virtual bool visit(parser::Note &note);

            virtual bool visitEnter(parser::Harmony &harmony);
            virtual bool visitLeave(parser::Harmony &harmony);

            virtual bool visitEnter(parser::Instrument &instrument);
            virtual bool visitLeave(parser::Instrument &instrument);

            virtual bool visitEnter(parser::NewInstance &newInstance);
            virtual bool visitLeave(parser::NewInstance &newInstance);

            virtual bool visit(parser::ThisExpression &thisExpression);
        };
    }
}

#endif //DEMUSE_DEMUSEVISITOR_H
