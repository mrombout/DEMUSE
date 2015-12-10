#include <gtest/gtest.h>
#include "matcher/NullMatcher.h"
#include "Token.h"

class NullMatcherTest : public ::testing::Test {
protected:
    NullMatcherTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    std::vector<dem::lexer::Token> tokens;
    dem::lexer::NullMatcher matcher;
};

TEST_F(NullMatcherTest, MatchReturnsEmptyString) {
    // arrange
    std::string str{"foobar"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("", result);
}

TEST_F(NullMatcherTest, MatchReturnsEmptyStringWithEndIterator) {
    // arrange
    std::string str{"foobar"};

    auto end = str.end();

    // act
    std::string result = matcher.match(end, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("", result);
}