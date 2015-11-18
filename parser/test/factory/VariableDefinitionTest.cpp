#include <gtest/gtest.h>
#include "factory/VariableDefinitionFactory.h"

class VariableDefinitionFactory : public ::testing::Test {
protected:
    VariableDefinitionFactory() {

    }

    dem::parser::VariableDefinitionFactory factory;
};

TEST_F(VariableDefinitionFactory, PrimitiveVariableDefinition) {

}
