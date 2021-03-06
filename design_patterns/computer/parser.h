#ifndef PARSER_H
#define PARSER_H

#include <string>

#include "exp.h"
#include "tokenscanner.h"

Expression *parseExp(TokenScanner *scanner);
Expression *readE(TokenScanner *scanner, int prec);
Expression *readT(TokenScanner *scanner);
Expression *readF(TokenScanner *scanner, Expression *exp);
int precedence(std::string token);

#endif /*PARSER_H*/