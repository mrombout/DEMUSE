#include <gtest/gtest.h>
#include <matcher/DurationMatcher.h>
#include "matcher/AccidentalMatcher.h"

class DurationMatcherTest : public ::testing::Test {
protected:
    DurationMatcherTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    std::vector<dem::lexer::Token> tokens;
    dem::lexer::DurationMatcher matcher;
};

TEST_F(DurationMatcherTest, Match_NoMatch_ReturnsEmptyString) {
    // arrange
    std::string str{"@"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("", result);
}

TEST_F(DurationMatcherTest, Match_MatchWhole_ReturnsWhole) {
    // arrange
    std::string str{"w@@@"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("w", result);
}

TEST_F(DurationMatcherTest, Match_MatchHalf_ReturnsHalf) {
    // arrange
    std::string str{"h@@@"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("h", result);
}

TEST_F(DurationMatcherTest, Match_MatchQuarter_ReturnsQuarter) {
    // arrange
    std::string str{"q@@@"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("q", result);
}
