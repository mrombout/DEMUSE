#include <gtest/gtest.h>
#include "VariableDeclarationFactory.h"

class VariableDefinitionFactory : public ::testing::Test {
protected:
    VariableDefinitionFactory() {

    }

    dem::parser::VariableDeclarationFactory factory;
};

TEST_F(VariableDefinitionFactory, PrimitiveVariableDefinition) {

}
