#include <stdio.h>

int main(void)
{
    int n, k, i;
    long long c; /*avoid overflow*/
#if 0
    freopen("c061.in", "r", stdin);
#endif
    while (scanf("%d %d", &n, &k)==2 && n+k /*as n>0&&k>0*/ && n>=k) {
        if (k>n/2) k=n-k;/*Cnk = Cn(n-k)*/
        for (i=0,c=1; i<k; i++) c*=n-i, c/=(1+i); /*reduced common (n-k)!*/
        printf("%lld\n", c);
    }
    return 0;
}

