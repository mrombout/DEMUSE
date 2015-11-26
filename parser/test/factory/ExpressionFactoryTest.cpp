#include <gtest/gtest.h>
#include <symbol/expression/StrictEqualCondition.h>
#include <symbol/expression/StrictNotEqualCondition.h>
#include <symbol/expression/ExponentExpression.h>
#include <symbol/FunctionCall.h>
#include "factory/ExpressionFactory.h"
#include "symbol/Identifier.h"
#include "symbol/Number.h"
#include "symbol/Text.h"
#include "symbol/Bool.h"
#include "symbol/expression/Expression.h"
#include "symbol/expression/AdditionExpression.h"
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
#include "symbol/expression/BinaryExpression.h"

class ExpressionFactoryTest : public ::testing::Test {
protected:
    ExpressionFactoryTest() {

    }

    dem::parser::ExpressionFactory *factory;
};

TEST_F(ExpressionFactoryTest, ExpressionIdentifier) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "X", 0, 0, 0)
    };

    // act
    dem::parser::Identifier *identifier = dynamic_cast<dem::parser::Identifier*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, identifier);
}

TEST_F(ExpressionFactoryTest, ExpressionPrimitiveNumber) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Number *number = dynamic_cast<dem::parser::Number*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, number);
    ASSERT_EQ(5, number->value());
}

TEST_F(ExpressionFactoryTest, ExpressionPrimitiveText) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::TEXT, "Lorum ipsum", 0, 0, 0)
    };

    // act
    dem::parser::Text *text = dynamic_cast<dem::parser::Text*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, text);
}

TEST_F(ExpressionFactoryTest, ExpressionPrimitiveBool) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::BOOL, "true", 0, 0, 0)
    };

    // act
    dem::parser::Bool *boolean = dynamic_cast<dem::parser::Bool*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, boolean);
}

TEST_F(ExpressionFactoryTest, ExpressionFunctionCall) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::IDENTIFIER, "foo",   0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::OPEN,       "(",  0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,      ")", 0, 0, 0)
    };

    // act
    dem::parser::FunctionCall *functionCall = dynamic_cast<dem::parser::FunctionCall*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, functionCall);
}

TEST_F(ExpressionFactoryTest, AdditionSingle) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,   "+", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::AdditionExpression *addExpression = dynamic_cast<dem::parser::AdditionExpression *>(expression);

    // assert
    ASSERT_NE(nullptr, addExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(addExpression->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(addExpression->right()));
}

TEST_F(ExpressionFactoryTest, AdditionMultiple) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,   "+", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,   "+", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::AdditionExpression *addExpression = dynamic_cast<dem::parser::AdditionExpression *>(expression);

    // assert
    ASSERT_NE(nullptr, addExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(addExpression->left()));
    ASSERT_EQ(typeid(dem::parser::AdditionExpression), typeid(addExpression->right()));
}

TEST_F(ExpressionFactoryTest, AdditionMultiplicationPrecedence) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TIMES,  "*", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,   "+", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::BinaryExpression<dem::parser::Expression, dem::parser::Expression> *expression = dynamic_cast<dem::parser::BinaryExpression<dem::parser::Expression, dem::parser::Expression>*>(factory->produce(tokens));

    // assert
    ASSERT_NE(nullptr, expression);
    ASSERT_EQ(typeid(dem::parser::MultiplicationExpression), typeid(*expression));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(expression->left()));
    ASSERT_EQ(typeid(dem::parser::AdditionExpression), typeid(expression->right()));
}

TEST_F(ExpressionFactoryTest, SubtractionSingle) {
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

TEST_F(ExpressionFactoryTest, SubtractionMultiple) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::MINUS,  "-", 0, 0, 0),
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
    ASSERT_EQ(typeid(dem::parser::SubtractionExpression), typeid(subtractionExpression->right()));
}

TEST_F(ExpressionFactoryTest, MultiplicationSingle) {
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

TEST_F(ExpressionFactoryTest, MultiplicationMultiple) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TIMES,  "*", 0, 0, 0),
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
    ASSERT_EQ(typeid(dem::parser::MultiplicationExpression), typeid(multiplicationExpression->right()));
}

TEST_F(ExpressionFactoryTest, DivisionSingle) {
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

TEST_F(ExpressionFactoryTest, DivisionMultiple) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::DIVIDE, "/", 0, 0, 0),
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
    ASSERT_EQ(typeid(dem::parser::DivisionExpression), typeid(divisionExpression->right()));
}

TEST_F(ExpressionFactoryTest, ModuloSingle) {
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

TEST_F(ExpressionFactoryTest, ModuloMultiple) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::MOD,    "%", 0, 0, 0),
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
    ASSERT_EQ(typeid(dem::parser::ModuloExpression), typeid(moduloExpression->right()));
}

TEST_F(ExpressionFactoryTest, ExponentSingle) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::EXP,    "^", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::ExponentExpression *exponentExpression = dynamic_cast<dem::parser::ExponentExpression*>(expression);

    // assert
    ASSERT_NE(nullptr, exponentExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(exponentExpression->left()));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(exponentExpression->right()));
}

TEST_F(ExpressionFactoryTest, ParenthesisSingle) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::OPEN,   "(", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::PLUS,   "+", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "2", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::CLOSE,  ")", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::TIMES,  "*", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "5", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);

    // assert
    ASSERT_TRUE(dynamic_cast<dem::parser::MultiplicationExpression*>(expression));
}

TEST_F(ExpressionFactoryTest, ExponentMultiple) {
    // arrange
    std::deque<dem::lexer::Token> tokens {
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "2", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::EXP,    "^", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "3", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::EXP,    "^", 0, 0, 0),
        dem::lexer::Token(dem::lexer::TokenType::NUMBER, "1", 0, 0, 0)
    };

    // act
    dem::parser::Expression *expression = factory->produce(tokens);
    dem::parser::ExponentExpression *exponentExpression = dynamic_cast<dem::parser::ExponentExpression*>(expression);

    dem::parser::Expression &leftHand = exponentExpression->left();
    dem::parser::Expression &rightHand = exponentExpression->right();
    dem::parser::Expression &rightLeftHand = static_cast<dem::parser::ExponentExpression&>(rightHand).left();
    dem::parser::Expression &rightRightHand = ((dem::parser::ExponentExpression&)rightHand).right();

    // assert
    ASSERT_NE(nullptr, exponentExpression);
    ASSERT_EQ(typeid(dem::parser::Number), typeid(leftHand));
    ASSERT_EQ(typeid(dem::parser::ExponentExpression), typeid(rightHand));
    ASSERT_EQ(typeid(dem::parser::Number), typeid(rightLeftHand));
    ASSERT_EQ(3.0d, static_cast<dem::parser::Number&>(rightLeftHand).value());
    ASSERT_EQ(typeid(dem::parser::Number), typeid(rightRightHand));
    ASSERT_EQ(1.0d, static_cast<dem::parser::Number&>(rightRightHand).value());
}

TEST_F(ExpressionFactoryTest, ConditionAnd) {
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

TEST_F(ExpressionFactoryTest, ConditionEqual) {
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

TEST_F(ExpressionFactoryTest, ConditionLargerThan) {
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

TEST_F(ExpressionFactoryTest, ConditionLargerThanOrEqual) {
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

TEST_F(ExpressionFactoryTest, ConditionNotEqual) {
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

TEST_F(ExpressionFactoryTest, ConditionOr) {
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

TEST_F(ExpressionFactoryTest, ConditionSmallerThan) {
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

TEST_F(ExpressionFactoryTest, ConditionSmallerThanOrEqual) {
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

TEST_F(ExpressionFactoryTest, ConditionStrictEqual) {
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


TEST_F(ExpressionFactoryTest, ConditionStrictNotEqual) {
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
// TODO: Test POSITIVE/NEGATIVE tokens