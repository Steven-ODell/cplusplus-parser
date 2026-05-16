#include "lexer.h"
#include "ast.h"
#include "evaluate.cpp"
#include <iostream>

int main() {
  std::cout << "String to tokenize:\n" << "run = true;\nTestString = 'Hello';\nTestString = string.add(' Test');\nTestStringCount = int.count(TestString);\nb = int.compute(5 + 3);\nx = 3;\nresult = x <= 3;\na = x + b;" << std::endl;
  std::string input_string = "run = true;\nTestString = 'Hello';\nTestString = string.add(' Test');\nTestStringCount = int.count(TestString);\nb = int.compute(5 + 3);\nx = 3;\nresult = x <= 3;\na = x + b;";
  
  //load the string into the lexer
  Lexer lexer(input_string);

  //take the string and turn it into an array of tokens
  lexer.tokenize();

  //needs tokenize initiated first for these to work properly
  //lexer.count_characters();
  //lexer.count_tokens();

  //parse the tokens after they are created
  Parser parser(lexer.getTokens());
  
  //unneeded way to print the cleaned tokens
  //parser.print_clean_tokens();

  //print non clean tokens
  //parser.print_all_tokens();
  ASTnode tree = parser.creat_tree() ;
  parser.print_tree(tree, 0);

  for (int i = 0; i < tree.children.size(); i++){
    evaluate(tree.children[i]);
  }

  for (const std::pair<std::string, std::string>& entry : memory) {
    std::cout << entry.first << " = " << entry.second << std::endl;
  }
  return 0;
}
