#include <gtest/gtest.h>
#include "factory/BreakFactory.h"

class BreakFactoryTest : public ::testing::Test {
protected:
    BreakFactoryTest() {

    }

    dem::parser::BreakFactory factory;
};

TEST_F(BreakFactoryTest, SingleBreak) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::BREAK, "break", 0, 1, 1),
    };

    // act / assert
    EXPECT_NO_THROW({
        dem::parser::Break *breakSymbol = factory.produce(tokens);
    });
}