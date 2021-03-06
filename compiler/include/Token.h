
#ifndef _PX_TOKEN_H_
#define _PX_TOKEN_H_

#include "Symbol.h"
#include "Utf8String.h"
#include "SourcePosition.h"

namespace px {

    enum class TokenType
    {
        BAD, END_FILE, IDENTIFIER, INTEGER, FLOAT, CHAR, STRING,
        KW_ABSTRACT,
        KW_AS,
        KW_BREAK,
        KW_CASE,
        KW_CONCEPT,
        KW_CONTINUE,
        KW_DEFAULT,
        KW_DO,
        KW_ELSE,
        KW_EXTERN,
        KW_FALSE,
        KW_FOR,
        KW_FUNC,
        KW_IF,
        KW_IMPLEMENTATION,
        KW_INTERFACE,
        KW_MODULE,
        KW_NEW,
        KW_PRIVATE,
        KW_PROTECTED,
        KW_PUBLIC,
        KW_REF,
        KW_RETURN,
        KW_STATE,
        KW_SWITCH,
        KW_TRUE,
        KW_VALUE,
        KW_WHILE,
        LPAREN,
        RPAREN,
        LBRACKET,
        RBRACKET,
        LSQUARE_BRACKET,
        RSQUARE_BRACKET,
        OP_ADD,
        OP_AND,
        OP_ASSIGN,
        OP_ASSIGN_ADD,
        OP_ASSIGN_BIT_AND,
        OP_ASSIGN_BIT_OR,
        OP_ASSIGN_BIT_XOR,
        OP_ASSIGN_DIV,
        OP_ASSIGN_MOD,
        OP_ASSIGN_LEFT_SHIFT,
        OP_ASSIGN_RIGHT_SHIFT,
        OP_ASSIGN_STAR,
        OP_ASSIGN_SUB,
        OP_BIT_AND,
        OP_BIT_OR,
        OP_BIT_XOR,
        OP_COLON,
        OP_COMMA,
        OP_COMPL,
        OP_DOT,
        OP_DECRE,
        OP_DIV,
        OP_EQUALS,
        OP_END_STATEMENT,
        OP_GREATER,
        OP_GREATER_OR_EQUAL,
        OP_INCRE,
        OP_LEFT_SHIFT,
        OP_LESS,
        OP_LESS_OR_EQUAL,
        OP_MOD,
        OP_NOT,
        OP_NOT_EQUAL,
        OP_OR,
        OP_QUESTION,
        OP_RIGHT_SHIFT,
        OP_STAR,
        OP_SUB
    };

    struct Token
    {
        TokenType type;
        Utf8String str;
        Type *suffixType;
        int integerBase;
        SourcePosition position;

        static std::unordered_map<TokenType, const Utf8String> tokenNames;
        Token(const SourcePosition &pos) : position{ pos } { clear(); }
        Token(const SourcePosition &pos, TokenType t, const Utf8String &s) : type { t }, str{ s }, suffixType{ nullptr }, integerBase{10}, position{ pos }
        {
        }

        void clear()
        {
            type = TokenType::BAD;
            str.clear();
            suffixType = nullptr;
            integerBase = 10;
        }

        static const Utf8String &getTokenName(TokenType type);
    };
}

namespace std
{
    template<>
    struct hash< px::TokenType >
    {
        typedef px::TokenType argument_type;
        typedef std::size_t result_type;
        result_type operator()( const argument_type& arg ) const
        {
            return static_cast<std::size_t>(arg);
        }
    };
}
#endif
