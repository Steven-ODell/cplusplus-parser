# C++ Interpreter Pipeline

A from-scratch lexer, parser, and evaluator written in C++. No parsing libraries. Built to understand how language pipelines actually work.

## What it does

Takes a source string, tokenizes it, builds an AST, and evaluates it — storing variable state in a runtime memory map.

```
source string → lexer → token stream → parser → AST → evaluator → memory state
```

## Supported syntax

```
x = 5;
result = x > 3;
label = 'Hello';
label = string.add(' World');
count = int.count(label);
b = int.compute(x + 3);
if (result) { x = 10 } else { x = 0 };
```

Supported types: integers, strings, booleans.
Supported operations: `+` `-` `*` `/` `>` `<` `>=` `<=`
Built-in functions: `compute` (math), `add` (string concat), `count` (string length)

## File structure

- `lexer.h / lexer.cpp` — tokenizer, handles all character classification and string literal capture
- `ast.h / ast.cpp` — recursive descent parser, builds the AST from the token stream
- `evaluate.cpp` — walks the AST recursively and executes each node, writing results to a `map<string, string>` memory table
- `main.cpp` — wires everything together and prints the tree and final memory state

## Build

```bash
cmake -B build -S .
cmake --build build
./build/first_cmake_program
```

## What I learned building this

- How a lexer handles ambiguous characters (e.g. `=` vs `==`, unterminated strings)
- How a recursive descent parser tracks position through a token stream
- Why operator precedence requires restructuring the expression parser (not implemented — planned for v2)
- How an evaluator uses a symbol table to track runtime state across statements

## Planned for v2

- PEMDAS operator precedence via precedence climbing
- Unary `!` / NOT operator
- Proper test input file instead of hardcoded strings in main
