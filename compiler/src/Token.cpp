
#include "Token.h"

namespace px
{

    std::unordered_map<TokenType, const Utf8String> Token::tokenNames = {
        { TokenType::BAD, "bad token" },
        { TokenType::IDENTIFIER, "identifer" },
        { TokenType::INTEGER, "integer literal" },
        { TokenType::FLOAT, "float literal" },
        { TokenType::CHAR, "char literal" },
        { TokenType::STRING, "string literal" },
        { TokenType::KW_ABSTRACT, "abstract" },
        { TokenType::KW_AS, "as" },
        { TokenType::KW_BREAK, "break" },
        { TokenType::KW_CASE, "case" },
        { TokenType::KW_CONCEPT, "concept" },
        { TokenType::KW_CONTINUE, "continue" },
        { TokenType::KW_DEFAULT, "default" },
        { TokenType::KW_DO, "do" },
        { TokenType::KW_ELSE , "else" },
        { TokenType::KW_EXTERN , "extern" },
        { TokenType::KW_FALSE, "false" },
        { TokenType::KW_FOR, "for" },
        { TokenType::KW_FUNC, "func" },
        { TokenType::KW_IF , "if" },
        { TokenType::KW_IMPLEMENTATION, "implementation" },
        { TokenType::KW_INTERFACE, "interface" },
        { TokenType::KW_MODULE, "module" },
        { TokenType::KW_NEW , "new" },
        { TokenType::KW_PRIVATE, "private" },
        { TokenType::KW_PROTECTED, "protected" },
        { TokenType::KW_PUBLIC, "public" },
        { TokenType::KW_REF, "ref" },
        { TokenType::KW_RETURN, "return" },
        { TokenType::KW_STATE, "state" },
        { TokenType::KW_SWITCH, "switch" },
        { TokenType::KW_TRUE, "true" },
        { TokenType::KW_VALUE, "value" },
        { TokenType::KW_WHILE, "while" },
        { TokenType::LPAREN, "(" },
        { TokenType::RPAREN, ")" },
        { TokenType::LBRACKET, "{" },
        { TokenType::RBRACKET, "}" },
        { TokenType::OP_ADD, "+" },
        { TokenType::OP_AND, "&&" },
        { TokenType::OP_ASSIGN, "=" },
        { TokenType::OP_ASSIGN_ADD, "+=" },
        { TokenType::OP_ASSIGN_DIV, "/=" },
        { TokenType::OP_ASSIGN_MOD, "%=" },
        { TokenType::OP_ASSIGN_STAR, "*=" },
        { TokenType::OP_ASSIGN_SUB, "-=" },
        { TokenType::OP_BIT_AND, "&" },
        { TokenType::OP_BIT_OR, "|" },
        { TokenType::OP_BIT_XOR, "^" },
        { TokenType::OP_COLON, ":" },
        { TokenType::OP_COMMA, "," },
        { TokenType::OP_COMPL, "~" },
        { TokenType::OP_DECRE, "--" },
        { TokenType::OP_DIV, "/" },
        { TokenType::OP_DOT, "." },
        { TokenType::OP_END_STATEMENT, ";" },
        { TokenType::OP_EQUALS, "==" },
        { TokenType::OP_GREATER, ">" },
        { TokenType::OP_GREATER_OR_EQUAL, ">=" },
        { TokenType::OP_INCRE, "++" },
        { TokenType::OP_LEFT_SHIFT, "<<" },
        { TokenType::OP_LESS, "<" },
        { TokenType::OP_LESS_OR_EQUAL, "<=" },
        { TokenType::OP_MOD, "%" },
        { TokenType::OP_NOT_EQUAL, "!=" },
        { TokenType::OP_OR, "||" },
        { TokenType::OP_QUESTION, "?" },
        { TokenType::OP_RIGHT_SHIFT, ">>" },
        { TokenType::OP_STAR, "*" },
        { TokenType::OP_SUB, "-" },
    };

    const Utf8String &Token::getTokenName(TokenType type)
    {
        auto it = tokenNames.find(type);
        if (it != tokenNames.end())
        {
            return it->second;
        }
        return tokenNames[TokenType::BAD];
    }
}

