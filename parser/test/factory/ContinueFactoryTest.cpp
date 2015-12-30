#include <gtest/gtest.h>
#include "factory/ContinueFactory.h"

class ContinueFactoryTest : public ::testing::Test {
protected:
    ContinueFactoryTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    dem::parser::ContinueFactory factory;

    dem::parser::ParseResults parseResults;
};

TEST_F(ContinueFactoryTest, SingleBreak) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::CONTINUE, "continue", tokenPosition),
    };

    // act / assert
    EXPECT_NO_THROW({
        dem::parser::Continue *continueSymbol = factory.produce(tokens, parseResults);
    });
}