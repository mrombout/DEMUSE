#ifndef DEMUSE_FUNCTIONDEFINITION_H
#define DEMUSE_FUNCTIONDEFINITION_H

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
             */
            FunctionDefinition(const lexer::Token &token, ParameterList *parameterList, Block *block);

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
             * The function `foo` is then accassible throughout the DEMUSE script.
             */
            FunctionDefinition(const lexer::Token &token, Identifier *identifier, ParameterList *parameterList, Block *block);

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
            Block &block() const;

        private:
            Identifier *mIdentifier;
            ParameterList *mParameterList;
            Block *mBlock;
        };
    }
}

#endif //DEMUSE_FUNCTIONDEFINITION_H
