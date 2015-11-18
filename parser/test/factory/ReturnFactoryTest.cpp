#include <gtest/gtest.h>
#include "factory/ReturnFactory.h"

class ReturnFactoryTest : public ::testing::Test {
protected:
    ReturnFactoryTest() {

    }

    dem::parser::ReturnFactory factory;
};

TEST_F(ReturnFactoryTest, ReturnPrimitive) {

}
