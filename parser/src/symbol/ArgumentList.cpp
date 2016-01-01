#include "symbol/ArgumentList.h"
#include "Visitor.h"

namespace dem {
    namespace parser {
        ArgumentList::ArgumentList(const lexer::Token &token, std::vector<Expression*> arguments) :
            Symbol(token),
            mArguments(arguments) {

        }

        std::vector<Expression *> &ArgumentList::arguments() {
            return mArguments;
        }

        int ArgumentList::numArguments() {
            return mArguments.size();
        }

        bool ArgumentList::accept(Visitor &visitor) {
            if(visitor.visitEnter(*this)) {
                for(Expression *argument : mArguments) {
                    argument->accept(visitor);
                }
            }

            return visitor.visitLeave(*this);
        }
    }
}
