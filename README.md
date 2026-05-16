# Custom C++ Parser & Interpreter Pipeline

A lightweight, from-scratch lexical analyzer, recursive AST parser, and tree-evaluating interpreter built in C++. This project demonstrates a complete compilation pipeline—transforming raw source strings into structural code trees and executing them via a global runtime state.

## Features

* **Lexer (Tokenizer):** Chunks raw string input into a strongly-typed stream of tokens while stripping white spaces and tracking text indices.
* **Abstract Syntax Tree Generator (Parser):** Processes the flat token stream using a predictive descent structure to handle variable assignments, conditional scoping, execution blocks, and method abstractions.
* **Tree Evaluator (Interpreter):** Recursively traverses the generated AST to handle execution branches, basic arithmetic, numerical comparisons, and global runtime memory tracking.
* **Built-in Testing Suite:** Main execution targets production-style script testing lines, verifying complex state tracking through multiple mutations.

---

## Architectural Overview

The code follows the classic engine design of modern interpreters:

```text
[Raw Source String] 
         │
         ▼
    (  Lexer  )     ──> Breaks characters into Token structures
         │
         ▼
 [Flat Token Stream] 
         │
         ▼
    (  Parser )     ──> Constructs structural hierarchy and tracks contexts
         │
         ▼
 [Abstract Syntax Tree] 
         │
         ▼
   ( Interpreter )  ──> Evaluates nodes recursively and mutates runtime memory
```text
```
# File Structure

lexer.h / lexer.cpp: Defines token patterns, strings/numeric literals, structural syntax indicators ({, }, (, )), and identifier classification logic.

ast.h / ast.cpp: Manages the recursive ASTnode schema. Houses structural evaluation blocks including check_expression, variable assignment tracking, and lookahead branch evaluation for loops and conditional trees.

evaluate.cpp: The execution runtime processor. Evaluates tree leaf nodes, resolves operators (+, -, *, /), handles string manipulations, compares variables, and isolates true/false tracking for execution path redirection.

main.cpp: Entry execution hub containing simulation test paths and live debug dump logic for the generated abstract syntax tree layout and internal memory registers.

# Getting Started
Prerequisites
A C++17 compatible compiler (GCC, Clang, or MSVC)

CMake (Version 3.10 or higher recommended)

# Build Instructions
Generate the build directory configuration using CMake:

Bash
cmake -B build -S .
Compile the binaries:

Bash
cmake --build build
Run the compiled executable target:

Bash
./build/cplusplus_parser

## Supported Code Patterns

The runtime pipeline is capable of parsing and executing structured operations such as:

```javascript
score = 85; 
passing = score > 80; 
grade = 'F'; 

if (passing) {
    grade = 'A'
} else {
    grade = 'C'
}; 

bonus = int.compute(score + 15); 
label = string.add(' points');bonus = int.compute(score + 15); 
label = string.add(' points');
``javascript`
```
# Future Enhancements Roadmap
Operator Dominance Upgrades: Restructuring the expression loop framework to enforce formal precedence tracking (PEMDAS) via Pratt Parsing configurations.

Unary Operators: Introducing single-operand indicators such as the logical negation operator (!) for runtime switch evaluations.

AST Expression Conditioning: Upgrading the condition parser loop from tracking a raw identifier string block to receiving full execution sub-trees natively.
