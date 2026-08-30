//pragma once is a header guard
//This tells compiler to only inclide file once per compilation.
//this is so you dont get errors if two files have the header
#pragma once
#include <string>
#include <cctype>
#include <vector>

//Create a struct to hold the data for the token array
struct Token {
  std::string type;
  std::string value;
  int index;
};

//Define a Lexer Class.
//Creates the structure and functions that you then use in lexer.cpp
class Lexer {
private:
  std::string source;
  int line_counter;
  int column_counter;
  //Telling the vector(growing-array) to store the token type
  std::vector<Token> tokens;
public:
  //Set up the constructor. This gets called in main
  Lexer(std::string input);
  //declare the function to tokenize are store them in an array
  std::vector<Token> tokenize();
  //Define other functions (just for learning and fun)
  void count_characters();
  void count_tokens();
  //This is a pointer set up with const and "&"
  const std::vector<Token>& getTokens() const;
};

