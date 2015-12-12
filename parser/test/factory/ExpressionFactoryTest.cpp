#include <gtest/gtest.h>
#include <symbol/expression/UnaryExpression.h>
#include "PrintVisitor.h"
#include "factory/ExpressionFactory.h"
#include "symbol/Identifier.h"
#include "symbol/expression/MemberExpression.h"
#include "symbol/expression/NumberLiteral.h"
#include "symbol/expression/TextLiteral.h"
#include "symbol/expression/BoolLiteral.h"
#include "symbol/expression/StrictEqualCondition.h"
#include "symbol/expression/StrictNotEqualCondition.h"
#include "symbol/expression/ExponentExpression.h"
#include "symbol/expression/ArrayAccessExpression.h"
#include "symbol/expression/AdditionExpression.h"
#include "symbol/expression/SubtractionExpression.h"
#include "symbol/expression/MultiplicationExpression.h"
#include "symbol/expression/DivisionExpression.h"
#include "symbol/expression/ModuloExpression.h"
#include "symbol/expression/SmallerThanCondition.h"
#include "symbol/expression/SmallerThanOrEqualCondition.h"
#include "symbol/expression/AndCondition.h"
#include "symbol/expression/EqualCondition.h"
#include "symbol/expression/LargerThanCondition.h"
#include "symbol/expression/LargerThanOrEqualCondition.h"
#include "symbol/expression/NotEqualCondition.h"
#include "symbol/expression/OrCondition.h"
#include "symbol/expression/BinaryExpression.h"
#include "symbol/expression/CallExpression.h"


class ExpressionFactoryTest : public ::testing::Test {
protected:
    ExpressionFactoryTest() {

    }

    dem::parser::PrintVisitor printer;
    dem::lexer::TokenPosition tokenPosition;
};

TEST_F(ExpressionFactoryTest, ExpressionIdentifier) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "X", tokenPosition)
    };

    // act
    dem::parser::Identifier *identifier = dynamic_cast<dem::parser::Identifier*>(dem::parser::ExpressionFactory::produce(tokens));

    // assert
    printer.print(identifier);
    ASSERT_NE(nullptr, identifier);
}

TEST_F(ExpressionFactoryTest, ExpressionLiteralNumber) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition)
    };

    // act
    dem::parser::NumberLiteral *number = dynamic_cast<dem::parser::NumberLiteral*>(dem::parser::ExpressionFactory::produce(tokens));

    // assert
    printer.print(number);
    ASSERT_NE(nullptr, number);
    ASSERT_EQ(5, number->value());
}

TEST_F(ExpressionFactoryTest, ExpressionLiteralText) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::TEXT, "Lorum ipsum", tokenPosition)
    };

    // act
    dem::parser::TextLiteral *text = dynamic_cast<dem::parser::TextLiteral*>(dem::parser::ExpressionFactory::produce(tokens));

    // assert
    printer.print(text);
    ASSERT_NE(nullptr, text);
    ASSERT_EQ("Lorum ipsum", text->value());
}

TEST_F(ExpressionFactoryTest, ExpressionLiteralBool) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::BOOL, "true", tokenPosition)
    };

    // act
    dem::parser::BoolLiteral *boolean = dynamic_cast<dem::parser::BoolLiteral*>(dem::parser::ExpressionFactory::produce(tokens));

    // assert
    printer.print(boolean);
    ASSERT_NE(nullptr, boolean);
}

TEST_F(ExpressionFactoryTest, AdditionSingle) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,   "+", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::AdditionExpression *addExpression = dynamic_cast<dem::parser::AdditionExpression *>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, addExpression);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(addExpression->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(addExpression->right()));
}

TEST_F(ExpressionFactoryTest, AdditionMultiple) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "1", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,       "+", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "1", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,       "+", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "1", tokenPosition),
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::AdditionExpression *addExpression = dynamic_cast<dem::parser::AdditionExpression *>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, addExpression);
    ASSERT_NE(nullptr, dynamic_cast<dem::parser::AdditionExpression*>(&addExpression->left()));
    ASSERT_NE(nullptr, dynamic_cast<dem::parser::NumberLiteral*>(&addExpression->right()));
}

TEST_F(ExpressionFactoryTest, SubtractionSingle) {
    FAIL(); // TODO: Somehow this crashes everything

    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::MINUS,  "-", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::SubtractionExpression *subtractionExpression = dynamic_cast<dem::parser::SubtractionExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, subtractionExpression);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(subtractionExpression->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(subtractionExpression->right()));
}

TEST_F(ExpressionFactoryTest, SubtractionMultiple) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", dem::lexer::TokenPosition()),
        dem::lexer::Token(dem::lexer::TokenType::MINUS,  "-", dem::lexer::TokenPosition()),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", dem::lexer::TokenPosition()),
        dem::lexer::Token(dem::lexer::TokenType::MINUS,  "-", dem::lexer::TokenPosition()),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", dem::lexer::TokenPosition())
    };

    // act
    dem::parser::SubtractionExpression *subtractionExpression = dynamic_cast<dem::parser::SubtractionExpression*>(dem::parser::ExpressionFactory::produce(tokens));

    // assert
    printer.print(subtractionExpression);
    ASSERT_NE(nullptr, subtractionExpression);
    ASSERT_EQ(typeid(dem::parser::SubtractionExpression), typeid(subtractionExpression->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(subtractionExpression->right()));
}

TEST_F(ExpressionFactoryTest, MultiplicationSingle) {
    FAIL(); // TODO: Fix me, this crashes the rest
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TIMES,  "*", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::MultiplicationExpression *multiplicationExpression = dynamic_cast<dem::parser::MultiplicationExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, multiplicationExpression);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(multiplicationExpression->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(multiplicationExpression->right()));
}

TEST_F(ExpressionFactoryTest, MultiplicationMultiple) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "1", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TIMES,  "*", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "2", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TIMES,  "*", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "3", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::MultiplicationExpression *multiplicationExpression = dynamic_cast<dem::parser::MultiplicationExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, multiplicationExpression);
    ASSERT_EQ(typeid(dem::parser::MultiplicationExpression), typeid(multiplicationExpression->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(multiplicationExpression->right()));
}

TEST_F(ExpressionFactoryTest, DivisionSingle) {
    FAIL(); // TODO: Fix me, this crashes everything

    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "1", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::DIVIDE, "/", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "2", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::DivisionExpression *divisionExpression = dynamic_cast<dem::parser::DivisionExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, divisionExpression);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(divisionExpression->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(divisionExpression->right()));
}

TEST_F(ExpressionFactoryTest, DivisionMultiple) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "1", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::DIVIDE, "/", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "2", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::DIVIDE, "/", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "3", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::DivisionExpression *divisionExpression = dynamic_cast<dem::parser::DivisionExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, divisionExpression);
    ASSERT_EQ(typeid(dem::parser::DivisionExpression), typeid(divisionExpression->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(divisionExpression->right()));
}

TEST_F(ExpressionFactoryTest, ModuloSingle) {
    FAIL(); // TODO: Fix me, this crashes everything

    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "1", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::MOD,    "%", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "2", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::ModuloExpression *moduloExpression = dynamic_cast<dem::parser::ModuloExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, moduloExpression);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(moduloExpression->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(moduloExpression->right()));
}

TEST_F(ExpressionFactoryTest, ModuloMultiple) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "1", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::MOD,    "%", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "2", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::MOD,    "%", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "3", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::ModuloExpression *moduloExpression = dynamic_cast<dem::parser::ModuloExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, moduloExpression);
    ASSERT_EQ(typeid(dem::parser::ModuloExpression), typeid(moduloExpression->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(moduloExpression->right()));
}

TEST_F(ExpressionFactoryTest, ParenthesisSingle) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::OPEN,   "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "1", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,   "+", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "2", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,  ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TIMES,  "*", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "3", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);

    // assert
    printer.print(expression);
    ASSERT_TRUE(dynamic_cast<dem::parser::MultiplicationExpression*>(expression));
}

TEST_F(ExpressionFactoryTest, ConditionAnd) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::BOOL, "true", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::AND,  "&&",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BOOL, "false", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::AndCondition *andCondition = dynamic_cast<dem::parser::AndCondition*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, andCondition);
    ASSERT_EQ(typeid(dem::parser::BoolLiteral), typeid(andCondition->left()));
    ASSERT_EQ(typeid(dem::parser::BoolLiteral), typeid(andCondition->right()));
}

TEST_F(ExpressionFactoryTest, ConditionEqual) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::EQ,     "==", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::EqualCondition *equalCondition = dynamic_cast<dem::parser::EqualCondition*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, equalCondition);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(equalCondition->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(equalCondition->right()));
}

TEST_F(ExpressionFactoryTest, ConditionLargerThan) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::LR,     ">", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::LargerThanCondition *largerThanCondition = dynamic_cast<dem::parser::LargerThanCondition*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, largerThanCondition);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(largerThanCondition->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(largerThanCondition->right()));
}

TEST_F(ExpressionFactoryTest, ConditionLargerThanOrEqual) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::LREQ,   ">=", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::LargerThanOrEqualCondition *lreqCondition = dynamic_cast<dem::parser::LargerThanOrEqualCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, lreqCondition);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(lreqCondition->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(lreqCondition->right()));
}

TEST_F(ExpressionFactoryTest, ConditionNotEqual) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NEQ,    "!=", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::NotEqualCondition *notEqualCondition = dynamic_cast<dem::parser::NotEqualCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, notEqualCondition);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(notEqualCondition->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(notEqualCondition->right()));
}

TEST_F(ExpressionFactoryTest, ConditionOr) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OR,     "||", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::OrCondition *orCondition = dynamic_cast<dem::parser::OrCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, orCondition);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(orCondition->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(orCondition->right()));
}

TEST_F(ExpressionFactoryTest, ConditionSmallerThan) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::SM,     "<", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::SmallerThanCondition *smallerThanCondition = dynamic_cast<dem::parser::SmallerThanCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, smallerThanCondition);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(smallerThanCondition->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(smallerThanCondition->right()));
}

TEST_F(ExpressionFactoryTest, ConditionSmallerThanOrEqual) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::SMEQ,   "<=", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::SmallerThanOrEqualCondition *smallerThanOrEqualCondition = dynamic_cast<dem::parser::SmallerThanOrEqualCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, smallerThanOrEqualCondition);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(smallerThanOrEqualCondition->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(smallerThanOrEqualCondition->right()));
}

TEST_F(ExpressionFactoryTest, ConditionStrictEqual) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TEQ,    "===", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",   tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::StrictEqualCondition *strictEqualCondition = dynamic_cast<dem::parser::StrictEqualCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, strictEqualCondition);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(strictEqualCondition->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(strictEqualCondition->right()));
}


TEST_F(ExpressionFactoryTest, ConditionStrictNotEqual) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::TNEQ,   "!==", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",   tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::StrictNotEqualCondition *strictNotEqualCondition = dynamic_cast<dem::parser::StrictNotEqualCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, strictNotEqualCondition);
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(strictNotEqualCondition->left()));
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(strictNotEqualCondition->right()));
}

TEST_F(ExpressionFactoryTest, ExpressionCallNoArguments) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",  tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::CallExpression *callExpression = dynamic_cast<dem::parser::CallExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, callExpression);

    ASSERT_EQ(0, callExpression->arguments().size());

    dem::parser::Identifier* identifier = dynamic_cast<dem::parser::Identifier*>(&callExpression->callee());
    ASSERT_NE(nullptr, identifier);
    ASSERT_EQ("foo", identifier->name());
}

TEST_F(ExpressionFactoryTest, ExpressionCallSingleArgument) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "5",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",   tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::CallExpression *callExpression = dynamic_cast<dem::parser::CallExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, callExpression);

    ASSERT_EQ(1, callExpression->arguments().size());

    dem::parser::Identifier* identifier = dynamic_cast<dem::parser::Identifier*>(&callExpression->callee());
    ASSERT_NE(nullptr, identifier);
    ASSERT_EQ("foo", identifier->name());
}

TEST_F(ExpressionFactoryTest, ExpressionCallTwoArgument) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
            dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo", tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",   tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "1",   tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::COMMA,      ",",   tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "2",   tokenPosition),
            dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",   tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::CallExpression *callExpression = dynamic_cast<dem::parser::CallExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, callExpression);

    ASSERT_EQ(2, callExpression->arguments().size());

    dem::parser::Identifier* identifier = dynamic_cast<dem::parser::Identifier*>(&callExpression->callee());
    ASSERT_NE(nullptr, identifier);
    ASSERT_EQ("foo", identifier->name());
}

TEST_F(ExpressionFactoryTest, ExpressionMemberCallTwoArgument) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "bar", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::PERIOD,     ".",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "1",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::COMMA,      ",",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "2",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")",   tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::CallExpression *callExpression = dynamic_cast<dem::parser::CallExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, callExpression);

    ASSERT_EQ(2, callExpression->arguments().size());

    dem::parser::MemberExpression* memberExpression = dynamic_cast<dem::parser::MemberExpression*>(&callExpression->callee());
    ASSERT_NE(nullptr, memberExpression);

    dem::parser::Identifier *object = dynamic_cast<dem::parser::Identifier*>(&memberExpression->object());
    ASSERT_NE(nullptr, object);
    ASSERT_EQ("bar", object->name());

    dem::parser::Identifier *property = dynamic_cast<dem::parser::Identifier*>(&memberExpression->property());
    ASSERT_NE(nullptr, property);
    ASSERT_EQ("foo", property->name());
}

TEST_F(ExpressionFactoryTest, ExpressionArrayAccess) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER,    "foo", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BRACKET_OPEN,  "[",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,        "0",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BRACKET_CLOSE, "]",   tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::MemberExpression *memberExpression = dynamic_cast<dem::parser::MemberExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, memberExpression);
    ASSERT_NE(nullptr, dynamic_cast<dem::parser::Identifier*>(&memberExpression->object()));
    ASSERT_NE(nullptr, dynamic_cast<dem::parser::NumberLiteral*>(&memberExpression->property()));
}

TEST_F(ExpressionFactoryTest, ExpressionArrayAccessMulti) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER,    "foo", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BRACKET_OPEN,  "[",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,        "0",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BRACKET_CLOSE, "]",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BRACKET_OPEN,  "[",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,        "1",   tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::BRACKET_CLOSE, "]",   tokenPosition)
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::MemberExpression *memberExpression = dynamic_cast<dem::parser::MemberExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, memberExpression);
    ASSERT_NE(nullptr, dynamic_cast<dem::parser::MemberExpression*>(&memberExpression->object()));
    ASSERT_NE(nullptr, dynamic_cast<dem::parser::NumberLiteral*>(&memberExpression->property()));
}

TEST_F(ExpressionFactoryTest, UnaryNegativeLiteralSingle) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::MINUS,  "-", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "1", tokenPosition),
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::UnaryExpression *unaryExpression = dynamic_cast<dem::parser::UnaryExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, unaryExpression);

    dem::parser::NumberLiteral *numberLiteral = dynamic_cast<dem::parser::NumberLiteral*>(&unaryExpression->argument());
    ASSERT_NE(nullptr, numberLiteral);
    ASSERT_EQ(1, numberLiteral->value());
}

TEST_F(ExpressionFactoryTest, UnaryNegativeExpressionSingle) {
    // arrange
    std::deque<dem::lexer::Token> tokens = {
        dem::lexer::Token(dem::lexer::TokenType::MINUS,  "-", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "1", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,   "+", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "1", tokenPosition),
    };

    // act
    dem::parser::Expression *expression = dem::parser::ExpressionFactory::produce(tokens);
    dem::parser::AdditionExpression *additionExpression = dynamic_cast<dem::parser::AdditionExpression*>(expression);

    // assert
    printer.print(expression);
    ASSERT_NE(nullptr, additionExpression);

    ASSERT_NE(nullptr, dynamic_cast<dem::parser::UnaryExpression*>(&additionExpression->left()));
    ASSERT_NE(nullptr, dynamic_cast<dem::parser::NumberLiteral*>(&additionExpression->right()));
}


// TODO: Test nested expressions
// TODO: Test precedence of every operator
// TODO: Test associativity for every operator