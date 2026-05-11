#include "lexer.h"
#include "ast.h"

int main() {
  std::cout << "String to tokenize: " << std::endl;
  std::string input_string = "result = obj.compute(5 + 3);\nfoo = bar;";
  
  //load the string into the lexer
  Lexer lexer(input_string);

  //take the string and turn it into an array of tokens
  lexer.tokenize();

  //needs tokenize initiated first for these to work properly
  //lexer.count_characters();
  //lexer.count_tokens();

  //parse the tokens after they are created
  Parser parser(lexer.getTokens());

  //clean the tokens of any white spaces or newlines
  std::vector<Token> cleaned_tokens = parser.stripWhitespaces();
  
  //unneeded way to print the cleaned tokens
  //parser.print_clean_tokens();

  //print non clean tokens
  parser.print_all_tokens();

  return 0;
}
