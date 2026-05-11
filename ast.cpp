#include "ast.h"
#include <iostream>
#include <vector>

Parser::Parser(const std::vector<Token>& t) : tokens(t) {
  current = 0;
 }

vector<Token> Parser::stripWhitespaces() {
  std::vector<Token> filtered_tokens;
  for (int i = 0; i < tokens.size(); i++){
    if (tokens[i].type != "SPACE" && tokens[i].type != "NEWLINE"){
      filtered_tokens.push_back(tokens[i]);
    }
  }
  return filtered_tokens;
}

void Parser::print_clean_tokens() {
  for (int i = 0; i < tokens.size(); i++){
    if (tokens[i].type != "SPACE" && tokens[i].type != "NEWLINE"){
      cout << tokens[i].type << ": " << tokens[i].value << " | Index: " << tokens[i].index << endl;
    }
  }
}

void Parser::print_all_tokens() {
  std::cout << "---" << std::endl;
  for (int j = 0; j < tokens.size(); j++) {
    cout << tokens[j].type << ": " << tokens[j].value << " | Index: " << tokens[j].index << endl;
  }
}
