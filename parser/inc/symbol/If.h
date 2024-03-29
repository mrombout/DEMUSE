#ifndef DEMUSE_IF_H
#define DEMUSE_IF_H

#include "CompoundStatement.h"
#include "symbol/expression/Expression.h"
#include "symbol/Block.h"

namespace dem {
    namespace parser {
        /**
         * \brief Represents an if statement (e.g. if(foo == 1) { ... })
         */
        class If : public CompoundStatement {
        public:
            /**
             * \brief Constructs an if statement, without an else block
             *
             * \param expression expression to evaluate
             * \param block      block to execute when expression is true
             * \throws std::invalid_argument if expression is null
             * \throws std::invalid_argument if block is null
             */
            If(lexer::Token &ifToken, Expression *expression, Block *block);

            /**
             * \brief Constructs an if statement, with an else block
             *
             * \param expression expression to evaluate, may not be null
             * \param block      block to execute when expression is true, may not be null
             * \param elseBlock  block to execute when expression is false, may be null
             * \throws std::invalid_argument if expression is null
             * \throws std::invalid_argument if block is null
             */
            If(lexer::Token &ifToken, Expression *expression, Block *block, Block *elseBlock);

            ~If();

            virtual bool accept(Visitor &visitor);

            /**
             * \return expression to evaluate
             */
            Expression &expression() const;

            /**
             * \return block to execute when expression is true
             */
            Block &block() const;

            /**
             * \return block to execute when expression is false, may be null
             */
            Block *elseBlock() const;

        private:
            Expression *mExpression;
            Block *mBlock;
            Block *mElseBlock;
        };
    }
}

#endif //DEMUSE_IF_H
