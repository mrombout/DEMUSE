#include <gtest/gtest.h>
#include "MusicStringLexer.h"
#include "Token.h"
#include "TokenType.h"

class MusicStringLexerTest : public ::testing::Test {
protected:
    MusicStringLexerTest() {

    }

    dem::lexer::MusicStringLexer lexer;
};

TEST_F(MusicStringLexerTest, Note_Single) {
    // arrange
    std::string str{"C"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::NOTE, tokens[0].type());
}

// TODO: FIXME
TEST_F(MusicStringLexerTest, Note_Identifier) {
    // arrange
    std::string str{"Car"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::UNKNOWN, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Accidental_SingleSharp) {
    // arrange
    std::string str{"#"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::ACCIDENTAL, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Accidental_SingleFlat) {
    // arrange
    std::string str{"b"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::ACCIDENTAL, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Accidental_SingleNatural) {
    // arrange
    std::string str{"n"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::ACCIDENTAL, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Chord_SingleMajor) {
    // arrange
    std::string str{"maj"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::CHORD, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Duration_Single) {
    // arrange
    std::string str{"w"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::DURATION, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Tuplet_Single) {
    // arrange
    std::string str{"*"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TUPLET, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Tie_Single) {
    // arrange
    std::string str{"-"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TIE, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Attack_Single) {
    // arrange
    std::string str{"a100"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::ATTACK, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Decay_Single) {
    // arrange
    std::string str{"d100"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::DECAY, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Harmony_Single) {
    // arrange
    std::string str{"+"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::HARMONY, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Combine_Single) {
    // arrange
    std::string str{"_"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::COMBINE, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Measure_Single) {
    // arrange
    std::string str{"|"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end, false);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::MEASURE, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Key_Single) {
    // arrange
    std::string str{"K"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::KEY, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Instrument_Single) {
    // arrange
    std::string str{"I"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::INSTRUMENT, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Voice_Single) {
    // arrange
    std::string str{"V"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::VOICE, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Layer_Single) {
    // arrange
    std::string str{"L"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::LAYER, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Tempo_Single) {
    // arrange
    std::string str{"T"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TEMPO, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Pitch_Single) {
    // arrange
    std::string str{"&8192"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::PITCH, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Pressure_Single) {
    // arrange
    std::string str{"+100"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::PRESSURE, tokens[0].type());
}

TEST_F(MusicStringLexerTest, PolyPressure_Single) {
    // arrange
    std::string str{"*100,100"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::POLY_PRESSURE, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Controller_Single) {
    // arrange
    std::string str{"X"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::CONTROLLER, tokens[0].type());
}

TEST_F(MusicStringLexerTest, Time_Single) {
    // arrange
    std::string str{"@100"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TIME, tokens[0].type());
}

TEST_F(MusicStringLexerTest, BracketOpen_Single) {
    // arrange
    std::string str{"["};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::BRACKET_OPEN, tokens[0].type());
}

TEST_F(MusicStringLexerTest, BracketClose_Single) {
    // arrange
    std::string str{"]"};
    auto begin = str.begin();
    auto end = str.end();

    // act
    std::vector<dem::lexer::Token> tokens = lexer.lex(begin, end);

    // assert
    ASSERT_EQ(dem::lexer::TokenType::BRACKET_CLOSE, tokens[0].type());
}