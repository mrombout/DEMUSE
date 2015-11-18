#include <gtest/gtest.h>
#include "factory/AssignmentFactory.h"

class AssignmentFactoryTest : public ::testing::Test {
protected:
    AssignmentFactoryTest() {

    }

    dem::parser::AssignmentFactory factory;
};

// TODO: Relies on ExpressionFactory, refactor so call to ExpressionFactory is no longer static

TEST_F(AssignmentFactoryTest, SimpleIdentifierAndPrimitiveValue) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "X", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::ASSIGNMENT, "=", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "1", 0, 0, 0),
    };

    // act
    dem::parser::Assignment *assignment = factory.produce(tokens);

    // assert
    ASSERT_EQ(typeid(dem::parser::Identifier), typeid(assignment->identifier()));
    ASSERT_EQ(typeid(dem::parser::Expression), typeid(assignment->expression()));
}

