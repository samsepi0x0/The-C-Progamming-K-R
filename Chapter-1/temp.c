
#include <stdio.h>
#define MAXIMUM 1000
#define MINIMUM 80

int getLine(char s[], int lim);

int main()
{
    int len;
    char line[MAXIMUM];

    while ((len = getLine(line, MAXIMUM)) > 0)
        if (len > MINIMUM)
        {
            printf("%s\n", line);
        }

    return 0;
}

int getLine(char s[], int lim)
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}
