
#include <ast/Expression.h>
#include <ast/Visitor.h>

namespace px
{
    namespace ast
    {
        void *AssignmentExpression::accept(Visitor &visitor) { return visitor.visit(*this); }

        void *BinaryOpExpression::accept(Visitor &visitor) { return visitor.visit(*this); }

        void *CastExpression::accept(Visitor &visitor) { return visitor.visit(*this); }

        void *TernaryOpExpression::accept(Visitor &visitor) { return visitor.visit(*this); }

        void *UnaryOpExpression::accept(Visitor &visitor) { return visitor.visit(*this); }

        void *VariableExpression::accept(Visitor &visitor) { return visitor.visit(*this); }
    }
}

