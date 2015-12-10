#include <gtest/gtest.h>
#include <symbol/Block.h>
#include "factory/FunctionDefinitionFactory.h"
#include "symbol/Identifier.h"
#include "symbol/FunctionDefinition.h"

class FunctionDefinitionTest : public ::testing::Test {
protected:
    FunctionDefinitionTest() {

    }

    dem::lexer::TokenPosition tokenPosition;
    dem::parser::FunctionDefinitionFactory factory;
};

TEST_F(FunctionDefinitionTest, EmptyParameterList) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FUNCTION,   "function", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}", tokenPosition),
    };

    // act
    dem::parser::FunctionDefinition *functionDefinitionStatement = factory.produce(tokens);

    // assert
    ASSERT_EQ(typeid(dem::parser::Identifier), typeid(functionDefinitionStatement->identifier()));
    ASSERT_EQ(typeid(dem::parser::ParameterList), typeid(functionDefinitionStatement->parameterList()));
    ASSERT_TRUE(functionDefinitionStatement->parameterList().isEmpty());
    ASSERT_EQ(typeid(dem::parser::Block), typeid(functionDefinitionStatement->block()));
}

TEST_F(FunctionDefinitionTest, SingleParameterList) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FUNCTION,   "function", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "bar", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}", tokenPosition),
    };

    // act
    dem::parser::FunctionDefinition *functionDefinitionStatement = factory.produce(tokens);

    // assert
    ASSERT_EQ(typeid(dem::parser::Identifier), typeid(functionDefinitionStatement->identifier()));
    ASSERT_EQ(typeid(dem::parser::ParameterList), typeid(functionDefinitionStatement->parameterList()));
    ASSERT_EQ(1, functionDefinitionStatement->parameterList().numParameters());
    ASSERT_EQ(typeid(dem::parser::Block), typeid(functionDefinitionStatement->block()));
}

TEST_F(FunctionDefinitionTest, ThreeParameterList) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::FUNCTION,   "function", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "bar1", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::COMMA,      ",", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "bar2", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::COMMA,      ",", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "bar3", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::START,      "{", tokenPosition),
        dem::lexer::Token(dem::lexer::TokenType::END,        "}", tokenPosition),
    };

    // act
    dem::parser::FunctionDefinition *functionDefinitionStatement = factory.produce(tokens);

    // assert
    ASSERT_EQ(typeid(dem::parser::Identifier), typeid(functionDefinitionStatement->identifier()));
    ASSERT_EQ(typeid(dem::parser::ParameterList), typeid(functionDefinitionStatement->parameterList()));
    ASSERT_EQ(3, functionDefinitionStatement->parameterList().numParameters());
    ASSERT_EQ(typeid(dem::parser::Block), typeid(functionDefinitionStatement->block()));
}
