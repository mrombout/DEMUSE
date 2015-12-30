#include "symbol/expression/FunctionDefinition.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        FunctionDefinition::FunctionDefinition(ParameterList *parameterList, Block *block) :
            FunctionDefinition(nullptr, parameterList, block) {

        }

        FunctionDefinition::FunctionDefinition(Identifier *identifier, ParameterList *parameterList, Block *block) :
            Expression(identifier->token()),
            mIdentifier(identifier),
            mParameterList(parameterList),
            mBlock(block) {

        }

        bool FunctionDefinition::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                // TODO: visit children
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
