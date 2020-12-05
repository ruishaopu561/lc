#ifndef TOKENSCANNER_H
#define TOKENSCANNER_H

#include <string>

enum TokenType
{
    WORD,
    NUMBER,
    BRACKET,
    ENDOF,
    OPFACT,
};

class TokenScanner
{
public:
    TokenScanner();
    TokenScanner(std::string str);
    ~TokenScanner();

    TokenType getTokenType(std::string str);
    void setInput(std::string str);
    bool hasMoreTokens();
    std::string nextToken();
    void saveToken(std::string str);
    void ignoreWhitespace();

private:
    std::string buffer;
    int cp;
    bool ignoreWhitespaceFlag;
    void skipWhitespace();
};

#endif /*TOKENSCANNER_H*/