#include "lexer.h"
#include <iostream>
#include <vector>

using namespace std;


Lexer::Lexer(string input){
  source = input;
  line_counter = 0;
  column_counter = 0;
}


vector<Token> Lexer::tokenize(){
  line_counter = 0;

  for (size_t i = 0; i < source.length();){
    string word;

    if (isalpha(source[i])){
      while (isalpha(source[i])){
        word += source[i];
        i++;
      }
      Token t;
      if (word == "int" || word == "string" || word == "bool"){
        t.type = "Keyword";
      }
      else if (word == "true" || word == "false") {
        t.type = "BoolLiteral";
      }
      else if (word == "compute" || word == "count" || word == "add"){
        t.type = "Function";
      }
      else if (word == "if"){
        t.type = "If_Check";
      }
      else {
        t.type = "Identifier";
      }
      t.value = word;
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      word = "";
    }

    else if (isdigit(source[i])){
      while (isdigit(source[i])){
        word += source[i];
        i++;
      }
      Token t;
      t.type = "Number";
      t.value = word;
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      word = "";
      }

    else if (source[i] == '\n'){
      line_counter++;
      Token t;
      t.type = "NEWLINE";
      t.value = "\\n";
      t.index = column_counter;
      tokens.push_back(t);
      word = "";
      i++;
     }

    else if (isspace(source[i])){
      while (isspace(source[i])){
        i++;
      }
      Token t;
      t.type = "Space";
      t.value = " ";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      word = "";
      }
    
    else if (source[i] == '('){
      Token t;
      t.type = "Lparen";
      t.value = "(";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      word = "";
      i++;
      }

    else if (source[i] == ')'){
      Token t;
      t.type = "Rparen";
      t.value = ")";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i++;
      }

    else if (source[i] == ';'){
      Token t;
      t.type = "EOL";
      t.value = ";";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter = 0;
      i++;
      }

    else if (source[i] == '>' || source[i] == '<' || source[i] == '!' || source[i] == '='){
      if (source[i+1] == '=') {
      Token t;
      t.type = "Comparison";
      t.value = string(1, source[i]) + string(1, source[i+1]);
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i += 2;
      }
      else if (source[i] == '='){
        Token t;
        t.type = "EQUALS";
        t.value = "=";
        t.index = column_counter;
        tokens.push_back(t);
        column_counter++;
        i++;
      }
      else {
      Token t;
      t.type = "Comparison";
      t.value = string(1, source[i]);
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i++;
      }
    }

    else if (source[i] == '.'){
      Token t;
      t.type = "DOT";
      t.value = ".";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i++;
      }

    else if (source[i] == '['){
      Token t;
      t.type = "L_BRACKET";
      t.value = "[";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i++;
      }

    else if (source[i] == ']'){
      Token t;
      t.type = "R_BRACKET";
      t.value = "]";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i++;
      }
  
    else if (source[i] == '{'){
      Token t;
      t.type = "LC_BRACKET";
      t.value = "{";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i++;
      }
  
    else if (source[i] == '}'){
      Token t;
      t.type = "RC_BRACKET";
      t.value = "}";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i++;
      }
    
    else if (source[i] == '?'){
      Token t;
      t.type = "QUESTION";
      t.value = "?";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i++;
      }

    else if (source[i] == '"'){
      Token t;
      t.type = "StringLiteral";
      i++;
      while (i < source.size() && source[i] != '"'){
        t.value += source[i];
        i++;
      }
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i++;
      }

    else if (source[i] == '\''){
      Token t;
      t.type = "StringLiteral";
      i++;
      while (i < source.size() && source[i] != '\''){
        t.value += source[i];
        i++;
      }
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i++;
      }


    else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/'){
      Token t;
      t.type = "Operation";
      t.value = string(1, source[i]);
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i++;
      }

    else {
      Token t;
      t.type = "UNKNOWN";
      t.value = string(1, source[i]);
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      i++;
    }
  }
return tokens; 
}


void Lexer::count_characters(){
  int letter_counter = 0;
  int digit_counter = 0;
  int space_counter = 0;
  int char_counter = 0;
  int line_counter = 0;
  int operator_counter = 0;
  for (size_t i = 0; i < source.length(); i++){
      if (isalpha(source[i])){
        letter_counter++;
      }
      else if (isdigit(source[i])){
        digit_counter++;
      }
      else if (source[i] == '\n'){
        line_counter++;
      }
      else if (isspace(source[i])){
        space_counter++;
      }
      else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/'){
        operator_counter++;
      }
      else {
        char_counter++;
      }
    }
  cout << "---\n"<< "Number of spaces: " << space_counter << endl;
  cout << "Number of digits: " << digit_counter << endl;
  cout << "Number of letter: " << letter_counter << endl;
  cout << "Number of 'chars': " << char_counter << endl;
  cout << "Number of operators: " << operator_counter << endl;
  cout << "Number of lines: " << line_counter << endl;
}


void Lexer::count_tokens(){
  int letter_token_counter = 0;
  int digit_token_counter = 0;
  int space_token_counter = 0;
  int char_token_counter = 0;
  int newline_counter = 0;
  int operator_token_counter = 0;
  for (int k = tokens.size() - 1; k >= 0; k--){
      if (tokens[k].type == "Identifier"){
        letter_token_counter++;
      }
      else if (tokens[k].type == "Number"){
        digit_token_counter++;
      }
      else if (tokens[k].type == "NEWLINE"){
        newline_counter++;
      }
      else if (tokens[k].type == "Space"){
        space_token_counter++;
      }
      else if (tokens[k].type == "Operation"){
        operator_token_counter++;
      }
      else{ 
        char_token_counter++;
      }
    }
  cout << "---\n" << "Number of space tokens: " << space_token_counter << endl;
  cout << "Number of digit tokens: " << digit_token_counter << endl;
  cout << "Number of letter tokens: " << letter_token_counter << endl;
  cout << "Number of char tokens: " << char_token_counter << endl;
  cout << "Number of operator tokens: " << operator_token_counter << endl;
  cout << "Number of new lines: " << newline_counter << endl;
}

const std::vector<Token>& Lexer::getTokens() const {
    return tokens;
}
