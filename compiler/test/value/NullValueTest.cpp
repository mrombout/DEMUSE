#include <gtest/gtest.h>
#include <value/NullValue.h>
#include "value/NullValue.h"
#include "Token.h"

class NullValueTest : public ::testing::Test {
protected:
    NullValueTest() :
            token(dem::lexer::TokenType::UNKNOWN, "", dem::lexer::TokenPosition()) {

    }

    dem::lexer::Token token;
};

TEST_F(NullValueTest, Add_ThrowsException) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // act / assert
    ASSERT_ANY_THROW({ a.add(&b); });
}

TEST_F(NullValueTest, Subtract_ThrowsException) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // act / assert
    ASSERT_ANY_THROW({ a.subtract(&b); });
}

TEST_F(NullValueTest, Multiply_ThrowsException) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // act / assert
    ASSERT_ANY_THROW({ a.multiply(&b); });
}

TEST_F(NullValueTest, Divide_ThrowsException) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // act / assert
    ASSERT_ANY_THROW({ a.divide(&b); });
}

TEST_F(NullValueTest, Modulo_ThrowsException) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a.modulo(&b); });
}

TEST_F(NullValueTest, Exponent_ThrowsException) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a.exponent(&b); });
}

TEST_F(NullValueTest, AsNumber_ReturnsMIDINoteNumber) {
    // arrange
    dem::compiler::NullValue a;

    // assert / act
    ASSERT_ANY_THROW({ a.asNumber(); });
}

TEST_F(NullValueTest, AsBool_ReturnsTrueWhenTrue) {
    // arrange
    dem::compiler::NullValue a;

    // assert / act
    ASSERT_ANY_THROW({ a.asBool(); });
}

TEST_F(NullValueTest, AsString_ReturnsNoteRepr) {
    // arrange
    dem::compiler::NullValue a;

    // assert / act
    ASSERT_ANY_THROW({ a.asString(); });
}

TEST_F(NullValueTest, AsNote_ThrowsException) {
    // arrange
    dem::compiler::NullValue a;

    // assert / act
    ASSERT_ANY_THROW({ a.asNote(); });
}

TEST_F(NullValueTest, Equals_AreEqual_ThrowsException) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a == b; });
}

TEST_F(NullValueTest, Equals_NotEqual_ReturnsFalse) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a == b; });
}

TEST_F(NullValueTest, NotEquals_AreEqual_ReturnsFalse) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a != b; });
}

TEST_F(NullValueTest, NotEquals_NotEqual_ReturnsTrue) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a != b; });
}

TEST_F(NullValueTest, SmallerThan_IsSmaller_ReturnsTrue) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a < b; });
}

TEST_F(NullValueTest, SmallerThan_IsEqual_ReturnsFalse) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a < b; });
}

TEST_F(NullValueTest, SmallerThan_IsLarger_ReturnsFalse) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a < b; });
}

TEST_F(NullValueTest, SmallerThanOrEqual_IsSmaller_ReturnsTrue) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a <= b; });
}

TEST_F(NullValueTest, SmallerThanOrEqual_IsEqual_ReturnsTrue) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a <= b; });
}

TEST_F(NullValueTest, SmallerThanOrEqual_IsLarger_ReturnsFalse) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a <= b; });
}


TEST_F(NullValueTest, LargerThan_IsSmaller_ReturnsFalse) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a > b; });
}

TEST_F(NullValueTest, LargerThan_IsEqual_ReturnsFalse) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a > b; });
}

TEST_F(NullValueTest, LargerThan_IsLarger_ReturnsTrue) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a > b; });
}

TEST_F(NullValueTest, LargerThanOrEqual_IsSmaller_ReturnsFalse) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a >= b; });
}

TEST_F(NullValueTest, LargerThanOrEqual_IsEqual_ReturnsTrue) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a >= b; });
}

TEST_F(NullValueTest, LargerThanOrEqual_IsLarger_ReturnsTrue) {
    // arrange
    dem::compiler::NullValue a;
    dem::compiler::NullValue b;

    // assert / act
    ASSERT_ANY_THROW({ a >= b; });
}

TEST_F(NullValueTest, ArrayAccess_NegativeIndex_ThrowsException) {
    // arrange
    dem::compiler::NullValue a;

    // assert / act
    ASSERT_ANY_THROW({ a[-1]; });
}

TEST_F(NullValueTest, ArrayAccess_IndexNotExist_ThrowsException) {
    // arrange
    dem::compiler::NullValue a;

    // assert / act
    ASSERT_ANY_THROW({ a[8]; });
}

TEST_F(NullValueTest, ArrayAccess_IndexExist_ReturnsValue) {
    // arrange
    dem::compiler::NullValue a;

    // assert / act
    ASSERT_ANY_THROW({ a[0]; });
}

TEST_F(NullValueTest, PropertyAccess_ThrowsException) {
    // arrange
    dem::compiler::NullValue a;

    // assert / act
    ASSERT_ANY_THROW({ a["propertyName"]; });
}

TEST_F(NullValueTest, Call_ThrowsException) {
    // arrange
    dem::compiler::NullValue a;

    // assert / act
    ASSERT_ANY_THROW({ a(); });
}