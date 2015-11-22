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
    std::string str{"abcde"};

    std::string result = matcher.match(str.begin(), str.end(), tokens);

    ASSERT_EQ("abcd", result);
}

TEST_F(RegexMatcherTest, ReturnsEmptyWhenNoMatch) {
    std::string str{"bcdefa"};

    std::string result = matcher.match(str.begin(), str.end(), tokens);

    ASSERT_EQ("", result);
}

TEST_F(RegexMatcherTest, ReturnsEmptyWhenMatchNotAtBeginOfString) {
    std::string str{"dbabcd"};

    std::string result = matcher.match(str.begin(), str.end(), tokens);

    ASSERT_EQ("", result);
}

TEST_F(RegexMatcherTest, ReturnsEmptyWithEndIterator) {
    std::string str{"abcde"};

    std::string result = matcher.match(str.end(), str.end(), tokens);

    ASSERT_EQ("", result);
}