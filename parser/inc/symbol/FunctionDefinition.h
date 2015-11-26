#ifndef DEMUSE_FUNCTIONDEFINITION_H
#define DEMUSE_FUNCTIONDEFINITION_H

#include "CompoundStatement.h"
#include "ParameterList.h"
#include "Block.h"

namespace dem {
    namespace parser {
        class FunctionDefinition : public CompoundStatement {
        public:
            FunctionDefinition(Identifier *identifier, ParameterList *parameterList, Block *block);

            virtual bool accept(Visitor &visitor);

            Identifier &identifier() const;
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
