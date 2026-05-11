#pragma once
#include "lexer.h"
#include <vector>
#include <string>

using namespace std;

struct ASTnode {
  string type;
  string value;
  vector<ASTnode> children;
};

class Parser {
private:
  vector<Token> tokens;
  int current;
public:
  Parser(const vector<Token>& tokens);
  ASTnode parse_input();
  vector<Token> stripWhitespaces();
  void print_clean_tokens();
  void print_all_tokens();
};
