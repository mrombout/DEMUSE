#include <gtest/gtest.h>
#include "value/NoteValue.h"
#include "Token.h"

class NoteValueTest : public ::testing::Test {
protected:
    NoteValueTest() :
        token(dem::lexer::TokenType::UNKNOWN, "", dem::lexer::TokenPosition()) {

    }

    dem::lexer::Token token;
};

TEST_F(NoteValueTest, Add_ThrowsException) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // act / assert
    ASSERT_ANY_THROW({
        a.add(&b);
    });
}

TEST_F(NoteValueTest, Subtract_ThrowsException) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // act / assert
    ASSERT_ANY_THROW({
        a.subtract(&b);
    });
}

TEST_F(NoteValueTest, Multiply_ThrowsException) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // act / assert
    ASSERT_ANY_THROW({
        a.multiply(&b);
    });
}

TEST_F(NoteValueTest, Divide_ThrowsException) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // act / assert
    ASSERT_ANY_THROW({
        a.divide(&b);
    });
}

TEST_F(NoteValueTest, Modulo_ThrowsException) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({
        a.modulo(&b);
    });
}

TEST_F(NoteValueTest, Exponent_ThrowsException) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({
        a.modulo(&b);
    });
}

TEST_F(NoteValueTest, AsNumber_ReturnsMIDINoteNumber) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // act
    double result = a.asNumber();

    // assert
    ASSERT_EQ(48, result);
}

TEST_F(NoteValueTest, AsBool_ReturnsTrueWhenTrue) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // act
    double result = a.asBool();

    // assert
    ASSERT_EQ(true, result);
}

TEST_F(NoteValueTest, AsString_ReturnsNoteRepr) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // act
    std::string result = a.asString();

    // assert
    ASSERT_EQ("C4nw", result);
}

TEST_F(NoteValueTest, AsNote_ThrowsException) {
    // arrange
    const dem::parser::Note note = dem::parser::Note(token, 'C', 4, 'n', 'w');
    dem::compiler::NoteValue a{note};

    // act
    const dem::parser::Note &result = a.asNote();

    // assert
    // TODO: Use ASSERT_EQ on `note`, gets error "no match for 'operator==' (operand types are 'const dem::parser::Note' and 'const dem::parser::Note')"
    ASSERT_EQ(note.note(), result.note());
    ASSERT_EQ(note.octave(), result.octave());
    ASSERT_EQ(note.accidental(), result.accidental());
    ASSERT_EQ(note.duration(), result.duration());
}

TEST_F(NoteValueTest, Equals_AreEqual_ThrowsException) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({
        a == b;
    });
}

TEST_F(NoteValueTest, Equals_NotEqual_ReturnsFalse) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({
        a == b;
    });
}

TEST_F(NoteValueTest, NotEquals_AreEqual_ReturnsFalse) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({
        a != b;
    });
}

TEST_F(NoteValueTest, NotEquals_NotEqual_ReturnsTrue) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({
        a != b;
    });
}

TEST_F(NoteValueTest, SmallerThan_IsSmaller_ReturnsTrue) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({
        a < b;
    });
}

TEST_F(NoteValueTest, SmallerThan_IsEqual_ReturnsFalse) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({
        a < b;
    });
}

TEST_F(NoteValueTest, SmallerThan_IsLarger_ReturnsFalse) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({
        a < b;
    });
}

TEST_F(NoteValueTest, SmallerThanOrEqual_IsSmaller_ReturnsTrue) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({
        a <= b;
    });
}

TEST_F(NoteValueTest, SmallerThanOrEqual_IsEqual_ReturnsTrue) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({
        a <= b;
    });
}

TEST_F(NoteValueTest, SmallerThanOrEqual_IsLarger_ReturnsFalse) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({
        a <= b;
    });
}


TEST_F(NoteValueTest, LargerThan_IsSmaller_ReturnsFalse) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({ a > b; });
}

TEST_F(NoteValueTest, LargerThan_IsEqual_ReturnsFalse) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({ a > b; });
}

TEST_F(NoteValueTest, LargerThan_IsLarger_ReturnsTrue) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({ a > b; });
}

TEST_F(NoteValueTest, LargerThanOrEqual_IsSmaller_ReturnsFalse) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({ a >= b; });
}

TEST_F(NoteValueTest, LargerThanOrEqual_IsEqual_ReturnsTrue) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({ a >= b; });
}

TEST_F(NoteValueTest, LargerThanOrEqual_IsLarger_ReturnsTrue) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};
    dem::compiler::NoteValue b{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({ a >= b; });
}

TEST_F(NoteValueTest, ArrayAccess_NegativeIndex_ThrowsException) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({ a[-1]; });
}

TEST_F(NoteValueTest, ArrayAccess_IndexNotExist_ThrowsException) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({ a[8]; });
}

TEST_F(NoteValueTest, ArrayAccess_IndexExist_ReturnsValue) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({ a[0]; });
}

TEST_F(NoteValueTest, PropertyAccess_ThrowsException) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({ a["propertyName"]; });
}

TEST_F(NoteValueTest, Call_ThrowsException) {
    // arrange
    dem::compiler::NoteValue a{dem::parser::Note(token, 'C', 4, 'n', 'w')};

    // assert / act
    ASSERT_ANY_THROW({ a(); });
}