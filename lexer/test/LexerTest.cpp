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
    auto begin = str.begin();
    auto end = str.end();

    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ("AND", result[0].content());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[1].type());
    EXPECT_EQ("OR", result[1].content());
}

TEST_F(LexerTest, ReturnsTokenListWhenMatchWithWhitespaceSeperation) {
    std::string str{"AND OR"};
    auto begin = str.begin();
    auto end = str.end();

    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ("AND", result[0].content());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[1].type());
    EXPECT_EQ("OR", result[1].content());
}

TEST_F(LexerTest, ReturnsTokenListWhenMatchWithUnknown) {
    std::string str{"AND unknown OR"};
    auto begin = str.begin();
    auto end = str.end();

    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    ASSERT_EQ(9, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    for(int i = 1; i < 8; ++i) {
        EXPECT_EQ(dem::lexer::TokenType::UNKNOWN, result[i].type());
    }
    EXPECT_EQ(dem::lexer::TokenType::OR, result[8].type());
}

TEST_F(LexerTest, ReturnsTokenListWhenTabbed) {
    std::string str{"AND\tOR"};
    auto begin = str.begin();
    auto end = str.end();

    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[1].type());
}

TEST_F(LexerTest, ReturnsTokenListWithWindowsNewlines) {
    std::string str{"AND\r\nOR"};
    auto begin = str.begin();
    auto end = str.end();

    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[1].type());
}

TEST_F(LexerTest, ReturnsTokenListWithUnixNewlines) {
    std::string str{"AND\nOR"};
    auto begin = str.begin();
    auto end = str.end();

    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[1].type());
}

TEST_F(LexerTest, ReturnsTokenListWithMacNewlines) {
    std::string str{"AND\rOR"};
    auto begin = str.begin();
    auto end = str.end();

    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    ASSERT_EQ(2, result.size());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[0].type());
    EXPECT_EQ(dem::lexer::TokenType::OR, result[1].type());
}

TEST_F(LexerTest, ReturnsTokenListWhenNullTokenDefinition) {
    std::string str{"abcdef AND"};
    auto begin = str.begin();
    auto end = str.end();

    dem::lexer::Lexer lexer;
    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    ASSERT_EQ(9, result.size());
    for(int i = 0; i < 9; i++) {
        EXPECT_EQ(dem::lexer::TokenType::UNKNOWN, result[i].type());
    }
}

TEST_F(LexerTest, ReturnsEmptyListWithEndIterator) {
    std::string str{"abcdef"};
    auto end = str.end();

    std::vector<dem::lexer::Token> result = lexer.lex(end, end);

    ASSERT_EQ(0, result.size());
}

TEST_F(LexerTest, ReturnsListWithSingleUnknownWhenNoMatch) {

}

TEST_F(LexerTest, ReturnsUnknownWhenNoTokenDefinitions) {
    std::string str{"abcdef"};
    auto begin = str.begin();
    auto end = str.end();

    dem::lexer::Lexer lexer;
    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    ASSERT_EQ(6, result.size());
    for(int i = 0; i < 6; ++i) {
        ASSERT_EQ(std::string(1, str.at(i)), result[i].content());
        ASSERT_EQ(dem::lexer::TokenType::UNKNOWN, result[i].type());
    }
}

TEST_F(LexerTest, Lex_OneLineFirstToken_PositionIsCorrect) {
    // arrange
    std::string str{"AND"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(1, result[0].line());
    ASSERT_EQ(1, result[0].column());
    ASSERT_EQ(0, result[0].startIndex());
}


TEST_F(LexerTest, Lex_OneLineSecondToken_PositionIsCorrect) {
    // arrange
    std::string str{"ANDOR"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(1, result[1].line());
    ASSERT_EQ(4, result[1].column());
    ASSERT_EQ(3, result[1].startIndex());
}


TEST_F(LexerTest, Lex_TwoLinesSecondToken_PositionIsCorrect) {
    // arrange
    std::string str{"AND\r\nOR"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(2, result[1].line());
    ASSERT_EQ(1, result[1].column());
    ASSERT_EQ(5, result[1].startIndex());
}

TEST_F(LexerTest, Lex_WindowsNewLine_TotalThreeLines) {
    // arrange
    std::string str{"AND\r\nOR\r\nAND"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(3, result[2].line());
}

TEST_F(LexerTest, Lex_LinuxNewLine_TotalThreeLines) {
    // arrange
    std::string str{"AND\nOR\nAND"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(3, result[2].line());
}

TEST_F(LexerTest, Lex_MacNewLine_TotalThreeLines) {
    // arrange
    std::string str{"AND\rOR\rAND"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(3, result[2].line());
}