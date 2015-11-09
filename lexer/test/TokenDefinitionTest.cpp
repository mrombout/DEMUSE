#include <gtest/gtest.h>
#include <matcher/NullMatcher.h>
#include "TokenDefinition.h"
#include "TokenType.h"

TEST(TokenDefinitionTest, ConstructorInitializes) {
    dem::lexer::NullMatcher *matcher = new dem::lexer::NullMatcher();
    dem::lexer::TokenDefinition tokenDefinition{dem::lexer::TokenType::UNKNOWN, matcher};
    dem::lexer::TokenDefinition tokenDefinitionCopy = tokenDefinition;

    ASSERT_EQ(matcher, &tokenDefinition.matcher());
    ASSERT_EQ(dem::lexer::TokenType::UNKNOWN, tokenDefinition.type());
    ASSERT_NE(matcher, &tokenDefinitionCopy.matcher());
    ASSERT_EQ(dem::lexer::TokenType::UNKNOWN, tokenDefinitionCopy.type());
}