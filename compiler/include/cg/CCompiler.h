
#ifndef _PX_CG_CCOMPILER_H_
#define _PX_CG_CCOMPILER_H_

#include "ast/Visitor.h"
#include "Scope.h"
#include "Utf8String.h"

#include <unordered_map>

namespace px {

    class CCompiler : public ast::Visitor
    {
    public:
        CCompiler(ScopeTree * scopeTree);
        void compile(ast::AST &ast);
        void *visit(ast::ArrayIndexReference &a) override;
        void *visit(ast::ArrayIndexAssignmentStatement &a) override;
        void *visit(ast::ArrayLiteral &a) override;
        void *visit(ast::AssignmentStatement &a) override;
        void *visit(ast::BinaryOpExpression &e) override;
        void *visit(ast::BoolLiteral &b) override;
        void *visit(ast::BlockStatement &s) override;
        void *visit(ast::BreakStatement &b) override;
        void *visit(ast::CastExpression &f) override;
        void *visit(ast::CharLiteral &c) override;
        void *visit(ast::ContinueStatement &c) override;
        void *visit(ast::DoWhileStatement &d) override;
        void *visit(ast::ExpressionStatement &s) override;
        void *visit(ast::FloatLiteral &f) override;
        void *visit(ast::FunctionCallExpression &f) override;
        void *visit(ast::FunctionDeclaration &f) override;
        void *visit(ast::FunctionDefinition &f) override;
        void *visit(ast::IfStatement &i) override;
        void *visit(ast::IntegerLiteral &i) override;
        void *visit(ast::Module &m) override;
        void *visit(ast::ReturnStatement &s) override;
        void *visit(ast::StringLiteral &s) override;
        void *visit(ast::TernaryOpExpression &t) override;
        void *visit(ast::UnaryOpExpression &e) override;
        void *visit(ast::VariableDeclaration &d) override;
        void *visit(ast::VariableExpression &v) override;
        void *visit(ast::WhileStatement &w) override;

    private:
        static Utf8String pxTypeToCType(Type *type);
        void indent();
        void indent(ast::AST *node);
        void unindent();
        void unindent(ast::AST *node);
        void newLine();
        void add(const Utf8String &text);
        Utf8String buildFunctionProto(Function *function);

        Utf8String code;
        unsigned int indentLevel;
        Utf8String toPreDeclare;
        px::Function *currentFunction;
        px::Scope *currentScope;
        px::ScopeTree * const scopeTree;
    };

}

#endif

