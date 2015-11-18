#include <gtest/gtest.h>
#include "factory/ContinueFactory.h"

class ContinueFactoryTest : public ::testing::Test {
protected:
    ContinueFactoryTest() {

    }

    dem::parser::ContinueFactory factory;
};

TEST_F(ContinueFactoryTest, SingleBreak) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::CONTINUE, "continue", 0, 1, 1),
    };

    // act / assert
    EXPECT_NO_THROW({
        dem::parser::Continue *continueSymbol = factory.produce(tokens);
    });
}