#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF 512
#define MAX 256

char st[MAX];
int top = -1;

void push(char c)
{
  if (top == MAX - 1)
  {
    printf("Stack Overflow\n");
    exit(1);
  }
  st[++top] = c;
}

char pop()
{
  if (top == -1)
  {
    printf("Stack Underflow\n");
    exit(1);
  }
  return st[top--];
}

char topE()
{
  if (top == -1)
  {
    printf("No element in stack\n");
    exit(1);
  }
  return st[top];
}

int isgte(char l, char r)
{
  if (l == '^')
    return 1;
  else if ((l == '*' || l == '/') && r != '^')
    return 1;
  else if ((l == '+' || l == '-') && (r == '+' || r == '-'))
    return 1;
  return 0;
}

void toPostfix(const char *in, int inlen, char *out, int *outlen)
{
  int i = 0, ol = 0;

  for (; i < inlen; i++, in++)
  {

    if (*in == '(')
    {
      push('(');
    }
    else if (isdigit(*in))
    {
      *out++ = *in;
      ol++;
    }
    else if (*in == ')')
    {
      char c = pop();
      while (c != '(')
      {
        *out++ = c;
        ol++;
        c = pop();
      }
    }
    else
    {
      while (top >= 0 && isgte(topE(), *in))
      {
        *out++ = pop();
        ol++;
      }
      push(*in);
    }
  }

  while (top >= 0)
  {
    *out++ = pop();
    ol++;
  }

  *out = '\0';
  *outlen = ol;
}

int main()
{
  char b[BUF];
  char oBuf[BUF];
  int ol;

  printf("Enter infix exp: ");
  gets(b);

  toPostfix(b, strlen(b), oBuf, &ol);

  printf("Converted exp:\n");
  printf("%s\n", oBuf);

  return 0;
}
