
#ifndef TOKEN_H_
#define TOKEN_H_

#include "Utf8String.h"

namespace px {

    enum class TokenType
    {
        BAD, END_FILE, IDENTIFIER, INTEGER, HEX_INT, BINARY_INT, OCTAL_INT, FLOAT, STRING,
        KW_ABSTRACT,
        KW_AS,
        KW_BREAK,
        KW_CASE,
        KW_CONCEPT,
        KW_CONTINUE,
        KW_DEFAULT,
        KW_DO,
        KW_ELSE,
        KW_FALSE,
        KW_FOR,
        KW_IF,
        KW_IMPLEMENTATION,
        KW_INTERFACE,
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
        OP_ADD,
        OP_AND,
        OP_ASSIGN,
        OP_ASSIGN_ADD,
        OP_ASSIGN_DIV,
        OP_ASSIGN_MOD,
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
        OP_SIZE,
        OP_STAR,
        OP_SUB
    };

    struct Token
    {
        TokenType type;
        Utf8String str;
        Token() { clear(); }
        Token(TokenType t, const Utf8String &s) : type(t), str(s) {}
        void clear() { type = TokenType::BAD; str.clear(); }
    };

}
#endif