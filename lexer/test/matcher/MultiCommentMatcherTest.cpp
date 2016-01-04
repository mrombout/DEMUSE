#include <gtest/gtest.h>
#include <matcher/DurationMatcher.h>
#include <matcher/MultiCommentMatcher.h>
#include "matcher/AccidentalMatcher.h"

class MultiCommentMatcherTest : public ::testing::Test {
protected:
    MultiCommentMatcherTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    std::vector<dem::lexer::Token> tokens;
    dem::lexer::MultiCommentMatcher matcher;
};

TEST_F(MultiCommentMatcherTest, Match_NoMatch_ReturnsEmptyString) {
    // arrange
    std::string str{"@@@"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("", result);
}

TEST_F(MultiCommentMatcherTest, Match_NoClose_ReturnsEmptyString) {
    // arrange
    std::string str{"/* comment"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("", result);
}

TEST_F(MultiCommentMatcherTest, Match_Closed_ReturnsComment) {
    // arrange
    std::string str{"/* comment */"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ(str, result);
}
