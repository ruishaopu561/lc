#include <iostream>

#include "parser.h"

Expression *parseExp(TokenScanner *scanner)
{
    Expression *exp = readE(scanner, 0);
    if (scanner->hasMoreTokens())
    {
        std::cout << "Unexpected token \"" << scanner->nextToken() << "\"" << std::endl;
        return NULL;
    }
    return exp;
}

Expression *readE(TokenScanner *scanner, int prec)
{
    Expression *exp = readT(scanner);
    exp = readF(scanner, exp);
    std::string token;
    while (true)
    {
        token = scanner->nextToken();
        int tprec = precedence(token);
        if (tprec <= prec)
        {
            break;
        }
        Expression *rhs = readE(scanner, tprec);
        exp = new CompoundExp(token, exp, rhs);
        exp = readF(scanner, exp);
    }
    scanner->saveToken(token); // 因为这个token实际没用上，所以存起来等下次用。
    return exp;
}

Expression *readT(TokenScanner *scanner)
{
    std::string token = scanner->nextToken();
    TokenType type = scanner->getTokenType(token);
    if (type == WORD)
    {
        return new IdentifierExp(token);
    }
    else if (type == NUMBER)
    {
        return new ConstantExp(atoi(token.c_str()));
    }
    else if (token != "(")
    {
        std::cout << "Unexpected token \"" << token << "\"" << std::endl;
        return NULL;
    }

    Expression *exp = readE(scanner, 0);
    exp = readF(scanner, exp);
    if (scanner->nextToken() != ")")
    {
        std::cout << "Unbalanced parentheses" << std::endl;
        return NULL;
    }
    return exp;
}

Expression *readF(TokenScanner *scanner, Expression *exp)
{
    std::string token = scanner->nextToken();
    TokenType type = scanner->getTokenType(token);
    if (type == OPFACT)
    {
        return new FactExp(token, exp);
    }
    else
    {
        scanner->saveToken(token);
        return exp;
    }
}

int precedence(std::string token)
{
    if (token == "=")
    {
        return 1;
    }
    else if (token == "+" || token == "-")
    {
        return 2;
    }
    else if (token == "*" || token == "/")
    {
        return 3;
    }
    return 0;
}