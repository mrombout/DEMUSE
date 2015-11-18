#include <gtest/gtest.h>
#include "factory/WhileFactory.h"

class WhileFactoryTest : public ::testing::Test {
protected:
    WhileFactoryTest() {

    }

    dem::parser::WhileFactory factory;
};

TEST_F(WhileFactoryTest, SimpleWhile) {

}
