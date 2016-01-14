#include <gtest/gtest.h>
#include "MuseMidiCompiler.h"

using namespace dem::parser;
using namespace dem::compiler;

class ExpressionEvaluatorTest : public ::testing::Test {
protected:
    ExpressionEvaluatorTest() :
        scope(nullptr),
        evaluator(compiler),
        dummyToken(dem::lexer::TokenType::UNKNOWN, "", dem::lexer::TokenPosition()) {

    }

    dem::compiler::ObjectValue scope;
    dem::compiler::MuseMidiCompiler compiler;
    dem::compiler::ExpressionEvaluator evaluator;

    dem::lexer::Token dummyToken;
};

TEST_F(ExpressionEvaluatorTest, Addition_Simple) {
    // arrange
    NumberLiteral *lhv = new NumberLiteral{dummyToken, 5};
    NumberLiteral *rhv = new NumberLiteral{dummyToken, 6};
    AdditionExpression expr{lhv, rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(11, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Subtraction_Simple) {
    // arrange
    NumberLiteral *lhv = new NumberLiteral{dummyToken, 5};
    NumberLiteral *rhv = new NumberLiteral{dummyToken, 6};
    SubtractionExpression expr{lhv, rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(-1, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Multiplication_Simple) {
    // arrange
    NumberLiteral *lhv = new NumberLiteral{dummyToken, 5};
    NumberLiteral *rhv = new NumberLiteral{dummyToken, 6};
    MultiplicationExpression expr{lhv, rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(30, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Division_Simple) {
    // arrange
    NumberLiteral *lhv = new NumberLiteral{dummyToken, 10};
    NumberLiteral *rhv = new NumberLiteral{dummyToken, 2};
    DivisionExpression expr{lhv, rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(5, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Modulo_Simple) {
    // arrange
    NumberLiteral *lhv = new NumberLiteral{dummyToken, 21};
    NumberLiteral *rhv = new NumberLiteral{dummyToken, 5};
    ModuloExpression expr{lhv, rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(1, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Exponent_Simple) {
    // arrange
    NumberLiteral *lhv = new NumberLiteral{dummyToken, 2};
    NumberLiteral *rhv = new NumberLiteral{dummyToken, 4};
    ExponentExpression expr{lhv, rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(16, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Order_MultDivBeforeAdd) {
    // arrange
    NumberLiteral *lhv = new NumberLiteral{dummyToken, 1};
    NumberLiteral *multlhv = new NumberLiteral{dummyToken, 2};
    NumberLiteral *multrhv = new NumberLiteral{dummyToken, 3};
    MultiplicationExpression *mult = new MultiplicationExpression{multlhv, multrhv};
    NumberLiteral *divrhv = new NumberLiteral{dummyToken, 4};
    DivisionExpression *div = new DivisionExpression{mult, divrhv};
    AdditionExpression expr{lhv, div};

    // 1 + 2 * 3 / 4
    //
    //     +
    //    1 /
    //     * 4
    //    2 3

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(2.5, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Function_SimpleAddition) {
    // arrange

    // act

    // assert

    // TODO: Implement unit test
}

TEST_F(ExpressionEvaluatorTest, Order_ParentBeforeEverything) {
    // arrange
    NumberLiteral *addl = new NumberLiteral{dummyToken, 5};
    NumberLiteral *addr = new NumberLiteral{dummyToken, 2};
    AdditionExpression *add = new AdditionExpression{addl, addr};
    NumberLiteral *multr = new NumberLiteral{dummyToken, 5};
    MultiplicationExpression mult{add, multr};

    // (5 + 2) * 5
    //
    //     *
    //    + 5
    //   5 2

    // act
    Value *value = evaluator.evaluate(&scope, mult);

    // assert
    ASSERT_EQ(35, value->asNumber());
}
