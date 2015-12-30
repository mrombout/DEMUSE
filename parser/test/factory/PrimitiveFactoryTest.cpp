#include <gtest/gtest.h>

/*
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
    dem::parser::BoolLiteral *boolean = dynamic_cast<dem::parser::BoolLiteral*>(factory.produce(tokens));

    // assert
    ASSERT_EQ(typeid(dem::parser::BoolLiteral), typeid(*boolean));
    ASSERT_EQ(true, boolean->value());
}

TEST_F(PrimitiveFactoryTest, Bool_False) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::BOOL, "false", tokenPosition),
    };

    // act
    dem::parser::BoolLiteral *boolean = dynamic_cast<dem::parser::BoolLiteral*>(factory.produce(tokens));

    // assert
    ASSERT_EQ(typeid(dem::parser::BoolLiteral), typeid(*boolean));
    ASSERT_FALSE(boolean->value());
}

TEST_F(PrimitiveFactoryTest, Text) {
    // arrange
    std::string content{"Lorum ipsum dolor sit amet."};
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::TEXT,     content, tokenPosition),
    };

    // act
    dem::parser::TextLiteral *text = dynamic_cast<dem::parser::TextLiteral*>(factory.produce(tokens));

    // assert
    ASSERT_EQ(typeid(dem::parser::TextLiteral), typeid(*text));
    ASSERT_EQ(content, text->value());
}

TEST_F(PrimitiveFactoryTest, Number_Integer) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", tokenPosition),
    };

    // act
    dem::parser::NumberLiteral *primitive = dynamic_cast<dem::parser::NumberLiteral*>(factory.produce(tokens));

    // assert
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(*primitive));
    ASSERT_EQ(5, primitive->value());
}

TEST_F(PrimitiveFactoryTest, Number_Float) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5.4", tokenPosition),
    };

    // act
    dem::parser::NumberLiteral *primitive = dynamic_cast<dem::parser::NumberLiteral*>(factory.produce(tokens));

    // assert
    ASSERT_EQ(typeid(dem::parser::NumberLiteral), typeid(*primitive));
    //ASSERT_EQ(5.4d, primitive->value());
    // TODO: Fix me
}

*/