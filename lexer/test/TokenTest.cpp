#include <gtest/gtest.h>
#include "Token.h"
#include "TokenType.h"

TEST(TokenTest, ConstructorInitializes) {
    dem::lexer::TokenPosition tokenPosition{1, 2, 3};
    dem::lexer::Token token{dem::lexer::TokenType::UNKNOWN, "foo", tokenPosition};
    ASSERT_EQ(dem::lexer::TokenType::UNKNOWN, token.type());
    ASSERT_EQ("foo", token.content());
    ASSERT_EQ(1, token.line());
    ASSERT_EQ(2, token.column());
    ASSERT_EQ(3, token.startIndex());
}