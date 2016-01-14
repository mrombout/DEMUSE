#include "symbol/expression/FunctionDefinition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        FunctionDefinition::FunctionDefinition(const lexer::Token &token, ParameterList *parameterList, ScopedBlock *block) :
            FunctionDefinition(token, nullptr, parameterList, block) {

        }

        FunctionDefinition::FunctionDefinition(const lexer::Token &token, Identifier *identifier, ParameterList *parameterList, ScopedBlock *block) :
            Expression(token),
            mIdentifier(identifier),
            mParameterList(parameterList),
            mBlock(block) {
            if(!mParameterList)
                throw std::invalid_argument("Argument 'parameterList' may not be null.");
            if(!mBlock)
                throw std::invalid_argument("Argument 'block' may not be null.");
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

        ScopedBlock &FunctionDefinition::block() const {
            return *mBlock;
        }
    }
}
