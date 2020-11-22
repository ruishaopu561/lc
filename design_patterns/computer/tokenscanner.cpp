#include <string>

#include "tokenscanner.h"

TokenScanner::TokenScanner() {}

TokenScanner::~TokenScanner() {}

TokenScanner::TokenScanner(std::string str)
{
    setInput(str);
}

TokenType TokenScanner::getTokenType(std::string str)
{
    if (str == "")
    {
        return ENDOF;
    }
    else if (str[0] > '0' && str[0] < '9')
    {
        return NUMBER;
    }
    else if (str[0] == '(')
    {
        return BRACKET;
    }
    else
    {
        return WORD;
    }
}

void TokenScanner::setInput(std::string str)
{
    buffer = str;
    cp = 0;
}

bool TokenScanner::hasMoreTokens()
{
    if (ignoreWhitespaceFlag)
    {
        skipWhitespace();
    }
    return cp < buffer.size();
}

std::string TokenScanner::nextToken()
{
    if (ignoreWhitespaceFlag)
    {
        skipWhitespace();
    }

    if (cp >= buffer.size())
    {
        return "";
    }
    else if (isalnum(buffer[cp]))
    {
        int start = cp;
        while (cp < buffer.size() && isalnum(buffer[cp]))
        {
            cp++;
        }
        return buffer.substr(start, cp - start);
    }
    else
    {
        return std::string(1, buffer[cp++]);
    }
}

void TokenScanner::saveToken(std::string str)
{
    cp -= str.size();
}

void TokenScanner::ignoreWhitespace()
{
    ignoreWhitespaceFlag = true;
}

void TokenScanner::skipWhitespace()
{
    while (cp < buffer.size() && isspace(buffer[cp]))
    {
        cp++;
    }
}