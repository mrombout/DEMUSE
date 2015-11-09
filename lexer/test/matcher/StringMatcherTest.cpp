#include <gtest/gtest.h>
#include "matcher/StringMatcher.h"

class StringMatcherTest : public ::testing::Test {
protected:
    StringMatcherTest() :
        matcher("abcd") {

    }

    dem::lexer::StringMatcher matcher;
};

TEST_F(StringMatcherTest, ReturnsStringWhenMatch) {
    std::string str{"abcde"};

    std::string result = matcher.match(str.begin(), str.end());

    ASSERT_EQ("abcd", result);
}

TEST_F(StringMatcherTest, ReturnsEmptyWhenNoMatch) {
    std::string str{"bcdefa"};

    std::string result = matcher.match(str.begin(), str.end());

    ASSERT_EQ("", result);
}

TEST_F(StringMatcherTest, ReturnsEmptyWhenMatchNotAtBeginOfString) {
    std::string str{"dbabcd"};

    std::string result = matcher.match(str.begin(), str.end());

    ASSERT_EQ("", result);
}

TEST_F(StringMatcherTest, ReturnsEmptyWithEndIterator) {
    std::string str{"abcde"};

    std::string result = matcher.match(str.end(), str.end());

    ASSERT_EQ("", result);
}