
#ifndef _PX_CG_LLVMCOMPILER_H_
#define _PX_CG_LLVMCOMPILER_H_

#include "ast/Visitor.h"
#include "ModuleData.h"
#include "Scope.h"
#include "Utf8String.h"

#include <unordered_map>
#include "llvm/IR/IRBuilder.h"

namespace px {

    class LLVMCompiler : public ast::Visitor
    {
    public:
        LLVMCompiler(ScopeTree * scopeTree);
        void compile(ast::AST &ast);
        void *visit(ast::AssignmentStatement &a) override;
        void *visit(ast::BinaryOpExpression &e) override;
        void *visit(ast::BoolLiteral &b) override;
        void *visit(ast::BlockStatement &s) override;
        void *visit(ast::CharLiteral &c) override;
        void *visit(ast::CastExpression &f) override;
        void *visit(ast::ExpressionStatement &s) override;
        void *visit(ast::ExternFunctionDeclaration &e) override;
        void *visit(ast::FloatLiteral &f) override;
        void *visit(ast::FunctionCallExpression &f) override;
        void *visit(ast::FunctionDeclaration &f) override;
        void *visit(ast::IfStatement &i) override;
        void *visit(ast::IntegerLiteral &i) override;
        void *visit(ast::Module &m) override;
        void *visit(ast::ReturnStatement &s) override;
        void *visit(ast::StringLiteral &s) override;
        void *visit(ast::TernaryOpExpression &t) override;
        void *visit(ast::UnaryOpExpression &e) override;
        void *visit(ast::VariableDeclaration &d) override;
        void *visit(ast::VariableExpression &v) override;

    private:
        class LLVMScope
        {
        public:
            LLVMScope(px::Scope *s, LLVMScope *p) : parent{ p }, scope{ s }
            {
            }

            LLVMScope *findVariable(const Utf8String &name)
            {
                auto var = variables.find(name);
                if (var != variables.end())
                    return this;
                else if (parent != nullptr)
                    return parent->findVariable(name);
                else
                    return nullptr;
            }

            std::unordered_map<Utf8String, llvm::AllocaInst*> variables;
            LLVMScope * const parent;
            px::Scope * const scope;
        };

        class LLVMFunctionData : public OtherSymbolData
        {
        public:
            LLVMFunctionData(llvm::Function *f) : function{ f }
            {
            }

            virtual ~LLVMFunctionData() = default;

            llvm::Function * const function;
        };

        llvm::Type *pxTypeToLlvmType(Type *type);

        ModuleData moduleData;
        llvm::IRBuilder<> builder;
        px::Function *currentFunction;
        LLVMScope *currentScope;
        px::ScopeTree * const scopeTree;
        llvm::BasicBlock *currentBlock;
    };

}

#endif