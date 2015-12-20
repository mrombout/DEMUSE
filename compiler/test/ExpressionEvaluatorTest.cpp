#include <gtest/gtest.h>
#include "MuseMidiCompiler.h"
#include "ExpressionEvaluator.h"
#include "symbol/expression/AdditionExpression.h"
#include "symbol/expression/SubtractionExpression.h"
#include "symbol/expression/MultiplicationExpression.h"
#include "symbol/expression/NumberLiteral.h"
#include "value/Value.h"

using namespace dem::parser;
using namespace dem::compiler;

class ExpressionEvaluatorTest : public ::testing::Test {
protected:
    ExpressionEvaluatorTest() :
            scope(nullptr),
            evaluator(compiler) {

    }

    dem::compiler::Scope scope;
    dem::compiler::MidiCompiler compiler; // TODO: replace with mock
    dem::compiler::ExpressionEvaluator evaluator;
};

TEST_F(ExpressionEvaluatorTest, Addition_Simple) {
    // arrange
    NumberLiteral lhv{5};
    NumberLiteral rhv{6};
    AdditionExpression expr{&lhv, &rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(11, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Subtraction_Simple) {
    // arrange
    NumberLiteral lhv{5};
    NumberLiteral rhv{6};
    SubtractionExpression expr{&lhv, &rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(-1, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Multiplication_Simple) {
    // arrange
    NumberLiteral lhv{5};
    NumberLiteral rhv{6};
    MultiplicationExpression expr{&lhv, &rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(30, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Division_Simple) {
    // arrange
    NumberLiteral lhv{10};
    NumberLiteral rhv{2};
    DivisionExpression expr{&lhv, &rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(5, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Modulo_Simple) {
    // arrange
    NumberLiteral lhv{21};
    NumberLiteral rhv{5};
    ModuloExpression expr{&lhv, &rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(1, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Exponent_Simple) {
    // arrange
    NumberLiteral lhv{2};
    NumberLiteral rhv{4};
    ExponentExpression expr{&lhv, &rhv};

    // act
    Value *value = evaluator.evaluate(&scope, expr);

    // assert
    ASSERT_EQ(16, value->asNumber());
}

TEST_F(ExpressionEvaluatorTest, Order_MultDivBeforeAdd) {
    // arrange
    NumberLiteral lhv{1};
    NumberLiteral multlhv{2};
    NumberLiteral multrhv{3};
    MultiplicationExpression mult{&multlhv, &multrhv};
    NumberLiteral divrhv{4};
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
    NumberLiteral addl{5};
    NumberLiteral addr{2};
    AdditionExpression add{&addl, &addr};
    NumberLiteral multr{5};
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
