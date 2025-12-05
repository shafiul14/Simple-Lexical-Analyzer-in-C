#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// List of C keywords
const char* keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default",
    "do", "double", "else", "enum", "extern", "float", "for", "goto",
    "if", "int", "long", "register", "return", "short", "signed",
    "sizeof", "static", "struct", "switch", "typedef", "union",
    "unsigned", "void", "volatile", "while"
};

// Check if a token is a keyword
bool isKeyword(const char* token) {
    int len = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < len; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}

// List of operators
const char* operators[] = {
    "+", "-", "*", "/", "%", "=", "==", "!=", ">", "<",
    ">=", "<=", "&&", "||", "!", "+=", "-=", "*=", "/=", "%="
};

// Check if a token is an operator
bool isOperator(const char* token) {
    int len = sizeof(operators) / sizeof(operators[0]);
    for (int i = 0; i < len; i++) {
        if (strcmp(token, operators[i]) == 0) {
            return true;
        }
    }
    return false;
}

// Check if a token is a number
bool isNumber(const char* token) {
    bool hasDecimal = false;
    for (int i = 0; token[i] != '\0'; i++) {
        if (token[i] == '.' && !hasDecimal) {
            hasDecimal = true;
            continue;
        }
        if (!isdigit(token[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    char input[] = "int a = 5; float b = a + 3.14";

    char* token = strtok(input, " \t\n;");

    while (token != NULL) {
        if (isKeyword(token)) {
            printf("Token: %s -> Keyword\n", token);
        }
        else if (isOperator(token)) {
            printf("Token: %s -> Operator\n", token);
        }
        else if (isNumber(token)) {
            printf("Token: %s -> Number\n", token);
        }
        else {
            printf("Token: %s -> Identifier\n", token);
        }

        token = strtok(NULL, " \t\n;");
    }

    return 0;
}
