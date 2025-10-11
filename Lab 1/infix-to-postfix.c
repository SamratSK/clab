#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF 512
#define MAX 256
char st[MAX];
int top = -1;

void push(char c) {
    if(top == MAX - 1) {
        printf("Stack Overflow");
        exit(1);
    } else {
        top++;
        st[top] = c;
    }
}

char pop() {
    if(top == -1) {
        printf("Stack Underflow");
        exit(1);
        return '\0';
    } else {
        char c = st[top];
        top--;
        return c;
    }
}

char topE();
int isgte(char l, char r);

void toPostfix(const char *in, int inLen, char *out, int *outLen) {
    int i = 0; int oL = 0;

    for(; i < inLen; i++, in++) {
        if(*in == ' ') continue;

        if(*in == '(') {
            push(*in);
        } else if(isdigit(*in)) {
            *out = *in;
            out++;
            oL++;
        } else if(*in == ')') {
            char c = pop();

            while(c != '(') {
                *out = c;
                out++;
                oL++;

                c = pop();
            }
        } else {
            while(top >= 0 && isgte(topE(), *in)) {
                *out = pop();
                out++;
                oL++;
            }

            push(*in);
        }
    }
    
    *outLen = oL;
    *out = '\0';
}

char topE() {
    if(top == -1) {
        printf("No element");
        exit(1);
        return '\0';
    } else {
        return st[top];
    }
}

int isgte(char l, char r) {
    if(l == '^') {return 1;}
    else if((l == '/' || l == '*') && r != '^') {return 1;}
    else if((l == '+' || l == '-') && (r == '+' || r == '-')) {return 1;}

    return 0;
}


int main() {
    printf("Enter infix exp: ");

    char bf[BUF];
    gets(bf);

    int oL;
    char oBuf[BUF];

    toPostfix(bf, strlen(bf), oBuf, &oL);
    printf("Converted exp: \n");
    printf("%s\n", oBuf);

    return 0;
}

//(4+(3/7)-(6*8)+2/8)