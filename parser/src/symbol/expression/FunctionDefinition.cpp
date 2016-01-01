#include "symbol/expression/FunctionDefinition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        FunctionDefinition::FunctionDefinition(const lexer::Token &token, ParameterList *parameterList, Block *block) :
            FunctionDefinition(token, nullptr, parameterList, block) {

        }

        FunctionDefinition::FunctionDefinition(const lexer::Token &token, Identifier *identifier, ParameterList *parameterList, Block *block) :
            Expression(token),
            mIdentifier(identifier),
            mParameterList(parameterList),
            mBlock(block) {

        }

        bool FunctionDefinition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                if(mIdentifier)
                    mIdentifier->accept(visitor);
                mParameterList->accept(visitor);
                mBlock->accept(visitor);
            }

            return visitor.visitLeave(*this);
        }

        Identifier *FunctionDefinition::identifier() const {
            return mIdentifier;
        }

        ParameterList &FunctionDefinition::parameterList() const {
            return *mParameterList;
        }

        Block &FunctionDefinition::block() const {
            return *mBlock;
        }
    }
}
