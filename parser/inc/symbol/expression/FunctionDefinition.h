#ifndef DEMUSE_FUNCTIONDEFINITION_H
#define DEMUSE_FUNCTIONDEFINITION_H

#include "symbol/ScopedBlock.h"
#include "symbol/CompoundStatement.h"
#include "symbol/ParameterList.h"
#include "symbol/Block.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a function definition (e.g. function foo() { ... })
         */
        class FunctionDefinition : public Expression {
        public:
            /**
             * \brief Constructs a function without an identifier
             *
             * Constructs a function without an identifier, this should primarily be used for anonymous functions or
             * closured. When an anonymous function is assigned to a variable (or passed as a parameter) the user can
             * still call these functions through their identifier variable.
             *
             * ```
             * var foo = function() {
             *     // ...
             * };
             * ```
             *
             * \param token         token this function definition is represented by
             * \param parameterList parameter list this function takes, may not be null
             * \param block         block to execute when this function is called, may not be null
             *
             * \throws std::invalid_argument when parameterList is null
             * \throws std::invalid_argument when block is null
             */
            FunctionDefinition(const lexer::Token &token, ParameterList *parameterList, ScopedBlock *block);

            /**
             * \brief Constructs a function with an identifier
             *
             * Constructs a function with an identifier, this is used for traditional function definitions, such as:
             *
             * ```
             * function foo() {
             *     // ...
             * }
             * ```
             *
             * The function `foo` is then accessible throughout the DEMUSE script.
             *
             * \param token         token this function definition is represented by
             * \param identifier    identifier to associate with this function, may be null
             * \param parameterList parameter list this function takes, may not be null
             * \param block         block to execute when this function is called, may not be null
             *
             * \throws std::invalid_argument when parameterList is null
             * \throws std::invalid_argument when block is null
             */
            FunctionDefinition(const lexer::Token &token, Identifier *identifier, ParameterList *parameterList, ScopedBlock *block);

            virtual bool accept(Visitor &visitor);

            /**
             * \return identifier of this function, or nullptr when this function is anonymous
             */
            Identifier *identifier() const;

            /**
             * \return list of parameters for this function
             */
            ParameterList &parameterList() const;

            /**
             * \brief Block to execute when this function is called
             */
            ScopedBlock &block() const;

        private:
            Identifier *mIdentifier;
            ParameterList *mParameterList;
            ScopedBlock *mBlock;
        };
    }
}

#endif //DEMUSE_FUNCTIONDEFINITION_H
