#include <gtest/gtest.h>
#include "matcher/CharMatcher.h"

class CharMatcherTest : public ::testing::Test {
protected:
    CharMatcherTest() :
        matcher('a') {

    }

    dem::lexer::CharMatcher matcher;
};

TEST_F(CharMatcherTest, ReturnsEmptyWhenNoMatch) {
    std::string str{"bcdefa"};

    std::string result = matcher.match(str.begin(), str.end());

    ASSERT_EQ("", result);
}

TEST_F(CharMatcherTest, ReturnsCharWhenMatch) {
    std::string str{"abcde"};

    std::string result = matcher.match(str.begin(), str.end());

    ASSERT_EQ("a", result);
}

TEST_F(CharMatcherTest, ReturnsEmptyWithEndIterator) {
    std::string str{"abcde"};

    std::string result = matcher.match(str.end(), str.end());

    ASSERT_EQ("", result);
}