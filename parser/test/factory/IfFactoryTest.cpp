#include <gtest/gtest.h>
#include "factory/IfFactory.h"

class IfFactoryTest : public ::testing::Test {
protected:
    IfFactoryTest() {

    }

    dem::parser::IfFactory factory;
};

TEST_F(IfFactoryTest, IfOnly) {

}

TEST_F(IfFactoryTest, IfElse) {

}

TEST_F(IfFactoryTest, IfNoBlock) {

}

TEST_F(IfFactoryTest, IfElseNoBlock) {

}

TEST_F(IfFactoryTest, IfBlockElseNoBlock) {

}

TEST_F(IfFactoryTest, IfNoBlockElseBlock) {

}