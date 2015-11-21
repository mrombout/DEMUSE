#include <gtest/gtest.h>
#include "Lexer.h"
#include "matcher/StringMatcher.h"
#include "TokenType.h"

class LexerTest : public ::testing::Test {
protected:
    LexerTest() {
        lexer.addDefinition(new dem::lexer::TokenDefinition(dem::lexer::TokenType::AND, new dem::lexer::StringMatcher("AND")));
        lexer.addDefinition(new dem::lexer::TokenDefinition(dem::lexer::TokenType::OR, new dem::lexer::StringMatcher("OR")));
    }

    dem::lexer::Lexer lexer;
};

TEST_F(LexerTest, ReturnsTokenListWhenMatchNoWhitespaceSeperation) {
    std::string str{"ANDOR"};

    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ("AND", result[0].content());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[1].type());
    EXPECT_EQ("OR", result[1].content());
}

TEST_F(LexerTest, ReturnsTokenListWhenMatchWithWhitespaceSeperation) {
    std::string str{"AND OR"};

    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ("AND", result[0].content());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[1].type());
    EXPECT_EQ("OR", result[1].content());
}

TEST_F(LexerTest, ReturnsTokenListWhenMatchWithUnknown) {
    std::string str{"AND unknown OR"};

    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    ASSERT_EQ(3, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ(dem::lexer::TokenType::UNKNOWN, result[1].type());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[2].type());
}

TEST_F(LexerTest, ReturnsTokenListWhenTabbed) {
    std::string str{"AND\tOR"};

    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[1].type());
}

TEST_F(LexerTest, ReturnsTokenListWithWindowsNewlines) {
    std::string str{"AND\r\nOR"};

    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[1].type());
}

TEST_F(LexerTest, ReturnsTokenListWithUnixNewlines) {
    std::string str{"AND\nOR"};

    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[1].type());
}

TEST_F(LexerTest, ReturnsTokenListWithMacNewlines) {
    std::string str{"AND\rOR"};

    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[1].type());
}

TEST_F(LexerTest, ReturnsTokenListWhenNullTokenDefinition) {
    std::string str{"abcdef AND"};

    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::UNKNOWN, result[0].type());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[1].type());
}

TEST_F(LexerTest, ReturnsEmptyListWithEndIterator) {
    std::string str{"abcdef"};

    std::vector<dem::lexer::Token> result = lexer.lex(str.end(), str.end());

    ASSERT_EQ(0, result.size());
}

TEST_F(LexerTest, ReturnsListWithSingleUnknownWhenNoMatch) {

}

TEST_F(LexerTest, ReturnsUnknownWhenNoTokenDefinitions) {
    std::string str{"abcdef"};

    dem::lexer::Lexer lexer;
    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    ASSERT_EQ(1, result.size());
    ASSERT_EQ(dem::lexer::TokenType::UNKNOWN, result[0].type());
    ASSERT_EQ("abcdef", result[0].content());
}

TEST_F(LexerTest, Lex_OneLineFirstToken_PositionIsCorrect) {
    // arrange
    std::string str{"AND"};

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    // assert
    ASSERT_EQ(1, result[0].line());
    ASSERT_EQ(1, result[0].column());
    ASSERT_EQ(0, result[0].startIndex());
}


TEST_F(LexerTest, Lex_OneLineSecondToken_PositionIsCorrect) {
    // arrange
    std::string str{"ANDOR"};

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    // assert
    ASSERT_EQ(1, result[1].line());
    ASSERT_EQ(4, result[1].column());
    ASSERT_EQ(3, result[1].startIndex());
}


TEST_F(LexerTest, Lex_TwoLinesSecondToken_PositionIsCorrect) {
    // arrange
    std::string str{"AND\r\nOR"};

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    // assert
    ASSERT_EQ(2, result[1].line());
    ASSERT_EQ(1, result[1].column());
    ASSERT_EQ(5, result[1].startIndex());
}

TEST_F(LexerTest, Lex_WindowsNewLine_TotalThreeLines) {
    // arrange
    std::string str{"AND\r\nOR\r\nAND"};

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    // assert
    ASSERT_EQ(3, result[2].line());
}

TEST_F(LexerTest, Lex_LinuxNewLine_TotalThreeLines) {
    // arrange
    std::string str{"AND\nOR\nAND"};

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    // assert
    ASSERT_EQ(3, result[2].line());
}

TEST_F(LexerTest, Lex_MacNewLine_TotalThreeLines) {
    // arrange
    std::string str{"AND\rOR\rAND"};

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(str.begin(), str.end());

    // assert
    ASSERT_EQ(3, result[2].line());
}