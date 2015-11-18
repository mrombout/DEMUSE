#include <gtest/gtest.h>
#include "factory/ParameterListFactory.h"

class ParameterListFactory : public ::testing::Test {
protected:
    ParameterListFactory() {

    }

    dem::parser::ParameterListFactory factory;
};

TEST_F(ParameterListFactory, SingleParameter) {

}

TEST_F(ParameterListFactory, ThreeParameters) {

}
