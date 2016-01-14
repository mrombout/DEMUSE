#include <stdexcept>
#include "symbol/If.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        If::If(lexer::Token &ifToken, Expression *expression, Block *block) :
            If(ifToken, expression, block, nullptr) {

        }

        If::If(lexer::Token &ifToken, Expression *expression, Block *block, Block *elseBlock) :
            CompoundStatement(ifToken),
            mExpression(expression),
            mBlock(block),
            mElseBlock(elseBlock) {
            if(!expression)
                throw std::invalid_argument("Argument 'expression' may not be null.");
            if(!block)
                throw std::invalid_argument("Argument 'block' may not be null.");
        }

        bool If::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                mExpression->accept(visitor);
                mBlock->accept(visitor);
                if(mElseBlock) {
                    mElseBlock->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }

        Expression &If::expression() const {
            return *mExpression;
        }

        Block &If::block() const {
            return *mBlock;
        }

        Block *If::elseBlock() const {
            return mElseBlock;
        }

        If::~If() {
            delete mExpression;
            delete mBlock;
            if(mElseBlock)
                delete mElseBlock;
        }
    }
}
