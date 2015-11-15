cmake_minimum_required(VERSION 3.3 FATAL_ERROR)
project(Parser VERSION 0.1 LANGUAGES CXX)

set(Parser_SRCS
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

    inc/symbol/Expression.h
    src/symbol/Expression.cpp

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

    inc/symbol/VariableDefinition.h
    src/symbol/VariableDefinition.cpp

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

    inc/factory/VariableDefinitionFactory.h
    src/factory/VariableDefinitionFactory.cpp

    inc/factory/ArgumentListFactory.h
    src/factory/ArgumentListFactory.cpp

    inc/factory/ParameterListFactory.h
    src/factory/ParameterListFactory.cpp

    inc/factory/PrimitiveFactory.h
    src/factory/PrimitiveFactory.cpp
)

add_library(libparser ${Parser_SRCS})
add_library(dem::libparser ALIAS libparser)
set_target_properties(liblexer PROPERTIES OUTPUT_NAME "parser")

add_executable(parser ${Parser_SRCS} src/main.cpp)

target_link_libraries(libparser dem::liblexer)
target_include_directories(libparser PUBLIC inc ${Lexer_INCLUDE_DIRS})

target_link_libraries(parser dem::liblexer)
target_include_directories(parser PUBLIC inc ${Lexer_INCLUDE_DIRS})