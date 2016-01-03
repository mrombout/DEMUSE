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
    dem::compiler::MidiCompiler compiler; // TODO: replace with mock
    dem::compiler::ExpressionEvaluator evaluator;

    dem::lexer::Token dummyToken;
};

TEST_F(ExpressionEvaluatorTest, Addition_Simple) {
    // arrange
    NumberLiteral lhv{dummyToken, 5};
    NumberLiteral rhv{dummyToken, 6};
    AdditionExpression expr{&lhv, &rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(11, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Subtraction_Simple) {
    // arrange
    NumberLiteral lhv{dummyToken, 5};
    NumberLiteral rhv{dummyToken, 6};
    SubtractionExpression expr{&lhv, &rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(-1, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Multiplication_Simple) {
    // arrange
    NumberLiteral lhv{dummyToken, 5};
    NumberLiteral rhv{dummyToken, 6};
    MultiplicationExpression expr{&lhv, &rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(30, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Division_Simple) {
    // arrange
    NumberLiteral lhv{dummyToken, 10};
    NumberLiteral rhv{dummyToken, 2};
    DivisionExpression expr{&lhv, &rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(5, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Modulo_Simple) {
    // arrange
    NumberLiteral lhv{dummyToken, 21};
    NumberLiteral rhv{dummyToken, 5};
    ModuloExpression expr{&lhv, &rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(1, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Exponent_Simple) {
    // arrange
    NumberLiteral lhv{dummyToken, 2};
    NumberLiteral rhv{dummyToken, 4};
    ExponentExpression expr{&lhv, &rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(16, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Order_MultDivBeforeAdd) {
    // arrange
    NumberLiteral lhv{dummyToken, 1};
    NumberLiteral multlhv{dummyToken, 2};
    NumberLiteral multrhv{dummyToken, 3};
    MultiplicationExpression mult{&multlhv, &multrhv};
    NumberLiteral divrhv{dummyToken, 4};
    DivisionExpression div{&mult, &divrhv};
    AdditionExpression expr{&lhv, &div};

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
    NumberLiteral addl{dummyToken, 5};
    NumberLiteral addr{dummyToken, 2};
    AdditionExpression add{&addl, &addr};
    NumberLiteral multr{dummyToken, 5};
    MultiplicationExpression mult{&add, &multr};

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
