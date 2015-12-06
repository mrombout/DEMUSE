#include <gtest/gtest.h>
#include "matcher/CharMatcher.h"

class CharMatcherTest : public ::testing::Test {
protected:
    CharMatcherTest() :
        matcher('a') {

    }

    dem::lexer::TokenPosition tokenPosition;
    std::vector<dem::lexer::Token> tokens;
    dem::lexer::CharMatcher matcher;
};

TEST_F(CharMatcherTest, ReturnsEmptyWhenNoMatch) {
    // arrange
    std::string str{"bcdefa"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("", result);
}

TEST_F(CharMatcherTest, ReturnsCharWhenMatch) {
    // arrange
    std::string str{"abcde"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("a", result);
}

TEST_F(CharMatcherTest, ReturnsEmptyWithEndIterator) {
    // arrange
    std::string str{"abcde"};

    auto end = str.end();

    // act
    std::string result = matcher.match(end, end, tokens, tokenPosition);

    // assert1
    ASSERT_EQ("", result);
}