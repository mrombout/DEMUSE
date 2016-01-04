#include <gtest/gtest.h>
#include "value/BooleanValue.h"

class BooleanValueTest : public ::testing::Test {

};

TEST_F(BooleanValueTest, Add_ThrowsException) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{true};

    // act / assert
    ASSERT_ANY_THROW({
         a.add(&b);
    });
}

TEST_F(BooleanValueTest, Subtract_ThrowsException) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{true};

    // act / assert
    ASSERT_ANY_THROW({
        a.subtract(&b);
    });
}

TEST_F(BooleanValueTest, Multiply_ThrowsException) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{true};

    // act / assert
    ASSERT_ANY_THROW({
        a.multiply(&b);
    });
}

TEST_F(BooleanValueTest, Divide_ThrowsException) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{true};

    // act / assert
    ASSERT_ANY_THROW({
        a.divide(&b);
    });
}

TEST_F(BooleanValueTest, Modulo_ThrowsException) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{true};

    // assert / act
    ASSERT_ANY_THROW({
        a.modulo(&b);
    });
}

TEST_F(BooleanValueTest, AsNumber_ReturnsOneWhenTrue) {
    // arrange
    dem::compiler::BooleanValue a{true};

    // act
    double result = a.asNumber();

    // assert
    ASSERT_EQ(1.0, result);
}

TEST_F(BooleanValueTest, AsNumber_ReturnsZeroWhenFalse) {
    // arrange
    dem::compiler::BooleanValue a{false};

    // act
    double result = a.asNumber();

    // assert
    ASSERT_EQ(0.0, result);
}

TEST_F(BooleanValueTest, AsBool_ReturnsTrueWhenTrue) {
    // arrange
    dem::compiler::BooleanValue a{true};

    // act
    bool result = a.asBool();

    // assert
    ASSERT_TRUE(result);
}

TEST_F(BooleanValueTest, AsBool_ReturnsFalseWhenFalse) {
    // arrange
    dem::compiler::BooleanValue a{false};

    // act
    bool result = a.asBool();

    // assert
    ASSERT_FALSE(result);
}

TEST_F(BooleanValueTest, AsString_ReturnsTrueWhenTrue) {
    // arrange
    dem::compiler::BooleanValue a{true};

    // act
    std::string result = a.asString();

    // assert
    ASSERT_EQ("true", result);
}

TEST_F(BooleanValueTest, AsString_ReturnsFalseWhenFalse) {
    // arrange
    dem::compiler::BooleanValue a{false};

    // act
    std::string result = a.asString();

    // assert
    ASSERT_EQ("false", result);
}

TEST_F(BooleanValueTest, Equals_AreEqual_ReturnsTrue) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{true};

    // act
    bool result = (a == b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(BooleanValueTest, Equals_NotEqual_ReturnsFalse) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{false};

    // act
    bool result = (a == b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(BooleanValueTest, NotEquals_AreEqual_ReturnsFalse) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{true};

    // act
    bool result = (a != b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(BooleanValueTest, NotEquals_NotEqual_ReturnsTrue) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{false};

    // act
    bool result = (a != b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(BooleanValueTest, SmallerThan_IsSmaller_ReturnsTrue) {
    // arrange
    dem::compiler::BooleanValue a{false};
    dem::compiler::BooleanValue b{true};

    // act
    bool result = (a < b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(BooleanValueTest, SmallerThan_IsEqual_ReturnsFalse) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{true};

    // act
    bool result = (a < b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(BooleanValueTest, SmallerThan_IsLarger_ReturnsFalse) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{false};

    // act
    bool result = (a < b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(BooleanValueTest, SmallerThanOrEqual_IsSmaller_ReturnsTrue) {
    // arrange
    dem::compiler::BooleanValue a{false};
    dem::compiler::BooleanValue b{true};

    // act
    bool result = (a <= b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(BooleanValueTest, SmallerThanOrEqual_IsEqual_ReturnsTrue) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{true};

    // act
    bool result = (a <= b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(BooleanValueTest, SmallerThanOrEqual_IsLarger_ReturnsFalse) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{false};

    // act
    bool result = (a <= b);

    // assert
    ASSERT_FALSE(result);
}


TEST_F(BooleanValueTest, LargerThan_IsSmaller_ReturnsFalse) {
    // arrange
    dem::compiler::BooleanValue a{false};
    dem::compiler::BooleanValue b{true};

    // act
    bool result = (a > b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(BooleanValueTest, LargerThan_IsEqual_ReturnsFalse) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{true};

    // act
    bool result = (a > b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(BooleanValueTest, LargerThan_IsLarger_ReturnsTrue) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{false};

    // act
    bool result = (a > b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(BooleanValueTest, LargerThanOrEqual_IsSmaller_ReturnsFalse) {
    // arrange
    dem::compiler::BooleanValue a{false};
    dem::compiler::BooleanValue b{true};

    // act
    bool result = (a >= b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(BooleanValueTest, LargerThanOrEqual_IsEqual_ReturnsTrue) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{true};

    // act
    bool result = (a >= b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(BooleanValueTest, LargerThanOrEqual_IsLarger_ReturnsTrue) {
    // arrange
    dem::compiler::BooleanValue a{true};
    dem::compiler::BooleanValue b{false};

    // act
    bool result = (a >= b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(BooleanValueTest, ArrayAccess_ThrowsException) {
    // arrange
    dem::compiler::BooleanValue a{true};

    // assert / act
    ASSERT_ANY_THROW({ a[-1]; });
}

TEST_F(BooleanValueTest, PropertyAccess_ThrowsException) {
    // arrange
    dem::compiler::BooleanValue a{true};

    // assert / act
    ASSERT_ANY_THROW({ a["propertyName"]; });
}

TEST_F(BooleanValueTest, Call_ThrowsException) {
    // arrange
    dem::compiler::BooleanValue a{true};

    // assert / act
    ASSERT_ANY_THROW({ a(); });
}