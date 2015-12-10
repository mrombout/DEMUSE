#ifndef DEMUSE_FUNCTIONDEFINITION_H
#define DEMUSE_FUNCTIONDEFINITION_H

#include "symbol/CompoundStatement.h"
#include "symbol/ParameterList.h"
#include "symbol/Block.h"

namespace dem {
    namespace parser {
        class FunctionDefinition : public Expression {
        public:
            FunctionDefinition(ParameterList *parameterList, Block *block);
            FunctionDefinition(Identifier *identifier, ParameterList *parameterList, Block *block);

            virtual bool accept(Visitor &visitor);

            Identifier *identifier() const;
            ParameterList &parameterList() const;
            Block &block() const;

        private:
            Identifier *mIdentifier;
            ParameterList *mParameterList;
            Block *mBlock;
        };
    }
}

#endif //DEMUSE_FUNCTIONDEFINITION_H
