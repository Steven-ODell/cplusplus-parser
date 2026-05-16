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
  vector<ASTnode> parse_input(vector<Token>);
  vector<Token> stripWhitespaces();
  ASTnode creat_tree();
  ASTnode check_operation(vector<Token>);
  ASTnode check_assignment(vector<Token>);
  ASTnode check_expression(vector<Token>);
  ASTnode check_comparator(vector<Token>);
  ASTnode check_function(vector<Token>);
  ASTnode check_if(vector<Token>);
  string grab_condition(vector<Token>);
  void print_clean_tokens();
  void print_all_tokens();
  void print_tree(ASTnode node, int depth);
};
