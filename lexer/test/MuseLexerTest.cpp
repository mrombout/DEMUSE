#include <gtest/gtest.h>
#include "MuseLexer.h"
#include "Token.h"

class MuseLexerTest : public ::testing::Test {
protected:
    MuseLexerTest() {

    }

    dem::lexer::MuseLexer lexer;
};

TEST_F(MuseLexerTest, Bool_PlainTrue) {
    // arrange
    std::string script = "true";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::BOOL, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Bool_PlainFalse) {
    // arrange
    std::string script = "false";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::BOOL, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Text_Plain) {
    // arrange
    std::string script = "\"Lorum ipsum dolor sit amet\"";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TEXT, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Text_PlainEscaped) {
    // arrange
    std::string script = "\"Lorum ipsum \\\"dolor sit amet\"";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TEXT, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Text_PlainUnescaped) {
    // arrange
    std::string script = "\"Lorum ipsum \"dolor sit amet\"";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TEXT, result[0].type());
    ASSERT_EQ("\"Lorum ipsum \"", result[0].content());
    ASSERT_EQ(dem::lexer::TokenType::IDENTIFIER, result[1].type());
    ASSERT_EQ("dolor", result[1].content());
}

TEST_F(MuseLexerTest, Number_Plain) {
    // arrange
    std::string script = "56";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::NUMBER, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Number_ZeroStart) {
    // arrange
    std::string script = "06";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::NUMBER, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Number_PlainDecimal) {
    // arrange
    std::string script = "3.14";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::NUMBER, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Note_Plain) {
    // arrange
    std::string script = "C;";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::NOTE, result[0].type());
    ASSERT_EQ(script.substr(0, 1), result[0].content());
}

TEST_F(MuseLexerTest, Note_Identifier) {
    // arrange
    std::string script = "Cars";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::IDENTIFIER, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Note_CaseSensitive) {
    // arrange
    std::string script = "c";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::IDENTIFIER, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Note_Accidental) {
    // arrange
    std::string script = "Cb";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::NOTE, result[0].type());
    ASSERT_EQ(script.substr(0, 1), result[0].content());
    ASSERT_EQ(dem::lexer::TokenType::ACCIDENTAL, result[1].type());
    ASSERT_EQ(script.substr(1), result[1].content());
}

TEST_F(MuseLexerTest, Comma_Plain) {
    // arrange
    std::string script = ",";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::COMMA, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Period_Plain) {
    // arrange
    std::string script = ".";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::PERIOD, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Positive_Plain) {
    // arrange
    std::string script = "+1";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::POSITIVE, result[0].type());
    ASSERT_EQ("+", result[0].content());
}

TEST_F(MuseLexerTest, Negative_Plain) {
    // arrange
    std::string script = "-1";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::NEGATIVE, result[0].type());
    ASSERT_EQ("-", result[0].content());
}

TEST_F(MuseLexerTest, Plus_Plain) {
    // arrange
    std::string script = "+";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::PLUS, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Plus_NoSpace) {
    // arrange
    std::string script = "+5";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_NE(dem::lexer::TokenType::PLUS, result[0].type());
    ASSERT_EQ("+", result[0].content());
}

TEST_F(MuseLexerTest, Minus_Plain) {
    // arrange
    std::string script = "-";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::MINUS, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Minus_NoSpace) {
    // arrange
    std::string script = "-5";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_NE(dem::lexer::TokenType::MINUS, result[0].type());
    ASSERT_EQ("-", result[0].content());
}

TEST_F(MuseLexerTest, Times_Plain) {
    // arrange
    std::string script = "*";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TIMES, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Times_NoSpace) {
    // arrange
    std::string script = "*5";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TIMES, result[0].type());
    ASSERT_EQ("*", result[0].content());
}

TEST_F(MuseLexerTest, Divide_Plain) {
    // arrange
    std::string script = "/";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::DIVIDE, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Divide_NoSpace) {
    // arrange
    std::string script = "/5";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::DIVIDE, result[0].type());
    ASSERT_EQ("/", result[0].content());
}

TEST_F(MuseLexerTest, Mod_Plain) {
    // arrange
    std::string script = "%";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::MOD, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Mod_NoSpace) {
    // arrange
    std::string script = "%5";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::MOD, result[0].type());
    ASSERT_EQ("%", result[0].content());
}

TEST_F(MuseLexerTest, Exp_Plain) {
    // arrange
    std::string script = "^";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::EXP, result[0].type());
    ASSERT_EQ(script, result[0].content());
}


TEST_F(MuseLexerTest, Exp_NoSpace) {
    // arrange
    std::string script = "^5";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::EXP, result[0].type());
    ASSERT_EQ("^", result[0].content());
}

TEST_F(MuseLexerTest, Eq_Plain) {
    // arrange
    std::string script = "==";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::EQ, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Teq_Plain) {
    // arrange
    std::string script = "===";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TEQ, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Neq_Plain) {
    // arrange
    std::string script = "!=";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::NEQ, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Tneq_Plain) {
    // arrange
    std::string script = "!==";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TNEQ, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Smeq_Plain) {
    // arrange
    std::string script = "<=";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::SMEQ, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Lreq_Plain) {
    // arrange
    std::string script = ">=";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::LREQ, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Sm_Plain) {
    // arrange
    std::string script = "<";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::SM, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Lr_Plain) {
    // arrange
    std::string script = ">";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::LR, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Not_Plain) {
    // arrange
    std::string script = "!";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::NOT, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, And_Plain) {
    // arrange
    std::string script = "&&";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::AND, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Or_Plain) {
    // arrange
    std::string script = "||";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::OR, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, For_Plain) {
    // arrange
    std::string script = "for";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::FOR, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, For_Empty) {
    // arrange
    std::string script = "for(;;) { }";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::FOR, result[0].type());
    ASSERT_EQ(script.substr(0, 3), result[0].content());
}

TEST_F(MuseLexerTest, For_WithStatements) {
    // arrange
    std::string script = "for(var i = 0; i < count; i++) { }";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::FOR, result[0].type());
    ASSERT_EQ(script.substr(0, 3), result[0].content());
}

TEST_F(MuseLexerTest, In_Plain) {
    // arrange
    std::string script = "in";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::IN_ARRAY, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Else_Plain) {
    // arrange
    std::string script = "else";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::ELSE, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Else_Block) {
    // arrange
    std::string script = "else { }";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::ELSE, result[0].type());
    ASSERT_EQ(script.substr(0, 4), result[0].content());
}

TEST_F(MuseLexerTest, Else_IfStatement) {
    // arrange
    std::string script = "else if(true) { }";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::ELSE, result[0].type());
    ASSERT_EQ(script.substr(0, 4), result[0].content());
}

TEST_F(MuseLexerTest, New_Plain) {
    // arrange
    std::string script = "new";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::NEW, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, New_WithExpression) {
    // arrange
    std::string script = "new Object();";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::NEW, result[0].type());
    ASSERT_EQ(script.substr(0, 3), result[0].content());
}

TEST_F(MuseLexerTest, If_Plain) {
    // arrange
    std::string script = "if";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::IF, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, If_WithExpression) {
    // arrange
    std::string script = "if(true) { }";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::IF, result[0].type());
    ASSERT_EQ(script.substr(0, 2), result[0].content());
}

TEST_F(MuseLexerTest, While_Plain) {
    // arrange
    std::string script = "while";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::WHILE, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, While_WithExpression) {
    // arrange
    std::string script = "while(true) { }";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::WHILE, result[0].type());
    ASSERT_EQ(script.substr(0, 5), result[0].content());
}

TEST_F(MuseLexerTest, Continue_Plain) {
    // arrange
    std::string script = "continue";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::CONTINUE, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Break_Plain) {
    // arrange
    std::string script = "break";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::BREAK, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Return_Plain) {
    // arrange
    std::string script = "return";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::RETURN, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Track_Plain) {
    // arrange
    std::string script = "track";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TRACK, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Start_Plain) {
    // arrange
    std::string script = "{";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::START, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, End_Plain) {
    // arrange
    std::string script = "}";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::END, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Open_Plain) {
    // arrange
    std::string script = "(";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::OPEN, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Close_Plain) {
    // arrange
    std::string script = ")";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::CLOSE, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, BracketOpen_Plain) {
    // arrange
    std::string script = "[";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::BRACKET_OPEN, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, BracketClose_Plain) {
    // arrange
    std::string script = "]";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::BRACKET_CLOSE, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

/* TODO: Broken, fix it
TEST_F(MuseLexerTest, Play_Plain) {
    // arrange
    std::string script = "<<";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::PLAY_START, result[0].type());
    ASSERT_EQ(script, result[0].content());
}
*/

TEST_F(MuseLexerTest, Function_Plain) {
    // arrange
    std::string script = "function";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::FUNCTION, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Var_Plain) {
    // arrange
    std::string script = "var";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::VAR, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Terminator_Plain) {
    // arrange
    std::string script = ";";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::TERMINATOR, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Assignment_Plain) {
    // arrange
    std::string script = "=";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::ASSIGNMENT, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Identifier_Plain) {
    // arrange
    std::string script = "X";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::IDENTIFIER, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Unknown_Single) {
    // arrange
    std::string script = "$";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::UNKNOWN, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Unknown_MultipleOnly) {
    // arrange
    std::string script = "$$$$$$";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::UNKNOWN, result[0].type());
    ASSERT_EQ(script, result[0].content());
}

TEST_F(MuseLexerTest, Unknown_MultipleThenRecognized) {
    // arrange
    std::string script = "$$$$$$ if(true) { }";

    // act
    std::vector<dem::lexer::Token> result = lexer.lex(script.begin(), script.end());

    // assert
    ASSERT_EQ(dem::lexer::TokenType::UNKNOWN, result[0].type());
    ASSERT_EQ(script.substr(0, 6), result[0].content());
}