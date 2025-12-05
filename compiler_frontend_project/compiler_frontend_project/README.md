# Simple Lexical Analyzer 
This project implements a simple lexical analyzer (tokenizer) in C.
Its purpose is to read a piece of C-like code, break it into tokens, and classify each token into:
Keywords
Identifiers
Operators
Numbers
Unknown tokens
Additionally, this project integrates rules similar to Flex/Lex patterns, such as:
Capital-letter identifiers ([A-Z][a-zA-Z0-9]*)
Operator recognition
Ignoring whitespace
Catching unknown characters

Features:

✔ Detects and classifies C keywords
✔ Detects operators like +, -, *, /, %, =, ==, +=, etc.
✔ Supports integer and floating-point numbers
✔ Identifies valid identifiers, including those beginning with capital letters
✔ Ignores whitespace automatically
✔ Shows a summary of all token counts
✔ Example input tokenized.
How the Program Works:-
1. Keyword List:
The program contains a list of all standard C keywords:
const char* keywords[] = { "auto", "break", "case", "char", ... };
The isKeyword() function compares each token using strcmp() to determine if it's a keyword.

2. Operator List:-
The analyzer recognizes both single and multi-character operators,
const char* operators[] = {
    "+", "-", "*", "/", "%", "=", "==", "!=", ">", "<",
    ">=", "<=", "&&", "||", "!", "+=", "-=", "*=", "/=", "%="
};
The isOperator() function checks each token against this list.s folder directly to GitHub.

3. Number Detection:-
The analyzer recognizes:
Integer literals (5, 100)
Floating-point numbers (3.14, 0.5)
bool isNumber(const char* token);
It allows only digits and at most one decimal point.

4. Identifier Detection:-
Two identifier rules are included.
4.1 Regular identifiers (Flex-style)
[A-Za-z_][a-zA-Z0-9_]*
In the code, anything that is not a:
Keyword
Operator
Number
is treated as an identifier.

4.2 Capital-letter identifiers:-
This reflects the Lex rule.
[A-Z][a-zA-Z0-9]*
Implemented as:
bool isCapitalIdentifier(const char* token);

5. Tokenizing the Input:-
The input string.
char input[] = "int a = 5; float b = a + 3.14";
is split using:
strtok(input, " \t\n;");
This removes whitespace and ; separators.
Each extracted token is then classified.

6. Output Summary:-
After processing all tokens, the program prints.

===== TOKEN SUMMARY =====
Total Tokens     : 9
Keywords         : 2
Identifiers      : 3
Operators        : 2
Numbers          : 2
This helps evaluate how many types of tokens were found.

Keyword Logic:-
isKeyword() loops through the keyword list and checks if the token matches any known C keyword.

Operator Logic:-
isOperator() compares each token against the defined list of operators.

Number Detection Logic:-
isNumber() validates:
digits only
one optional decimal
Thus it correctly classifies integers and floats.

Capital Identifier Rule:-
Simulates Lex rule.
[A-Z][a-zA-Z0-9]*
Useful for detecting special types or constants starting with capital letters.

Token Processing Loop:-
The tokenizer uses strtok() to extract tokens, then classifies them in this order:
Keyword
Operator
Number
Capital Identifier
Regular Identifier
This ensures accurate classification.

Conclusion:
This program provides a simple but effective lexical analyzer written in pure C, imitating some features of Lex/Flex using only standard libraries.
It is ideal for:-
Compiler design assignments
Lexical analysis demonstrations
Understanding tokenization basics
BSc Computer Science projects
