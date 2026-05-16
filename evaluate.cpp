#include "ast.h"
#include <string>
#include <map>

using namespace std;

map<string, string> memory;

string evaluate(ASTnode node, string context = ""){
  if (node.type == "Identifier") {
    if (node.children.size() > 0) {
      string result = evaluate(node.children[0], node.value);
      memory[node.value] = result;
      return result;
    }
    else {
      return memory[node.value];
    }
  }
  else if (node.type == "BoolLiteral"){
    return node.value;
  }
  else if (node.type == "StringLiteral"){
    return node.value;
  }
  else if (node.type == "Number"){
    return node.value;
  }
  else if (node.type == "Comparison"){
    string left  = evaluate(node.children[0]);
    string right  = evaluate(node.children[1]);
    int l = stoi(left);
    int r = stoi(right);
    if (left.empty() || right.empty()) return "";
    if (node.value == ">"){
      if ((l>r) == 1){
        return "true";
      }
      else {
        return "false";
      }
    } 
    if (node.value == "<"){
      if ((l<r) == 1){
        return "true";
      }
      else {
        return "false";
      }
    } 
    if (node.value == "<="){
      if ((l<=r) == 1){
        return "true";
      }
      else {
        return "false";
      }
    } 
    if (node.value == ">="){
      if ((l>=r) == 1){
        return "true";
      }
      else {
        return "false";
      }
    } 
    return node.value;
  }
  else if (node.type == "ReturnType"){
    return evaluate(node.children[0], context);
  }
  else if (node.type == "Function"){
    if (node.value == "add"){
      string l = memory[context];
      string r = evaluate(node.children[0]);
      return l+r;
    }
    else if (node.value == "compute"){
      return evaluate(node.children[0], context);
    }
    else if (node.value  == "count"){
      string l = evaluate(node.children[0]);
      return to_string(l.length());
    }
  }
  else if (node.type == "Operation"){
    string left  = evaluate(node.children[0]);
    string right  = evaluate(node.children[1]);
    int l = stoi(left);
    int r = stoi(right);
    if (left.empty() || right.empty()) return "";
    if (node.value == "+") return to_string(l+r);
    if (node.value == "-") return to_string(l-r);
    if (node.value == "*") return to_string(l*r);
    if (node.value == "/") return to_string(l/r);
  }

  else if (node.type == "If_Check"){
    string condition = memory[node.value];
    if (condition == "true") {
      for (int i = 0; i < node.children[0].children.size(); i++){
        evaluate(node.children[0].children[i]);
      }
    }
    else if (node.children.size() > 1) {
      for (int i = 0; i < node.children[1].children.size(); i++){
        evaluate(node.children[1].children[i]);
      }
    }
  }
  return "";
}

