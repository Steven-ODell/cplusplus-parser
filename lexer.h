#pragma once
#include <string>
#include <cctype>
#include <iostream>
#include <vector>

struct Token {
  std::string type;
  std::string value;
  int index;
};

class Lexer {
private:
  std::string source;
  int pos;
  int line_counter;
  int column_counter;
  //telling the vector to store the token type
  std::vector<Token> tokens;
public:
  Lexer(std::string input);
  void tokenize();
  void count_characters();
  void count_tokens();
  const std::vector<Token>& getTokens() const;
};

