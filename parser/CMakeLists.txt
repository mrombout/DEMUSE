cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Parser VERSION 0.1 LANGUAGES CXX)

set(Parser_SRCS
    inc/Visitor.h
    src/Visitor.cpp

    inc/Visitable.h
    src/Visitable.cpp

    inc/Parser.h

    inc/MuseParser.h
    src/MuseParser.cpp

    inc/symbol/Symbol.h
    src/symbol/Symbol.cpp

    inc/symbol/Program.h
    src/symbol/Program.cpp

    inc/symbol/Statement.h
    src/symbol/Statement.cpp

    inc/symbol/Assignment.h
    src/symbol/Assignment.cpp

    inc/symbol/Return.h
    src/symbol/Return.cpp

    inc/symbol/Break.h
    src/symbol/Break.cpp

    inc/symbol/Continue.h
    src/symbol/Continue.cpp

    inc/symbol/If.h
    src/symbol/If.cpp

    inc/symbol/While.h
    src/symbol/While.cpp

    inc/symbol/For.h
    src/symbol/For.cpp

    inc/symbol/FunctionDefinition.h
    src/symbol/FunctionDefinition.cpp

    inc/symbol/Identifier.h
    src/symbol/Identifier.cpp

    inc/symbol/Block.h
    src/symbol/Block.cpp

    inc/symbol/VariableDeclaration.h
    src/symbol/VariableDeclaration.cpp

    inc/symbol/ArgumentList.h
    src/symbol/ArgumentList.cpp

    inc/symbol/ParameterList.h
    src/symbol/ParameterList.cpp

    inc/symbol/Primitive.h

    inc/symbol/Bool.h
    src/symbol/Bool.cpp

    inc/symbol/Text.h
    src/symbol/Text.cpp

    inc/symbol/Number.h
    src/symbol/Number.cpp

    inc/symbol/expression/Expression.h
    src/symbol/expression/Expression.cpp

    inc/symbol/expression/BinaryExpression.h

    inc/symbol/expression/AdditionExpression.h
    src/symbol/expression/AdditionExpression.cpp

    inc/symbol/expression/SubtractionExpression.h
    src/symbol/expression/SubtractionExpression.cpp

    inc/symbol/expression/MultiplicationExpression.h
    src/symbol/expression/MultiplicationExpression.cpp

    inc/symbol/expression/DivisionExpression.h
    src/symbol/expression/DivisionExpression.cpp

    inc/symbol/expression/ModuloExpression.h
    src/symbol/expression/ModuloExpression.cpp

    inc/symbol/expression/AssignmentExpression.h
    src/symbol/expression/AssignmentExpression.cpp

    inc/symbol/expression/ExponentExpression.h
    src/symbol/expression/ExponentExpression.cpp

    inc/symbol/expression/Condition.h
    src/symbol/expression/Condition.cpp

    inc/symbol/expression/SmallerThanCondition.h
    src/symbol/expression/SmallerThanCondition.cpp

    inc/symbol/expression/AndCondition.h
    src/symbol/expression/AndCondition.cpp

    inc/symbol/expression/EqualCondition.h
    src/symbol/expression/EqualCondition.cpp

    inc/symbol/expression/LargerThanCondition.h
    src/symbol/expression/LargerThanCondition.cpp

    inc/symbol/expression/LargerThanOrEqualCondition.h
    src/symbol/expression/LargerThanOrEqualCondition.cpp

    inc/symbol/expression/NotEqualCondition.h
    src/symbol/expression/NotEqualCondition.cpp

    inc/symbol/expression/OrCondition.h
    src/symbol/expression/OrCondition.cpp

    inc/symbol/expression/SmallerThanOrEqualCondition.h
    src/symbol/expression/SmallerThanOrEqualCondition.cpp

    inc/symbol/expression/StrictEqualCondition.h
    src/symbol/expression/StrictEqualCondition.cpp

    inc/symbol/expression/StrictNotEqualCondition.h
    src/symbol/expression/StrictNotEqualCondition.cpp

    inc/factory/SymbolFactory.h
    src/factory/SymbolFactory.cpp

    inc/factory/ProgramFactory.h
    src/factory/ProgramFactory.cpp

    inc/factory/StatementFactory.h
    src/factory/StatementFactory.cpp

    inc/factory/AssignmentFactory.h
    src/factory/AssignmentFactory.cpp

    inc/factory/ExpressionFactory.h
    src/factory/ExpressionFactory.cpp

    inc/factory/ReturnFactory.h
    src/factory/ReturnFactory.cpp

    inc/factory/BreakFactory.h
    src/factory/BreakFactory.cpp

    inc/factory/ContinueFactory.h
    src/factory/ContinueFactory.cpp

    inc/factory/IfFactory.h
    src/factory/IfFactory.cpp

    inc/factory/WhileFactory.h
    src/factory/WhileFactory.cpp

    inc/factory/ForFactory.h
    src/factory/ForFactory.cpp

    inc/factory/FunctionDefinitionFactory.h
    src/factory/FunctionDefinitionFactory.cpp

    inc/factory/IdentifierFactory.h
    src/factory/IdentifierFactory.cpp

    inc/factory/BlockFactory.h
    src/factory/BlockFactory.cpp

    inc/factory/VariableDeclarationFactory.h
    src/factory/VariableDeclarationFactory.cpp

    inc/factory/ArgumentListFactory.h
    src/factory/ArgumentListFactory.cpp

    inc/factory/ParameterListFactory.h
    src/factory/ParameterListFactory.cpp

    inc/factory/PrimitiveFactory.h
    src/factory/PrimitiveFactory.cpp
)

set(TestParser_SRCS
    test/factory/ArgumentListFactoryTest.cpp
    test/factory/AssignmentFactoryTest.cpp
    test/factory/BlockFactoryTest.cpp
    test/factory/BreakFactoryTest.cpp
    test/factory/ContinueFactoryTest.cpp
    test/factory/ExpressionFactoryTest.cpp
    test/factory/ForFactoryTest.cpp
    test/factory/FunctionDefinitionFactoryTest.cpp
    test/factory/IdentifierFactoryTest.cpp
    test/factory/IfFactoryTest.cpp
    test/factory/ParameterListFactoryTest.cpp
    test/factory/ProgramFactoryTest.cpp
    test/factory/ReturnFactoryTest.cpp
    test/factory/StatementFactoryTest.cpp
    test/factory/VariableDefinitionTest.cpp
    test/factory/WhileFactoryTest.cpp
    test/factory/PrimitiveFactoryTest.cpp
)

add_library(libparser ${Parser_SRCS})
add_library(dem::libparser ALIAS libparser)
set_target_properties(liblexer PROPERTIES OUTPUT_NAME "parser")

add_executable(parser ${Parser_SRCS} src/main.cpp)

target_link_libraries(libparser dem::liblexer)
target_include_directories(libparser PUBLIC inc ${Lexer_INCLUDE_DIRS})

target_link_libraries(parser dem::liblexer)
target_include_directories(parser PUBLIC inc ${Lexer_INCLUDE_DIRS})

# testing
enable_testing()

add_executable(testparser ${Parser_SRCS} ${TestParser_SRCS})

target_link_libraries(testparser dem::liblexer)
target_include_directories(testparser PRIVATE inc ${Lexer_INCLUDE_DIRS})

find_package(GTest REQUIRED)
if(GTEST_FOUND)
    target_include_directories(testparser PRIVATE E:/Libraries/googletest-release-1.7.0/include)
    target_link_libraries(testparser ${GTEST_BOTH_LIBRARIES})
endif()

add_test(AllLexerTests testparser)