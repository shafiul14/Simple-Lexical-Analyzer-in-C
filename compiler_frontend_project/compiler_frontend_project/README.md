# Simple Lexical Analyzer (C Compiler Front-End)

This GitHub project contains a simple lexical analyzer written in C.  
It identifies tokens such as:
- Keywords  
- Operators  
- Numbers  
- Identifiers  

## 📌 Files Included
- `lexer.c` — main source code
- `README.md` — documentation

## ▶️ How to Compile
```
gcc lexer.c -o lexer
```

## ▶️ How to Run
```
./lexer
```

## 📄 Sample Output
```
Token: int -> Keyword
Token: a -> Identifier
Token: = -> Operator
Token: 5 -> Number
Token: float -> Keyword
Token: b -> Identifier
Token: = -> Operator
Token: a -> Identifier
Token: + -> Operator
Token: 3.14 -> Number
```

Upload this folder directly to GitHub.
