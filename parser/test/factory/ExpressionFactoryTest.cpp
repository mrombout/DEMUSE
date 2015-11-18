#include <gtest/gtest.h>
#include "factory/ExpressionFactory.h"
#include "symbol/Identifier.h"
#include "symbol/Number.h"
#include "symbol/Text.h"
#include "symbol/Bool.h"
#include "symbol/expression/AddExpression.h"
#include "symbol/expression/SubtractionExpression.h"
#include "symbol/expression/MultiplicationExpression.h"
#include "symbol/expression/DivisionExpression.h"
#include "symbol/expression/ModuloExpression.h"

class ExpressionFactoryTest : public ::testing::Test {
protected:
    ExpressionFactoryTest() {

    }

    dem::parser::ExpressionFactory *factory;
};

/*
TEST_F(ExpressionFactoryTest, SingleIdentifierExpression) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "X", 0, 0, 0)
    };

    // act
    dem::parser::Identifier *identifier = dynamic_cast<dem::parser::Identifier*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, identifier);
}
*/

TEST_F(ExpressionFactoryTest, SingleNumberPrimitiveExpression) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Number *number = dynamic_cast<dem::parser::Number*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, number);
    ASSERT_EQ("5", number->value());
}

TEST_F(ExpressionFactoryTest, SingleTextPrimitiveExpression) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::TEXT, "Lorum ipsum", 0, 0, 0)
    };

    // act
    dem::parser::Text *text = dynamic_cast<dem::parser::Text*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, text);
}

TEST_F(ExpressionFactoryTest, SingleBoolPrimitiveExpression) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::BOOL, "true", 0, 0, 0)
    };

    // act
    dem::parser::Bool *boolean = dynamic_cast<dem::parser::Bool*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, boolean);
}

TEST_F(ExpressionFactoryTest, SingleAddition) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,   "+", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::AddExpression *addExpression = dynamic_cast<dem::parser::AddExpression*>(expression);

    // assert
    ASSERT_NE(nullptr, addExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(addExpression->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(addExpression->right()));
}

TEST_F(ExpressionFactoryTest, SingleSubtraction) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::MINUS,  "-", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::SubtractionExpression *subtractionExpression = dynamic_cast<dem::parser::SubtractionExpression*>(expression);

    // assert
    ASSERT_NE(nullptr, subtractionExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(subtractionExpression->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(subtractionExpression->right()));
}

TEST_F(ExpressionFactoryTest, SingleMultiplication) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TIMES,  "*", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::MultiplicationExpression *multiplicationExpression = dynamic_cast<dem::parser::MultiplicationExpression*>(expression);

    // assert
    ASSERT_NE(nullptr, multiplicationExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(multiplicationExpression->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(multiplicationExpression->right()));
}

TEST_F(ExpressionFactoryTest, SingleDivision) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::DIVIDE, "/", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::DivisionExpression *divisionExpression = dynamic_cast<dem::parser::DivisionExpression*>(expression);

    // assert
    ASSERT_NE(nullptr, divisionExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(divisionExpression->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(divisionExpression->right()));
}


TEST_F(ExpressionFactoryTest, SingleModuloOperation) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::MOD,    "%", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::ModuloExpression *moduloExpression = dynamic_cast<dem::parser::ModuloExpression*>(expression);

    // assert
    ASSERT_NE(nullptr, moduloExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(moduloExpression->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(moduloExpression->right()));
}

// TODO: Test nested expressions
// TODO: Test precedence of every operator
// TODO: Test associativity for every operator