#include <gtest/gtest.h>
#include "matcher/NullMatcher.h"
#include "Token.h"

class NullMatcherTest : public ::testing::Test {
protected:
    NullMatcherTest() {

    }

    std::vector<dem::lexer::Token> tokens;
    dem::lexer::NullMatcher matcher;
};

TEST_F(NullMatcherTest, MatchReturnsEmptyString) {
    std::string str{"foobar"};
    std::string result = matcher.match(str.begin(), str.end(), tokens);

    ASSERT_EQ("", result);
}

TEST_F(NullMatcherTest, MatchReturnsEmptyStringWithEndIterator) {
    std::string str{"foobar"};
    std::string result = matcher.match(str.end(), str.end(), tokens);

    ASSERT_EQ("", result);
}