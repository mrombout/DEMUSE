#include <gtest/gtest.h>
#include "matcher/NullMatcher.h"

class NullMatcherTest : public ::testing::Test {
protected:
    NullMatcherTest() {

    }

    dem::lexer::NullMatcher matcher;
};

TEST_F(NullMatcherTest, MatchReturnsEmptyString) {
    std::string str{"foobar"};
    std::string result = matcher.match(str.begin(), str.end());

    ASSERT_EQ("", result);
}

TEST_F(NullMatcherTest, MatchReturnsEmptyStringWithEndIterator) {
    std::string str{"foobar"};
    std::string result = matcher.match(str.end(), str.end());

    ASSERT_EQ("", result);
}