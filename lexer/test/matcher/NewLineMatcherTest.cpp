#include <gtest/gtest.h>
#include "matcher/NewLineMatcher.h"

class NewLineMatcherTest : public ::testing::Test {
protected:
    NewLineMatcherTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    std::vector<dem::lexer::Token> tokens;
    dem::lexer::NewLineMatcher matcher;
};

TEST_F(NewLineMatcherTest, Match_NoMatch_ReturnsEmptyString) {
    // arrange
    std::string str{"@@@"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("", result);
}

TEST_F(NewLineMatcherTest, Match_WindowsNewline_ReturnWindowsNewLine) {
    // arrange
    std::string str{"\r\n@@@"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("\r\n", result);
}

TEST_F(NewLineMatcherTest, Match_UnixNewline_ReturnWindowsNewLine) {
    // arrange
    std::string str{"\n@@@"};

    auto begin = str.begin();
    auto end = str.end();

    // act
    std::string result = matcher.match(begin, end, tokens, tokenPosition);

    // assert
    ASSERT_EQ("\n", result);
}
