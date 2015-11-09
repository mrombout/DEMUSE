#include <gtest/gtest.h>
#include "Token.h"
#include "TokenType.h"

TEST(TokenTest, ConstructorInitializes) {
    dem::lexer::Token token{dem::lexer::TokenType::UNKNOWN, "foo", 1, 2, 3};
    ASSERT_EQ(dem::lexer::TokenType::UNKNOWN, token.type());
    ASSERT_EQ("foo", token.content());
    ASSERT_EQ(1, token.startIndex());
    ASSERT_EQ(2, token.line());
    ASSERT_EQ(3, token.column());
}