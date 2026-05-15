#include "ast.h"
#include <iostream>
#include <vector>

Parser::Parser(const vector<Token>& t) : tokens(t) {
  current = 0;
 }


vector<Token> Parser::stripWhitespaces() {
  vector<Token> filtered_tokens;
  for (int i = 0; i < tokens.size(); i++){
    if (tokens[i].type != "Space" && tokens[i].type != "NEWLINE"){
      filtered_tokens.push_back(tokens[i]);
    }
  }
  return filtered_tokens;
}


vector<ASTnode> Parser::parse_input(vector<Token> tokens) {
  vector<Token> filtered_tokens = stripWhitespaces();
  vector<ASTnode> tree;
  while (current < filtered_tokens.size()) {
    if (filtered_tokens[current].type == "EOL") {
      current++;
    }
    else if (filtered_tokens[current].type == "Identifier" && filtered_tokens[current + 1].type == "EQUALS"){
      tree.push_back(check_assignment(filtered_tokens));
    }
    else {
      current++;
    }
    //tree.push_back(check_function(filtered_tokens));
  }
  return tree;
}


ASTnode Parser::creat_tree() {
  ASTnode root;
  root.type = "Program";
  root.value = "Main";
  root.children = parse_input(tokens);
  return root;
}


ASTnode Parser::check_assignment(vector<Token> tokens) {
    ASTnode node;
    node.type = tokens[current].type;
    node.value = tokens[current].value;
    current += 2;
    node.children.push_back(check_expression(tokens));
    return node;
}


ASTnode Parser::check_expression(vector<Token> tokens) {
  ASTnode node;
  node.value = tokens[current].value;
  node.type = tokens[current].type;
  current++;

  if (current < tokens.size() && tokens[current].type == "Keyword"){
    ASTnode assignment_node;
    assignment_node.type = tokens[current].type;
    assignment_node.value = tokens[current].value;
    current++;

    assignment_node.children.push_back(check_expression(tokens));

    return assignment_node;
  }


  else if (current < tokens.size() && tokens[current].type == "DOT"){
    ASTnode method_node;
    method_node.type = "ReturnType";
    method_node.value = tokens[current-1].value;
    current++;
    ASTnode expression_node;
    expression_node.type = tokens[current].type;
    expression_node.value = tokens[current].value;
    current++;
    current++;
    while (current < tokens.size() && tokens[current].type != "RPAREN"){
      expression_node.children.push_back(check_expression(tokens));
    }
    if (tokens[current].type == "RPAREN"){
      current++;
    }
    method_node.children.push_back(expression_node);
    return method_node;

  }


  else if (tokens[current].type == "LPAREN"){
    current++;
  }


  else if (current < tokens.size() && tokens[current].type == "Operation"){
    ASTnode assignment_node;

    assignment_node.type = tokens[current].type;
    assignment_node.value = tokens[current].value;
    current++;
    assignment_node.children.push_back(node);
    assignment_node.children.push_back(check_expression(tokens));

    return assignment_node;
  }



  else if (current < tokens.size() && tokens[current].type == "Comparison"){
    ASTnode assignment_node;

    assignment_node.type = tokens[current].type;
    assignment_node.value = tokens[current].value;
    current++;
    assignment_node.children.push_back(node);
    assignment_node.children.push_back(check_expression(tokens));

    return assignment_node;
  }
  return node;
}


void Parser::print_tree(ASTnode node, int depth){
  for (int d = depth; d > 0; d--) cout << "  ";
  cout << node.type << ": " << node.value << endl;
  for (int i = 0; i < node.children.size(); i++){
    print_tree(node.children[i], depth + 1);
  }
}

void Parser::print_clean_tokens() {
  for (int i = 0; i < tokens.size(); i++){
    if (tokens[i].type != "Space" && tokens[i].type != "NEWLINE"){
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
