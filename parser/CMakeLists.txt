cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(Parser VERSION 0.1 LANGUAGES CXX)

set(Parser_SRCS
    inc/Visitor.h
    src/Visitor.cpp

    inc/Visitable.h
    src/Visitable.cpp

    inc/Parser.h

    inc/MuseParser.h
    src/MuseParser.cpp

    inc/PrintVisitor.h
    src/PrintVisitor.cpp

    inc/exception/ParsingException.h
    src/exception/ParsingException.cpp

    inc/symbol/Symbol.h
    src/symbol/Symbol.cpp

    inc/symbol/expression/ArrayLiteral.h
    src/symbol/expression/ArrayLiteral.cpp

    inc/symbol/Program.h
    src/symbol/Program.cpp

    inc/symbol/Statement.h
    src/symbol/Statement.cpp

    inc/symbol/Assignment.h
    src/symbol/Assignment.cpp

    inc/symbol/Return.h
    src/symbol/Return.cpp

    inc/symbol/ScopedBlock.h
    src/symbol/ScopedBlock.cpp

    inc/symbol/Break.h
    src/symbol/Break.cpp

    inc/symbol/CompoundStatement.h
    src/symbol/CompoundStatement.cpp

    inc/symbol/Continue.h
    src/symbol/Continue.cpp

    inc/symbol/If.h
    src/symbol/If.cpp

    inc/symbol/NewInstance.h
    src/symbol/NewInstance.cpp

    inc/symbol/While.h
    src/symbol/While.cpp

    inc/symbol/For.h
    src/symbol/For.cpp

    inc/symbol/Identifiable.h

    inc/symbol/expression/FunctionDefinition.h
    src/symbol/expression/FunctionDefinition.cpp

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

    inc/symbol/expression/BoolLiteral.h
    src/symbol/expression/BoolLiteral.cpp

    inc/symbol/expression/TextLiteral.h
    src/symbol/expression/TextLiteral.cpp

    inc/symbol/expression/ThisExpression.h
    src/symbol/expression/ThisExpression.cpp

    inc/symbol/Track.h
    src/symbol/Track.cpp

    inc/symbol/expression/NumberLiteral.h
    src/symbol/expression/NumberLiteral.cpp

    inc/symbol/expression/Expression.h
    src/symbol/expression/Expression.cpp

    inc/symbol/expression/ExpressionStatement.h
    src/symbol/expression/ExpressionStatement.cpp

    inc/symbol/expression/FunctionCallExpression.h
    src/symbol/expression/FunctionCallExpression.cpp

    inc/symbol/expression/ArrayAccessExpression.h
    src/symbol/expression/ArrayAccessExpression.cpp

    inc/symbol/expression/BinaryExpression.h

    inc/symbol/expression/CallExpression.h
    src/symbol/expression/CallExpression.cpp

    inc/symbol/expression/AdditionExpression.h
    src/symbol/expression/AdditionExpression.cpp

    inc/symbol/expression/SubtractionExpression.h
    src/symbol/expression/SubtractionExpression.cpp

    inc/symbol/expression/UnaryExpression.h
    src/symbol/expression/UnaryExpression.cpp

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

    inc/symbol/expression/Literal.h
    src/symbol/expression/Literal.cpp

    inc/symbol/expression/MemberExpression.h
    src/symbol/expression/MemberExpression.cpp

    inc/symbol/expression/NotEqualCondition.h
    src/symbol/expression/NotEqualCondition.cpp

    inc/symbol/expression/OrCondition.h
    src/symbol/expression/OrCondition.cpp

    inc/symbol/expression/PropertyAccessExpression.h
    src/symbol/expression/PropertyAccessExpression.cpp

    inc/symbol/expression/SmallerThanOrEqualCondition.h
    src/symbol/expression/SmallerThanOrEqualCondition.cpp

    inc/symbol/expression/StrictEqualCondition.h
    src/symbol/expression/StrictEqualCondition.cpp

    inc/symbol/expression/StrictNotEqualCondition.h
    src/symbol/expression/StrictNotEqualCondition.cpp

    inc/symbol/play/Playable.h

    inc/symbol/play/Play.h
    src/symbol/play/Play.cpp

    inc/symbol/play/Harmony.h
    src/symbol/play/Harmony.cpp

    inc/symbol/play/Instrument.h
    src/symbol/play/Instrument.cpp

    inc/symbol/play/Note.h
    src/symbol/play/Note.cpp

    inc/factory/SymbolFactory.h
    src/factory/SymbolFactory.cpp

    inc/factory/TrackFactory.h
    src/factory/TrackFactory.cpp

    inc/factory/ProgramFactory.h
    src/factory/ProgramFactory.cpp

    inc/factory/StatementFactory.h
    src/factory/StatementFactory.cpp

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

    inc/factory/InstrumentFactory.h
    src/factory/InstrumentFactory.cpp

    inc/factory/NewInstanceFactory.h
    src/factory/NewInstanceFactory.cpp

    inc/factory/NoteFactory.h
    src/factory/NoteFactory.cpp

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

    inc/factory/PlayFactory.h
    src/factory/PlayFactory.cpp

    inc/factory/NoteFactory.h
    src/factory/NoteFactory.cpp

    inc/factory/NewInstanceFactory.h
    src/factory/NewInstanceFactory.cpp
)

set(TestParser_SRCS
    test/factory/ArgumentListFactoryTest.cpp
    test/factory/BlockFactoryTest.cpp
    test/factory/BreakFactoryTest.cpp
    test/factory/ContinueFactoryTest.cpp
    test/factory/ExpressionFactoryTest.cpp
    test/factory/ForFactoryTest.cpp
    test/factory/IdentifierFactoryTest.cpp
    test/factory/IfFactoryTest.cpp
    test/factory/ParameterListFactoryTest.cpp
    test/factory/ProgramFactoryTest.cpp
    test/factory/ReturnFactoryTest.cpp
    test/factory/StatementFactoryTest.cpp
    test/factory/VariableDefinitionTest.cpp
    test/factory/WhileFactoryTest.cpp)

add_library(libparser SHARED ${Parser_SRCS})
add_library(dem::libparser ALIAS libparser)
set_target_properties(libparser PROPERTIES OUTPUT_NAME "parser")

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
    target_include_directories(testparser PRIVATE P:/Libraries/googletest-release-1.7.0/include)
    target_link_libraries(testparser ${GTEST_BOTH_LIBRARIES})
endif()

add_test(AllLexerTests testparser)

# install
install(TARGETS libparser DESTINATION / COMPONENT libparser)