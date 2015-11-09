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
    // TODO: result[0].mTokenType suddenly changes after first ASSERT, WTH?!
    EXPECT_EQ(dem::lexer::TokenType::UNKNOWN, result[0].type());
    EXPECT_EQ(dem::lexer::TokenType::AND, result[1].type());
    std::cout << "Boija!" << std::endl;
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