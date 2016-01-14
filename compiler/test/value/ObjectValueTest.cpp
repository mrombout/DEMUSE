#include <gtest/gtest.h>
#include "value/NumberValue.h"
#include "value/Variable.h"

class ObjectValueTest : public ::testing::Test {
protected:
    ObjectValueTest() :
            scope(nullptr) {

    }

    dem::compiler::ObjectValue scope;
};

TEST_F(ObjectValueTest, Add_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // act / assert
    ASSERT_ANY_THROW({ a.add(&b); });
}

TEST_F(ObjectValueTest, Subtract_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // act / assert
    ASSERT_ANY_THROW({ a.subtract(&b); });
}

TEST_F(ObjectValueTest, Multiply_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // act / assert
    ASSERT_ANY_THROW({ a.multiply(&b); });
}

TEST_F(ObjectValueTest, Divide_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // act / assert
    ASSERT_ANY_THROW({ a.divide(&b); });
}

TEST_F(ObjectValueTest, Modulo_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a.modulo(&b); });
}

TEST_F(ObjectValueTest, Exponent_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a.exponent(&b); });
}

TEST_F(ObjectValueTest, AsNumber_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;

    // assert / act
    ASSERT_ANY_THROW({ a.asNumber(); });
}

TEST_F(ObjectValueTest, AsBool_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;

    // assert / act
    ASSERT_ANY_THROW({ a.asBool(); });
}

TEST_F(ObjectValueTest, AsString_ReturnsObject) {
    // arrange
    dem::compiler::ObjectValue a;

    // act
    std::string result = a.asString();

    // assert
    ASSERT_EQ("Object", result);
}

TEST_F(ObjectValueTest, AsNote_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;

    // assert / act
    ASSERT_ANY_THROW({ a.asNote(); });
}

TEST_F(ObjectValueTest, Equals_AreEqual_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a == b; });
}

TEST_F(ObjectValueTest, Equals_NotEqual_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a == b; });
}

TEST_F(ObjectValueTest, NotEquals_AreEqual_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a != b; });
}

TEST_F(ObjectValueTest, NotEquals_NotEqual_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a != b; });
}

TEST_F(ObjectValueTest, SmallerThan_IsSmaller_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a < b; });
}

TEST_F(ObjectValueTest, SmallerThan_IsEqual_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a < b; });
}

TEST_F(ObjectValueTest, SmallerThan_IsLarger_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a < b; });
}

TEST_F(ObjectValueTest, SmallerThanOrEqual_IsSmaller_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a <= b; });
}

TEST_F(ObjectValueTest, SmallerThanOrEqual_IsEqual_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a <= b; });
}

TEST_F(ObjectValueTest, SmallerThanOrEqual_IsLarger_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a <= b; });
}


TEST_F(ObjectValueTest, LargerThan_IsSmaller_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a > b; });
}

TEST_F(ObjectValueTest, LargerThan_IsEqual_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a > b; });
}

TEST_F(ObjectValueTest, LargerThan_IsLarger_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a > b; });
}

TEST_F(ObjectValueTest, LargerThanOrEqual_IsSmaller_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a >= b; });
}

TEST_F(ObjectValueTest, LargerThanOrEqual_IsEqual_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a >= b; });
}

TEST_F(ObjectValueTest, LargerThanOrEqual_IsLarger_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;
    dem::compiler::ObjectValue b;

    // assert / act
    ASSERT_ANY_THROW({ a >= b; });
}

TEST_F(ObjectValueTest, ArrayAccess_NegativeIndex_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;

    // assert / act
    ASSERT_ANY_THROW({ a[-1]; });
}

TEST_F(ObjectValueTest, ArrayAccess_IndexNotExist_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;

    // assert / act
    ASSERT_ANY_THROW({ a[8]; });
}

TEST_F(ObjectValueTest, ArrayAccess_IndexExist_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;

    // assert / act
    ASSERT_ANY_THROW({ a[0]; });
}

TEST_F(ObjectValueTest, PropertyAccess_ReturnsProperty) {
    // arrange
    dem::compiler::NumberValue value{3};

    dem::compiler::ObjectValue a;
    a.declareVariable(new dem::parser::Identifier("test"), &value);

    // act
    dem::compiler::Variable *result = a.variable(new dem::parser::Identifier("test"));

    // assert
    ASSERT_EQ(value.asNumber(), result->asNumber());
}

TEST_F(ObjectValueTest, Call_ThrowsException) {
    // arrange
    dem::compiler::ObjectValue a;

    // assert / act
    ASSERT_ANY_THROW({ a(scope); });
}