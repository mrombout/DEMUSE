#include <gtest/gtest.h>
#include "value/NumberValue.h"

class NumberValueTest : public ::testing::Test {

};

TEST_F(NumberValueTest, Add_NumberNumber_CalculationCorrect) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{2};

    // act
    dem::compiler::Value *result = a.add(&b);

    // assert
    ASSERT_EQ(3, result->asNumber());
}

TEST_F(NumberValueTest, Subtract_NumberNumber_CalculationCorrect) {
    // arrange
    dem::compiler::NumberValue a{10};
    dem::compiler::NumberValue b{5};

    // act
    dem::compiler::Value *result = a.subtract(&b);

    // assert
    ASSERT_EQ(5, result->asNumber());
}

TEST_F(NumberValueTest, Multiply_NumberNumber_CalculationCorrect) {
    // arrange
    dem::compiler::NumberValue a{2};
    dem::compiler::NumberValue b{2};

    // act
    dem::compiler::Value *result = a.multiply(&b);

    // assert
    ASSERT_EQ(4, result->asNumber());
}

TEST_F(NumberValueTest, Divide_NumberNumber_CalculationCorrect) {
    // arrange
    dem::compiler::NumberValue a{10};
    dem::compiler::NumberValue b{2};

    // act
    dem::compiler::Value *result = a.divide(&b);

    // assert
    ASSERT_EQ(5, result->asNumber());
}

TEST_F(NumberValueTest, Modulo_NumberNumber_CalculationCorrect) {
    // arrange
    dem::compiler::NumberValue a{10};
    dem::compiler::NumberValue b{3};

    // act
    dem::compiler::Value *result = a.modulo(&b);

    // assert
    ASSERT_EQ(1, result->asNumber());
}

TEST_F(NumberValueTest, AsNumber_PositiveInteger) {
    // arrange
    dem::compiler::NumberValue a{1};

    // act
    double result = a.asNumber();

    // assert
    ASSERT_EQ(1.0, result);
}

TEST_F(NumberValueTest, AsNumber_NegativeInteger) {
    // arrange
    dem::compiler::NumberValue a{-1};

    // act
    double result = a.asNumber();

    // assert
    ASSERT_EQ(-1.0, result);
}

TEST_F(NumberValueTest, AsNumber_PositiveDouble) {
    // arrange
    dem::compiler::NumberValue a{1.5};

    // act
    double result = a.asNumber();

    // assert
    ASSERT_EQ(1.5, result);
}

TEST_F(NumberValueTest, AsNumber_NegativeDouble) {
    // arrange
    dem::compiler::NumberValue a{-1.5};

    // act
    double result = a.asNumber();

    // assert
    ASSERT_EQ(-1.5, result);
}

TEST_F(NumberValueTest, AsBool_PositiveInteger_ReturnsTrue) {
    // arrange
    dem::compiler::NumberValue a{1};

    // act
    bool result = a.asBool();

    // assert
    ASSERT_TRUE(result);
}

TEST_F(NumberValueTest, AsBool_ZeroInteger_ReturnsFalse) {
    // arrange
    dem::compiler::NumberValue a{0};

    // act
    bool result = a.asBool();

    // assert
    ASSERT_FALSE(result);
}

TEST_F(NumberValueTest, AsBool_NegativeInteger_ReturnsFalse) {
    // arrange
    dem::compiler::NumberValue a{-1};

    // act
    bool result = a.asBool();

    // assert
    ASSERT_FALSE(result);
}

TEST_F(NumberValueTest, AsString_PositiveInteger_ReturnsNumberAsString) {
    // arrange
    dem::compiler::NumberValue a{1};

    // act
    std::string result = a.asString();

    // assert
    ASSERT_EQ("1.000000", result);
}

TEST_F(NumberValueTest, AsString_NegativeInteger_ReturnsNumberAsString) {
    // arrange
    dem::compiler::NumberValue a{-1};

    // act
    std::string result = a.asString();

    // assert
    ASSERT_EQ("-1.000000", result);
}

TEST_F(NumberValueTest, Equals_AreEqual_ReturnsTrue) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{1};

    // act
    bool result = (a == b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(NumberValueTest, Equals_NotEqual_ReturnsFalse) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{2};

    // act
    bool result = (a == b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(NumberValueTest, NotEquals_AreEqual_ReturnsFalse) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{1};

    // act
    bool result = (a != b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(NumberValueTest, NotEquals_NotEqual_ReturnsTrue) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{2};

    // act
    bool result = (a != b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(NumberValueTest, SmallerThan_IsSmaller_ReturnsTrue) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{2};

    // act
    bool result = (a < b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(NumberValueTest, SmallerThan_IsEqual_ReturnsFalse) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{1};

    // act
    bool result = (a < b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(NumberValueTest, SmallerThan_IsLarger_ReturnsFalse) {
    // arrange
    dem::compiler::NumberValue a{2};
    dem::compiler::NumberValue b{1};

    // act
    bool result = (a < b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(NumberValueTest, SmallerThanOrEqual_IsSmaller_ReturnsTrue) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{2};

    // act
    bool result = (a <= b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(NumberValueTest, SmallerThanOrEqual_IsEqual_ReturnsTrue) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{1};

    // act
    bool result = (a <= b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(NumberValueTest, SmallerThanOrEqual_IsLarger_ReturnsFalse) {
    // arrange
    dem::compiler::NumberValue a{2};
    dem::compiler::NumberValue b{1};

    // act
    bool result = (a <= b);

    // assert
    ASSERT_FALSE(result);
}


TEST_F(NumberValueTest, LargerThan_IsSmaller_ReturnsFalse) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{2};

    // act
    bool result = (a > b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(NumberValueTest, LargerThan_IsEqual_ReturnsFalse) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{1};

    // act
    bool result = (a > b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(NumberValueTest, LargerThan_IsLarger_ReturnsTrue) {
    // arrange
    dem::compiler::NumberValue a{2};
    dem::compiler::NumberValue b{1};

    // act
    bool result = (a > b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(NumberValueTest, LargerThanOrEqual_IsSmaller_ReturnsFalse) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{2};

    // act
    bool result = (a >= b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(NumberValueTest, LargerThanOrEqual_IsEqual_ReturnsTrue) {
    // arrange
    dem::compiler::NumberValue a{1};
    dem::compiler::NumberValue b{1};

    // act
    bool result = (a >= b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(NumberValueTest, LargerThanOrEqual_IsLarger_ReturnsTrue) {
    // arrange
    dem::compiler::NumberValue a{2};
    dem::compiler::NumberValue b{1};

    // act
    bool result = (a >= b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(NumberValueTest, ArrayAccess_NegativeIndex_ThrowsException) {
    // arrange
    dem::compiler::NumberValue a{2};

    // assert / act
    ASSERT_ANY_THROW({ a[-1]; });
}

TEST_F(NumberValueTest, ArrayAccess_IndexNotExist_ThrowsException) {
    // arrange
    dem::compiler::NumberValue a{2};

    // assert / act
    ASSERT_ANY_THROW({ a[8]; });
}

TEST_F(NumberValueTest, ArrayAccess_IndexExist_ReturnsValue) {
    // arrange
    dem::compiler::NumberValue a{2};

    // assert / act
    ASSERT_ANY_THROW({ a[0]; });
}

TEST_F(NumberValueTest, PropertyAccess_ThrowsException) {
    // arrange
    dem::compiler::NumberValue a{2};

    // assert / act
    ASSERT_ANY_THROW({ a["propertyName"]; });
}

TEST_F(NumberValueTest, Call_ThrowsException) {
    // arrange
    dem::compiler::NumberValue a{2};

    // assert / act
    ASSERT_ANY_THROW({ a(); });
}