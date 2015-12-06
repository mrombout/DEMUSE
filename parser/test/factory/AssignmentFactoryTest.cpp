#include <gtest/gtest.h>
#include "factory/AssignmentFactory.h"
#include "symbol/Identifier.h"
#include "symbol/Assignment.h"

class AssignmentFactoryTest : public ::testing::Test {
protected:
    AssignmentFactoryTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    dem::parser::AssignmentFactory factory;
};

// TODO: Relies on ExpressionFactory, refactor so call to ExpressionFactory is no longer static

TEST_F(AssignmentFactoryTest, SimpleIdentifierAndPrimitiveValue) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "X", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::ASSIGNMENT, "=", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER,     "1", tokenPosition),
    };

    // act
    dem::parser::Assignment *assignment = factory.produce(tokens);

    // assert
    ASSERT_EQ(typeid(dem::parser::Identifier), typeid(assignment->identifier()));
    ASSERT_EQ(typeid(dem::parser::Expression), typeid(assignment->expression()));
}

