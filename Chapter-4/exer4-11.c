int getop(char s[]) {
  int i, c;
  static char buf = EOF;

  if (buf == EOF || buf == ' ' || buf == '\t') {
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';  
  } else 
    c = buf;
  if (!isdigit(c) && c != '.')
    return c;
  i = 0;
  if (isdigit(c))
    while(isdigit(s[++i]) = c = getch());
  if (c == '.')
    while(isdigit(s[++i]) = c = getch());

    s[i] = '\0';
  if (c != EOF)
    buf = EOF;
  return NUMBER;

}
