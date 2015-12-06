#include <gtest/gtest.h>
#include "symbol/Number.h"
#include "symbol/Bool.h"
#include "symbol/Text.h"
#include "factory/PrimitiveFactory.h"
#include "Token.h"

class PrimitiveFactoryTest : public ::testing::Test {
protected:
    PrimitiveFactoryTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    dem::parser::PrimitiveFactory factory;
};

TEST_F(PrimitiveFactoryTest, Bool_True) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::BOOL, "true", tokenPosition),
    };

    // act
    dem::parser::Bool *boolean = dynamic_cast<dem::parser::Bool*>(factory.produce(tokens));

    // assert
    ASSERT_EQ(typeid(dem::parser::Bool), typeid(*boolean));
    ASSERT_EQ(true, boolean->value());
}

TEST_F(PrimitiveFactoryTest, Bool_False) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::BOOL, "false", tokenPosition),
    };

    // act
    dem::parser::Bool *boolean = dynamic_cast<dem::parser::Bool*>(factory.produce(tokens));

    // assert
    ASSERT_EQ(typeid(dem::parser::Bool), typeid(*boolean));
    ASSERT_FALSE(boolean->value());
}

TEST_F(PrimitiveFactoryTest, Text) {
    // arrange
    std::string content{"Lorum ipsum dolor sit amet."};
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::TEXT,     content, tokenPosition),
    };

    // act
    dem::parser::Text *text = dynamic_cast<dem::parser::Text*>(factory.produce(tokens));

    // assert
    ASSERT_EQ(typeid(dem::parser::Text), typeid(*text));
    ASSERT_EQ(content, text->value());
}

TEST_F(PrimitiveFactoryTest, Number_Integer) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition),
    };

    // act
    dem::parser::Number *primitive = dynamic_cast<dem::parser::Number*>(factory.produce(tokens));

    // assert
    ASSERT_EQ(typeid(dem::parser::Number), typeid(*primitive));
    ASSERT_EQ(5, primitive->value());
}

TEST_F(PrimitiveFactoryTest, Number_Float) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5.4", tokenPosition),
    };

    // act
    dem::parser::Number *primitive = dynamic_cast<dem::parser::Number*>(factory.produce(tokens));

    // assert
    ASSERT_EQ(typeid(dem::parser::Number), typeid(*primitive));
    ASSERT_EQ(5.4d, primitive->value());
}

