#include <gtest/gtest.h>
#include "factory/ExpressionFactory.h"
#include "symbol/Identifier.h"
#include "symbol/Number.h"
#include "symbol/Text.h"
#include "symbol/Bool.h"

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

// TODO: Test nested expressions
// TODO: Test precedence of every operator
// TODO: Test associativity for every operator