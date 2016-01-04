#include <gtest/gtest.h>
#include "value/TextValue.h"

class TextValueTest : public ::testing::Test {

};

TEST_F(TextValueTest, Add_AddsToString) {
    // arrange
    dem::compiler::TextValue a{"Yin"};
    dem::compiler::TextValue b{"Yang"};

    // act
    dem::compiler::Value *result = a.add(&b);

    // assert
    ASSERT_EQ("YinYang", result->asString());
}

TEST_F(TextValueTest, Subtract_ThrowsException) {
    // arrange
    dem::compiler::TextValue a{"Left"};
    dem::compiler::TextValue b{"Right"};

    // act / assert
    ASSERT_ANY_THROW({ a.subtract(&b); });
}

TEST_F(TextValueTest, Multiply_ThrowsException) {
    // arrange
    dem::compiler::TextValue a{"Left"};
    dem::compiler::TextValue b{"Right"};

    // act / assert
    ASSERT_ANY_THROW({ a.multiply(&b); });
}

TEST_F(TextValueTest, Divide_ThrowsException) {
    // arrange
    dem::compiler::TextValue a{"Left"};
    dem::compiler::TextValue b{"Right"};

    // act / assert
    ASSERT_ANY_THROW({ a.divide(&b); });
}

TEST_F(TextValueTest, Modulo_ThrowsException) {
    // arrange
    dem::compiler::TextValue a{"Left"};
    dem::compiler::TextValue b{"Right"};

    // assert / act
    ASSERT_ANY_THROW({ a.modulo(&b); });
}

TEST_F(TextValueTest, AsNumber_ValidNumber_ReturnsNumberAsString) {
    // arrange
    dem::compiler::TextValue a{"3"};

    // act
    double result = a.asNumber();

    // assert
    ASSERT_EQ(3.0, result);
}

TEST_F(TextValueTest, AsNumber_InvalidNumber_ThrowsException) {
    // arrange
    dem::compiler::TextValue a{""};

    // act / assert
    ASSERT_ANY_THROW({
         a.asNumber();
    });
}

TEST_F(TextValueTest, AsBool_Empty_ReturnsFalse) {
    // arrange
    dem::compiler::TextValue a{""};

    // act
    bool result = a.asBool();

    // assert
    ASSERT_FALSE(result);
}

TEST_F(TextValueTest, AsBool_NotEmpty_ReturnsTrue) {
    // arrange
    dem::compiler::TextValue a{"Foo"};

    // act
    bool result = a.asBool();

    // assert
    ASSERT_TRUE(result);
}

TEST_F(TextValueTest, AsString_ReturnsSameString) {
    // arrange
    dem::compiler::TextValue a{"Hello?"};

    // act
    std::string result = a.asString();

    // assert
    ASSERT_EQ("Hello?", result);
}

TEST_F(TextValueTest, Equals_AreEqual_ReturnsTrue) {
    // arrange
    dem::compiler::TextValue a{"Left"};
    dem::compiler::TextValue b{"Left"};

    // act
    bool result = (a == b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(TextValueTest, Equals_NotEqual_ReturnsFalse) {
    // arrange
    dem::compiler::TextValue a{"Left"};
    dem::compiler::TextValue b{"Right"};

    // act
    bool result = (a == b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(TextValueTest, NotEquals_AreEqual_ReturnsFalse) {
    // arrange
    dem::compiler::TextValue a{"Left"};
    dem::compiler::TextValue b{"Left"};

    // act
    bool result = (a != b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(TextValueTest, NotEquals_NotEqual_ReturnsTrue) {
    // arrange
    dem::compiler::TextValue a{"Left"};
    dem::compiler::TextValue b{"Right"};

    // act
    bool result = (a != b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(TextValueTest, SmallerThan_IsSmaller_ReturnsTrue) {
    // arrange
    dem::compiler::TextValue a{"A"};
    dem::compiler::TextValue b{"B"};

    // act
    bool result = (a < b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(TextValueTest, SmallerThan_IsEqual_ReturnsFalse) {
    // arrange
    dem::compiler::TextValue a{"A"};
    dem::compiler::TextValue b{"A"};

    // act
    bool result = (a < b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(TextValueTest, SmallerThan_IsLarger_ReturnsFalse) {
    // arrange
    dem::compiler::TextValue a{"B"};
    dem::compiler::TextValue b{"A"};

    // act
    bool result = (a < b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(TextValueTest, SmallerThanOrEqual_IsSmaller_ReturnsTrue) {
    // arrange
    dem::compiler::TextValue a{"A"};
    dem::compiler::TextValue b{"B"};

    // act
    bool result = (a <= b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(TextValueTest, SmallerThanOrEqual_IsEqual_ReturnsTrue) {
    // arrange
    dem::compiler::TextValue a{"A"};
    dem::compiler::TextValue b{"A"};

    // act
    bool result = (a <= b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(TextValueTest, SmallerThanOrEqual_IsLarger_ReturnsFalse) {
    // arrange
    dem::compiler::TextValue a{"B"};
    dem::compiler::TextValue b{"A"};

    // act
    bool result = (a <= b);

    // assert
    ASSERT_FALSE(result);
}


TEST_F(TextValueTest, LargerThan_IsSmaller_ReturnsFalse) {
    // arrange
    dem::compiler::TextValue a{"A"};
    dem::compiler::TextValue b{"B"};

    // act
    bool result = (a > b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(TextValueTest, LargerThan_IsEqual_ReturnsFalse) {
    // arrange
    dem::compiler::TextValue a{"A"};
    dem::compiler::TextValue b{"A"};

    // act
    bool result = (a > b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(TextValueTest, LargerThan_IsLarger_ReturnsTrue) {
    // arrange
    dem::compiler::TextValue a{"B"};
    dem::compiler::TextValue b{"A"};

    // act
    bool result = (a > b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(TextValueTest, LargerThanOrEqual_IsSmaller_ReturnsFalse) {
    // arrange
    dem::compiler::TextValue a{"A"};
    dem::compiler::TextValue b{"B"};

    // act
    bool result = (a >= b);

    // assert
    ASSERT_FALSE(result);
}

TEST_F(TextValueTest, LargerThanOrEqual_IsEqual_ReturnsTrue) {
    // arrange
    dem::compiler::TextValue a{"A"};
    dem::compiler::TextValue b{"A"};

    // act
    bool result = (a >= b);

    // assert
    ASSERT_TRUE(result);
}

TEST_F(TextValueTest, LargerThanOrEqual_IsLarger_ReturnsTrue) {
    // arrange
    dem::compiler::TextValue a{"B"};
    dem::compiler::TextValue b{"A"};

    // act
    bool result = (a >= b);

    // assert
    ASSERT_TRUE(result);
}


TEST_F(TextValueTest, ArrayAccess_NegativeIndex_ThrowsException) {
    // arrange
    dem::compiler::TextValue a{"Lorum Ipsum"};

    // assert / act
    ASSERT_ANY_THROW({ a[-1]; });
}

TEST_F(TextValueTest, ArrayAccess_IndexNotExist_ThrowsException) {
    // arrange
    dem::compiler::TextValue a{"Lorum Ipsum"};

    // assert / act
    ASSERT_ANY_THROW({ a[8]; });
}

TEST_F(TextValueTest, ArrayAccess_IndexExist_ThrowsException) {
    // arrange
    dem::compiler::TextValue a{"Lorum Ipsum"};

    // assert / act
    ASSERT_ANY_THROW({ a[0]; });
}

TEST_F(TextValueTest, PropertyAccess_ReturnsProperty) {
    // arrange
    dem::compiler::TextValue a{"Lorum Ipsum"};

    // assert / act
    ASSERT_ANY_THROW({ a[0]; });
}

TEST_F(TextValueTest, Call_ThrowsException) {
    // arrange
    dem::compiler::TextValue a{"Lorum Ipsum"};

    // assert / act
    ASSERT_ANY_THROW({ a(); });
}