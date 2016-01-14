#ifndef DEMUSE_FOR_H
#define DEMUSE_FOR_H

#include "CompoundStatement.h"
#include "symbol/expression/Expression.h"
#include "symbol/expression/AssignmentExpression.h"
#include "symbol/Block.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents a for statement (e.g. for(var i = 0; i < 4; i++) { ... })
         */
        class For : public CompoundStatement {
        public:
            /**
             * \brief Constructs a new for loop, any of these parameter may be null, except block
             *
             * \param token          token this for-loop represents
             * \param initialization statement to run the first time the loop is entered, may be null
             * \param condition      expression to evaluate for each loop, may be null
             * \param afterThought   expression to evaluate after each loop, may be null
             * \param block          block to execute each loop, may not be null
             */
            For(lexer::Token &token, Statement *initialization, Expression *condition, AssignmentExpression *afterThought, Block *block);
            ~For();

            virtual bool accept(Visitor &visitor);

            /**
             * \return statement to run the first time the loop is entered, may be null
             */
            Statement *initialization() const;

            /**
             * \return expression to evaluate for each loop, may be null
             */
            Expression *condition() const;

            /**
             * \return expression to evaluate after each loop, may be null
             */
            AssignmentExpression *afterThought() const;

            /**
             * \return block to execute each loop
             */
            Block &block() const;

        private:
            Statement *mInitialization;
            Expression *mCondition;
            AssignmentExpression *mAfterThought;
            Block *mBlock;
        };
    }
}

#endif //DEMUSE_FOR_H
