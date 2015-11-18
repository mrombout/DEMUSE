#include <gtest/gtest.h>
#include "factory/IdentifierFactory.h"

class IdentifierFactoryTest : public ::testing::Test {
protected:
    IdentifierFactoryTest() {

    }

    dem::parser::IdentifierFactory factory;
};

TEST_F(IdentifierFactoryTest, LetterOnlyIdentifier) {

}
