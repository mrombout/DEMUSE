#include <gtest/gtest.h>
#include <symbol/expression/StrictEqualCondition.h>
#include <symbol/expression/StrictNotEqualCondition.h>
#include "factory/ExpressionFactory.h"
#include "symbol/Identifier.h"
#include "symbol/Number.h"
#include "symbol/Text.h"
#include "symbol/Bool.h"
#include "symbol/expression/AddExpression.h"
#include "symbol/expression/SubtractionExpression.h"
#include "symbol/expression/MultiplicationExpression.h"
#include "symbol/expression/DivisionExpression.h"
#include "symbol/expression/ModuloExpression.h"
#include "symbol/expression/SmallerThanCondition.h"
#include "symbol/expression/SmallerThanOrEqualCondition.h"
#include "symbol/expression/AndCondition.h"
#include "symbol/expression/EqualCondition.h"
#include "symbol/expression/LargerThanCondition.h"
#include "symbol/expression/LargerThanOrEqualCondition.h"
#include "symbol/expression/NotEqualCondition.h"
#include "symbol/expression/OrCondition.h"

class ExpressionFactoryTest : public ::testing::Test {
protected:
    ExpressionFactoryTest() {

    }

    dem::parser::ExpressionFactory *factory;
};

/*
TEST_F(ExpressionFactoryTest, SingleIdentifierExpression) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "X", 0, 0, 0)
    };

    // act
    dem::parser::Identifier *identifier = dynamic_cast<dem::parser::Identifier*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, identifier);
}
*/

TEST_F(ExpressionFactoryTest, SingleNumberPrimitiveExpression) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Number *number = dynamic_cast<dem::parser::Number*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, number);
    ASSERT_EQ("5", number->value());
}

TEST_F(ExpressionFactoryTest, SingleTextPrimitiveExpression) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::TEXT, "Lorum ipsum", 0, 0, 0)
    };

    // act
    dem::parser::Text *text = dynamic_cast<dem::parser::Text*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, text);
}

TEST_F(ExpressionFactoryTest, SingleBoolPrimitiveExpression) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::BOOL, "true", 0, 0, 0)
    };

    // act
    dem::parser::Bool *boolean = dynamic_cast<dem::parser::Bool*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, boolean);
}

TEST_F(ExpressionFactoryTest, SingleAddition) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,   "+", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::AddExpression *addExpression = dynamic_cast<dem::parser::AddExpression*>(expression);

    // assert
    ASSERT_NE(nullptr, addExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(addExpression->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(addExpression->right()));
}

TEST_F(ExpressionFactoryTest, SingleSubtraction) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::MINUS,  "-", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::SubtractionExpression *subtractionExpression = dynamic_cast<dem::parser::SubtractionExpression*>(expression);

    // assert
    ASSERT_NE(nullptr, subtractionExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(subtractionExpression->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(subtractionExpression->right()));
}

TEST_F(ExpressionFactoryTest, SingleMultiplication) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TIMES,  "*", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::MultiplicationExpression *multiplicationExpression = dynamic_cast<dem::parser::MultiplicationExpression*>(expression);

    // assert
    ASSERT_NE(nullptr, multiplicationExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(multiplicationExpression->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(multiplicationExpression->right()));
}

TEST_F(ExpressionFactoryTest, SingleDivision) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::DIVIDE, "/", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::DivisionExpression *divisionExpression = dynamic_cast<dem::parser::DivisionExpression*>(expression);

    // assert
    ASSERT_NE(nullptr, divisionExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(divisionExpression->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(divisionExpression->right()));
}


TEST_F(ExpressionFactoryTest, SingleModuloOperation) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::MOD,    "%", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::ModuloExpression *moduloExpression = dynamic_cast<dem::parser::ModuloExpression*>(expression);

    // assert
    ASSERT_NE(nullptr, moduloExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(moduloExpression->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(moduloExpression->right()));
}

TEST_F(ExpressionFactoryTest, AndCondition) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::BOOL, "true", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::AND,  "&&",   0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::BOOL, "true", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::AndCondition *andCondition = dynamic_cast<dem::parser::AndCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, andCondition);
    ASSERT_EQ(typeid(dem::parser::Bool), typeid(andCondition->left()));
    ASSERT_EQ(typeid(dem::parser::Bool), typeid(andCondition->right()));
}

TEST_F(ExpressionFactoryTest, EqualCondition) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::EQ,     "==", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::EqualCondition *equalCondition = dynamic_cast<dem::parser::EqualCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, equalCondition);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(equalCondition->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(equalCondition->right()));
}

TEST_F(ExpressionFactoryTest, LargerThanCondition) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::LR,     ">", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::LargerThanCondition *largerThanCondition = dynamic_cast<dem::parser::LargerThanCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, largerThanCondition);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(largerThanCondition->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(largerThanCondition->right()));
}

TEST_F(ExpressionFactoryTest, LargerThanOrEqualCondition) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::LREQ,   ">=", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::LargerThanOrEqualCondition *lreqCondition = dynamic_cast<dem::parser::LargerThanOrEqualCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, lreqCondition);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(lreqCondition->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(lreqCondition->right()));
}

TEST_F(ExpressionFactoryTest, NotEqualCondition) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::NEQ,    "!=", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::NotEqualCondition *notEqualCondition = dynamic_cast<dem::parser::NotEqualCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, notEqualCondition);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(notEqualCondition->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(notEqualCondition->right()));
}

TEST_F(ExpressionFactoryTest, OrCondition) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::OR,     "||", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::OrCondition *orCondition = dynamic_cast<dem::parser::OrCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, orCondition);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(orCondition->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(orCondition->right()));
}

TEST_F(ExpressionFactoryTest, SmallerThanCondition) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::SM,     "<", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::SmallerThanCondition *smallerThanCondition = dynamic_cast<dem::parser::SmallerThanCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, smallerThanCondition);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(smallerThanCondition->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(smallerThanCondition->right()));
}

TEST_F(ExpressionFactoryTest, SmallerThanOrEqualCondition) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::SMEQ,   "<=", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",  0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::SmallerThanOrEqualCondition *smallerThanOrEqualCondition = dynamic_cast<dem::parser::SmallerThanOrEqualCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, smallerThanOrEqualCondition);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(smallerThanOrEqualCondition->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(smallerThanOrEqualCondition->right()));
}

TEST_F(ExpressionFactoryTest, StrictEqual) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",   0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TEQ,    "===", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",   0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::StrictEqualCondition *strictEqualCondition = dynamic_cast<dem::parser::StrictEqualCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, strictEqualCondition);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(strictEqualCondition->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(strictEqualCondition->right()));
}


TEST_F(ExpressionFactoryTest, StrictNotEqual) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
            dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",   0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::TNEQ,   "!==", 0, 0, 0),
            dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5",   0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::StrictNotEqualCondition *strictNotEqualCondition = dynamic_cast<dem::parser::StrictNotEqualCondition*>(expression);

    // assert
    ASSERT_NE(nullptr, strictNotEqualCondition);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(strictNotEqualCondition->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(strictNotEqualCondition->right()));
}

// TODO: Test nested expressions
// TODO: Test precedence of every operator
// TODO: Test associativity for every operator