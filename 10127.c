/*UVa 10127 - Ones*/
#include <stdio.h>
int main(void)
{
    int i, n, tmp;
    while (scanf("%d", &n)==1) {
        if (n%2==0 || n%5==0) continue;
        for (i=1,tmp=1;;i++) {
            if (tmp%n==0) break;
#if 1
            tmp = (tmp*10+1)%n; /*AC*/
#else
            tmp = (tmp*10+1);  /*naive, but TLE*/
#endif
        }
        printf("%d\n", i);
    }
    return 0;
}

