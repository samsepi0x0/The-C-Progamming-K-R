#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFSIZE 100
#define MAXVAL 100

void Push(double);
double Pop(void);
double Top(void);
int getLine(char [], int);
double Atof(char []);
void clear(void);
void print_help(void);
void print_stack(void);

char buf[BUFSIZE];
int bufp = 0;
int sp = 0;
double val[MAXVAL];


int main() {
  int type, len;
  double op2;
  char s[MAXOP];
  print_help();
  while ((len = getLine(s, MAXVAL)) > 0) {
    if (len < 3 && !isdigit(s[0])) {
      type = s[0];
    }
    else 
      type = NUMBER;
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
      
      /* --- Swap / Duplicate / Top / Clear --- */
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

      /* --- MATH Library functions --- */
      case 's': // sin of Top Value
        Push(sin(Pop()));
        break;
      case 'e':
        Push(exp(Pop()));
        break;
      case 'p':
        op2 = Pop();
        double r = Pop();
        if (r != 0 && op2 > 0)
          Push(pow(r, op2));
        else 
          printf("error: cannot raise %g to %d\n", r, op2);
        break;
      case 'P':
        print_stack();
        break;
      case 'E':
        return 0;
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
    printf("Underflow occured.\n");
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

void print_stack() {
  if (sp == 0) {
    printf("error: Empty stack.\n");
    return;
  }
  int i = 0;
  printf("=== Start of Stack ===\n");
  for(i = 0; i < sp; i++)
    printf("\t%.8g\n", val[i]);

}

int getLine(char s[], int lim) {
  int i, c;
  i = 0;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
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

void print_help(void) {
  printf("================================\n");
  printf("|      Stacky Calculator       |\n");
  printf("================================\n\n");
  printf("Analyses Reverse Polish Notation.\n");
  printf("Commands:\n");
  printf("ENTER:\tPrints the top of the stack.\n");
  printf("C:\tClears the stack\n");
  printf("S:\tSwap top two elements\n");
  printf("D:\tDuplicates the top element\n");
  printf("T:\tPrints the Top element of stack\n");
  printf("P:\tPrints entire stack (bottom to top)");
  printf("s:\tReturns sin value of the top element\n");
  printf("e:\tReturn exponent value of top element\n");
  printf("p:\tReturn x^y where x and y are top stack elements\n");
  printf("E:\tExits the program.\n\n");
}
