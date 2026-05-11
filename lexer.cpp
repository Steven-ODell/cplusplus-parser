#include "lexer.h"

using namespace std;


Lexer::Lexer(string input){
  source = input;
  pos = 0;
  line_counter = 0;
  column_counter = 0;
}


void Lexer::tokenize(){
  line_counter = 0;

  for (int i = 0; i < source.length();){
    string word;
    int start = i;

    if (isalpha(source[i])){
      while (isalpha(source[i])){
        word += source[i];
        i++;
      }
      Token t;
      t.type = "LETTER";
      t.value = word;
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      word = "";
      start = i;
    }

    else if (isdigit(source[i])){
      while (isdigit(source[i])){
        word += source[i];
        i++;
      }
      Token t;
      t.type = "NUMBER";
      t.value = word;
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      word = "";
      start = i;
      }

    else if (source[i] == '\n'){
      line_counter++;
      Token t;
      t.type = "NEWLINE";
      t.value = "\\n";
      t.index = column_counter;
      tokens.push_back(t);
      word = "";
      start = i;
      i++;
     }

    else if (isspace(source[i])){
      while (isspace(source[i])){
        i++;
      }
      Token t;
      t.type = "SPACE";
      t.value = " ";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      word = "";
      start = i;
      }
    
    else if (source[i] == '('){
      Token t;
      t.type = "LPAREN";
      t.value = "(";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      word = "";
      start = i;
      i++;
      }

    else if (source[i] == ')'){
      Token t;
      t.type = "RPAREN";
      t.value = ")";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      start = i;
      i++;
      }

    else if (source[i] == ';'){
      Token t;
      t.type = "SEMICOLON";
      t.value = ";";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter = 0;
      start = i;
      i++;
      }

    else if (source[i] == '='){
      Token t;
      t.type = "EQUALS";
      t.value = "=";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      start = i;
      i++;
      }

    else if (source[i] == '.'){
      Token t;
      t.type = "DOT";
      t.value = ".";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      start = i;
      i++;
      }

    else if (source[i] == '['){
      Token t;
      t.type = "LBRACKET";
      t.value = "[";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      start = i;
      i++;
      }

    else if (source[i] == ']'){
      Token t;
      t.type = "RBRACKET";
      t.value = "]";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      start = i;
      i++;
      }
    
    else if (source[i] == '?'){
      Token t;
      t.type = "QUESTION";
      t.value = "?";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      start = i;
      i++;
      }

    else if (source[i] == '"'){
      Token t;
      t.type = "DQUOTE";
      t.value = "\"";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      start = i;
      i++;
      }

    else if (source[i] == '\''){
      Token t;
      t.type = "QUOTE";
      t.value = "'";
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      start = i;
      i++;
      }

    else if (source[i] == '+' || source[i] == '-' || source[i] == '*' || source[i] == '/'){
      Token t;
      t.type = "OPERATOR";
      t.value = string(1, source[i]);
      t.index = column_counter;
      tokens.push_back(t);
      column_counter++;
      start = i;
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

}


void Lexer::count_characters(){
  int letter_counter = 0;
  int digit_counter = 0;
  int space_counter = 0;
  int char_counter = 0;
  int line_counter = 0;
  int operator_counter = 0;
  for (int i = 0; i < source.length(); i++){
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
      if (tokens[k].type == "LETTER"){
        letter_token_counter++;
      }
      else if (tokens[k].type == "NUMBER"){
        digit_token_counter++;
      }
      else if (tokens[k].type == "NEWLINE"){
        newline_counter++;
      }
      else if (tokens[k].type == "SPACE"){
        space_token_counter++;
      }
      else if (tokens[k].type == "OPERATOR"){
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
