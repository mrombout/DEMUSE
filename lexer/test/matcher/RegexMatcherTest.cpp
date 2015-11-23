#include <gtest/gtest.h>
#include "matcher/RegexMatcher.h"

class RegexMatcherTest : public ::testing::Test {
protected:
    RegexMatcherTest() :
        matcher("abcd") {

    }

    std::vector<dem::lexer::Token> tokens;
    dem::lexer::RegexMatcher matcher;
};

TEST_F(RegexMatcherTest, ReturnsStringWhenMatch) {
    // arrange
    std::string str{"abcde"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens);

    // assert
    ASSERT_EQ("abcd", result);
}

TEST_F(RegexMatcherTest, ReturnsEmptyWhenNoMatch) {
    // arrange
    std::string str{"bcdefa"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens);

    // assert
    ASSERT_EQ("", result);
}

TEST_F(RegexMatcherTest, ReturnsEmptyWhenMatchNotAtBeginOfString) {
    // arrange
    std::string str{"dbabcd"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens);

    // assert
    ASSERT_EQ("", result);
}

TEST_F(RegexMatcherTest, ReturnsEmptyWithEndIterator) {
    // arrange
    std::string str{"abcde"};

    auto end = str.end();

    // act
    std::string result = matcher.match(end, end, tokens);

    // assert
    ASSERT_EQ("", result);
}