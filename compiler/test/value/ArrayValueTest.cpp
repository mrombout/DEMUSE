#include <gtest/gtest.h>
#include "value/ArrayValue.h"
#include "value/NumberValue.h"

class ArrayValueTest : public ::testing::Test {

};

TEST_F(ArrayValueTest, Add_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // act / assert
    ASSERT_ANY_THROW({
         a.add(&b);
    });
}

TEST_F(ArrayValueTest, Subtract_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // act / assert
    ASSERT_ANY_THROW({
        a.subtract(&b);
    });
}

TEST_F(ArrayValueTest, Multiply_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // act / assert
    ASSERT_ANY_THROW({
        a.multiply(&b);
    });
}

TEST_F(ArrayValueTest, Divide_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // act / assert
    ASSERT_ANY_THROW({
        a.divide(&b);
    });
}

TEST_F(ArrayValueTest, Modulo_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({
        a.modulo(&b);
    });
}

TEST_F(ArrayValueTest, Exponent_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({
        a.modulo(&b);
    });
}

TEST_F(ArrayValueTest, AsNumber_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({
        a.modulo(&b);
    });
}

TEST_F(ArrayValueTest, AsBool_ReturnsTrueWhenTrue) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({
        a.modulo(&b);
    });
}

TEST_F(ArrayValueTest, AsString_NonEmpty_ReturnsAllElementsAsString) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};

    // act
    std::string result = a.asString();

    // assert
    ASSERT_EQ("[1.000000, 2.000000, 3.000000]", result);
}

TEST_F(ArrayValueTest, AsString_Empty_ReturnsEmptyArrayRepr) {
    // arrange
    dem::compiler::ArrayValue a{{}};

    // act
    std::string result = a.asString();

    // assert
    ASSERT_EQ("[]", result);
}

TEST_F(ArrayValueTest, AsNote_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({
        a.modulo(&b);
    });
}

TEST_F(ArrayValueTest, Equals_AreEqual_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};

    // assert / act
    ASSERT_ANY_THROW({
        a == b;
    });
}

TEST_F(ArrayValueTest, Equals_NotEqual_ReturnsFalse) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({
        a == b;
    });
}

TEST_F(ArrayValueTest, NotEquals_AreEqual_ReturnsFalse) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};

    // assert / act
    ASSERT_ANY_THROW({
        a != b;
    });
}

TEST_F(ArrayValueTest, NotEquals_NotEqual_ReturnsTrue) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({
        a != b;
    });
}

TEST_F(ArrayValueTest, SmallerThan_IsSmaller_ReturnsTrue) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({
        a < b;
    });
}

TEST_F(ArrayValueTest, SmallerThan_IsEqual_ReturnsFalse) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};

    // assert / act
    ASSERT_ANY_THROW({
        a < b;
    });
}

TEST_F(ArrayValueTest, SmallerThan_IsLarger_ReturnsFalse) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};

    // assert / act
    ASSERT_ANY_THROW({
        a < b;
    });
}

TEST_F(ArrayValueTest, SmallerThanOrEqual_IsSmaller_ReturnsTrue) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({
        a <= b;
    });
}

TEST_F(ArrayValueTest, SmallerThanOrEqual_IsEqual_ReturnsTrue) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};

    // assert / act
    ASSERT_ANY_THROW({
        a <= b;
    });
}

TEST_F(ArrayValueTest, SmallerThanOrEqual_IsLarger_ReturnsFalse) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};

    // assert / act
    ASSERT_ANY_THROW({
        a <= b;
    });
}


TEST_F(ArrayValueTest, LargerThan_IsSmaller_ReturnsFalse) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({ a > b; });
}

TEST_F(ArrayValueTest, LargerThan_IsEqual_ReturnsFalse) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};

    // assert / act
    ASSERT_ANY_THROW({ a > b; });
}

TEST_F(ArrayValueTest, LargerThan_IsLarger_ReturnsTrue) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};

    // assert / act
    ASSERT_ANY_THROW({ a > b; });
}

TEST_F(ArrayValueTest, LargerThanOrEqual_IsSmaller_ReturnsFalse) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({ a >= b; });
}

TEST_F(ArrayValueTest, LargerThanOrEqual_IsEqual_ReturnsTrue) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};

    // assert / act
    ASSERT_ANY_THROW({ a >= b; });
}

TEST_F(ArrayValueTest, LargerThanOrEqual_IsLarger_ReturnsTrue) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};

    // assert / act
    ASSERT_ANY_THROW({ a >= b; });
}

TEST_F(ArrayValueTest, ArrayAccess_NegativeIndex_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({ a[-1]; });
}

TEST_F(ArrayValueTest, ArrayAccess_IndexNotExist_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({ a[8]; });
}

TEST_F(ArrayValueTest, ArrayAccess_IndexExist_ReturnsValue) {
    // arrange
    dem::compiler::ArrayValue b{{new dem::compiler::NumberValue(1), new dem::compiler::NumberValue(2), new dem::compiler::NumberValue(3)}};

    // act
    dem::compiler::Value *result = b[0];

    // assert
    ASSERT_EQ(1, result->asNumber());
}

TEST_F(ArrayValueTest, PropertyAccess_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({ a["propertyName"]; });
}

TEST_F(ArrayValueTest, Call_ThrowsException) {
    // arrange
    dem::compiler::ArrayValue a{{new dem::compiler::NumberValue(3), new dem::compiler::NumberValue(4), new dem::compiler::NumberValue(5)}};

    // assert / act
    ASSERT_ANY_THROW({ a(); });
}