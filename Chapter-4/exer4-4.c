#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100

int getop(char []);
void Push(double);
double Pop(void);
double Top(void);
int getch(void);
void ungetch(int);
double Atof(char []);
void clear();

char buf[BUFSIZE];
int bufp = 0;
int sp = 0;
double val[MAXVAL];


int main() {
  int type;
  double op2;
  char s[MAXOP];
  while ((type = getop(s)) != EOF) {
    switch(type) {
      case NUMBER:
        Push(Atof(s));
        break;
      case '+':
        Push(Pop() + Pop());
        break;
      case '-':
        op2 = Pop();
        Push(Pop() - op2);
      case '\n':
        printf("\t%.8g\n", Top());
        break;
      case '*':
        Push(Pop() * Pop());
        break;
      case '/':
        op2 = Pop();
        if (op2 != 0.0)
          Push(Pop() / op2);
        else
          printf("Divide By Zero Error.\n");
        break;
      case '%':
        op2 = Pop();
        if (op2 != 0.0){
          int r = (int)Pop() % (int)op2;
          if (r < 0)
            Push(op2 < 0 ? r - (int)op2 : r + (int)op2);
          else
            Push(r);
        }
        else
          printf("Mod 0 not allowed.\n");
        break;
      case 'S': // swap top two elements
        op2 = Pop();
        double op1 = Pop();
        Push(op2);
        Push(op1);
        break;
      case 'D': // Duplicate the top element
        op2 = Pop();
        Push(op2);
        Push(op2);
        break;
      case 'T': // top of the stack
        printf("Top:\t%.8g\n", Top());
        break;
      case 'C': // clears the stack;
        clear();
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}


void Push(double f) {
  if (sp < MAXVAL){
    val[++sp] = f;
  }
  else
    printf("Overflow occured.\n");
}

double Pop() {
  if (sp > 0)
    return val[sp--];
  else {
    printf("Underflow occured.\n");
    return 0.0;
  }
}

double Top() {
  if (sp > 0) {
    return val[sp];
  }
  else{
    printf("Top Underflow occured.\n");
    return 0.0;
  }
}

void clear() {
  if (sp > 0){
    val[0] = 0.0;
    sp = 0;
    printf("Stack Cleared.\n");
  } else {
    printf("Stack is Empty.\n");
  }
}

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t');
  s[1] = '\0';
  
  if (!isdigit(c) && c != '.' && c != '-')
    return c;
  
  i = 0;
  if (c == '-') {
    c = getch();
    if (c == '\n') {
      return '-';
    } else {
      s[++i] = c;
    }
  }

  if (isdigit(c)) {
    while (isdigit(s[++i] = c = getch()));
  }
  
  if (c == '.')
    while (isdigit(s[++i] = c = getch()));
  
  s[i] = '\0';

  if (c != EOF)
    ungetch(c);
  
  return NUMBER;
}

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: Too many commands!");
  else
    buf[bufp++] = c;
}

double Atof(char s[]) {
  double val, power, e;
  int i, sign, exp;
  bool div;

  for(i = 0; isspace(s[i]); i++);
  
  sign = (s[i] == '-') ? -1 : 1;
  
  if (s[i] == '-' || s[i] == '+')
    i++;
  
  for(val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  
  if (s[i] == '.')
    i++;
  
  for(power = 1.0; isdigit(s[i]); i++){
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  
  if (s[i] == 'e' || s[i] == 'E') {
      i++;

    if (s[i] == '-') 
      div = true;
    
    if (s[i] == '-' || s[i] == '+')
      i++;
  
    for(exp = 0; isdigit(s[i]); i++)
      exp = exp * 10 + (s[i] - '0');

    for(e = 1.0; exp > 0; exp--)
      e = e * 10.0;
  
    if (div)
      e = 1/e;

    return (sign * val / power) * e;
  } else {
    return sign * val / power;
  }
}
