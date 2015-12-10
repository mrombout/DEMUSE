#include <gtest/gtest.h>
#include "matcher/StringMatcher.h"

class StringMatcherTest : public ::testing::Test {
protected:
    StringMatcherTest() :
        matcher("abcd") {

    }

    dem::lexer::TokenPosition tokenPosition;
    std::vector<dem::lexer::Token> tokens;
    dem::lexer::StringMatcher matcher;
};

TEST_F(StringMatcherTest, ReturnsStringWhenMatch) {
    // arrange
    std::string str{"abcde"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("abcd", result);
}

TEST_F(StringMatcherTest, ReturnsEmptyWhenNoMatch) {
    // arrange
    std::string str{"bcdefa"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("", result);
}

TEST_F(StringMatcherTest, ReturnsEmptyWhenMatchNotAtBeginOfString) {
    // arrange
    std::string str{"dbabcd"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("", result);
}

TEST_F(StringMatcherTest, ReturnsEmptyWithEndIterator) {
    // arrange
    std::string str{"abcde"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(end, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("", result);
}