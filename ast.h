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
  vector<ASTnode> parse_input();
  vector<Token> stripWhitespaces();
  void print_clean_tokens();
  ASTnode creat_tree();
  ASTnode check_comparator(vector<Token> node, int j, int depth);
  void print_all_tokens();
  ASTnode check_variable_assignment(vector<Token>, int j);
  void print_tree(ASTnode node, int depth);
  int grab_current();
};
