#include <gtest/gtest.h>
#include "matcher/AccidentalMatcher.h"

class AccidentalMatcherTest : public ::testing::Test {
protected:
    AccidentalMatcherTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    std::vector<dem::lexer::Token> tokens;
    dem::lexer::AccidentalMatcher matcher;
};

TEST_F(AccidentalMatcherTest, Match_NoMatch_ReturnsEmptyString) {
    // arrange
    std::string str{"@"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("", result);
}

TEST_F(AccidentalMatcherTest, Match_MatchSharp_ReturnsSharp) {
    // arrange
    std::string str{"#"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("#", result);
}

TEST_F(AccidentalMatcherTest, Match_MatchFlat_ReturnsFlat) {
    // arrange
    std::string str{"b"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("b", result);
}

TEST_F(AccidentalMatcherTest, Match_MatchNatural_ReturnsNatural) {
    // arrange
    std::string str{"n"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("n", result);
}
