#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    char *s = NULL;
    size_t l=0;
    while (getline(&s, &l, stdin)!=-1) {
        char c, *p = s;
        int i=0, w=0;
        while (c=*p++) {
            if (isalpha(c)&&!w) {
                w=1;
                i++;
            } else if (!isalpha(c)) w=0; /*flip until non-alpha*/
        }
        printf("%d\n", i);
    }
    if (s) free(s);
    return 0;
}
