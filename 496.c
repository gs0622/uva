#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 4096
char seta[MAX], setb[MAX];

int equal(char *a, char *b)
{
    int i;
    for (i=0;i<MAX;i++)
        if (a[i] != b[i])
            return 0; /*false*/
    return 1; /*true*/
}

int contain(char *a, char *b)
{
    int i;
    for (i=0;i<MAX;i++)
        if (!a[i] & b[i])
            return 0; /*false*/
    return 1; /*true*/
}

int disjoint(char *a, char *b)
{
    int i;
    for (i=0;i<MAX;i++)
        if (a[i] & b[i])
            return 0; /*false*/
    return 1; /*true*/
}

void compare(char *a, char *b)
{
    if (equal(a, b)) printf("A equals B\n");
    else if (contain(a, b)) printf("B is a proper subset of A\n");
    else if (contain(b, a)) printf("A is a proper subset of B\n");
    else if (disjoint(a, b)) printf("A and B are disjoint\n");
    else printf("I'm confused!\n");
}

int main(int argc, char **argv)
{
    static char flip = 1; /*1 for line-A, 0 for line-B*/
    char *line, *p, *q;
    size_t len;
    while (-1 != getline(&line, &len, stdin)) {
        //printf("%c=%s", flip? 'A':'B', line);
        p = strtok(line, " ");
        q = (flip)? seta : setb;
        while (p) {
            q[atoi(p)] = 1;
            p = strtok(NULL, " ");
        }
        if (0/*B*/==flip) {
            compare(seta, setb);
            memset((void *)seta, 0, MAX);
            memset((void *)setb, 0, MAX);
        }
        flip=!flip;
    }
}
