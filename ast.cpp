#include "ast.h"
#include <iostream>
#include <vector>

Parser::Parser(const vector<Token>& t) : tokens(t) {
  current = 0;
 }

vector<Token> Parser::stripWhitespaces() {
  vector<Token> filtered_tokens;
  for (int i = 0; i < tokens.size(); i++){
    if (tokens[i].type != "SPACE" && tokens[i].type != "NEWLINE"){
      filtered_tokens.push_back(tokens[i]);
    }
  }
  return filtered_tokens;
}

vector<ASTnode> Parser::parse_input() {
  vector<Token> filtered_tokens = stripWhitespaces();
  vector<ASTnode> tree;
  for (int j = 0; j < filtered_tokens.size(); j++) {
    ASTnode node;
    if (filtered_tokens[j].type == "LETTER" && filtered_tokens[j+1].type == "EQUALS"){
      node.type = "Variable";
      node.value = filtered_tokens[j].value;
      node.children.push_back(check_variable_assignment(filtered_tokens, j));
      tree.push_back(node);
    }
  }
  return tree;
}

ASTnode Parser::creat_tree() {
  ASTnode root;
  root.type = "Program";
  root.value = "Main";
  root.children = parse_input();
  return root;
}

void Parser::print_clean_tokens() {
  for (int i = 0; i < tokens.size(); i++){
    if (tokens[i].type != "SPACE" && tokens[i].type != "NEWLINE"){
      cout << tokens[i].type << ": " << tokens[i].value << " | Index: " << tokens[i].index << endl;
    }
  }
}

void Parser::print_all_tokens() {
  cout << "---" << endl;
  for (int j = 0; j < tokens.size(); j++) {
    cout << tokens[j].type << ": " << tokens[j].value << " | Index: " << tokens[j].index << endl;
  }
}

ASTnode Parser::check_variable_assignment(vector<Token> tokens, int j) {
  ASTnode variable_assignment;
  int depth = 1;
  for (int i = (j+2); i < tokens.size();){
    if (tokens[i].type == "SEMICOLON"){
      i++;
      return variable_assignment;
    }
    else {
      variable_assignment.type = "Assignment";
      while (tokens[i].type != "SEMICOLON"){
        depth++;
        variable_assignment.value += tokens[i].value;
        i++;
      }
    }
  }
  return variable_assignment;
}

void Parser::print_tree(ASTnode node, int depth){
  cout << node.type << ": " << node.value << endl;
  for (int i = 0; i < node.children.size(); i++){
    print_tree(node.children[i], depth + 1);
  }
}
