#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char *input;
char lookahead;

void next_token() {
    lookahead = *input++;
}

void match(char expected) {
    if (lookahead == expected) {
        next_token();
    } else {
        fprintf(stderr, "Syntax error: expected '%c', found '%c'\n", expected, lookahead);
        exit(1);
    }
}

void parse_S();
void parse_T();
void parse_T_prime();

void parse_S() {
    if (lookahead == 'a') {
        match('a');
    } else if (lookahead == '>') {
        match('>');
    } else if (lookahead == '(') {
        match('(');
        parse_T();
        match(')');
    } else {
        fprintf(stderr, "Syntax error in S: unexpected '%c'\n", lookahead);
        exit(1);
    }
}

void parse_T() {
    parse_S();
    parse_T_prime();
}

void parse_T_prime() {
    if (lookahead == ',') {
        match(',');
        parse_S();
        parse_T_prime();
    }
    // else: epsilon production, do nothing
}

void parse_grammar1(char *str) {
    input = str;
    next_token();
    parse_S();
    if (lookahead != '\0') {
        fprintf(stderr, "Syntax error: unexpected input at end\n");
        exit(1);
    }
    printf("Parsing successful!\n");
}

int main() {
    char *test1 = "a";
    char *test2 = "(a,>)";
    char *test3 = "((aa),>)";
    
    printf("Testing Grammar 1:\n");
    parse_grammar1(test1);
    parse_grammar1(test2);
    parse_grammar1(test3);
    
    return 0;
}
