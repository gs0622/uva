#include <stdio.h>
#include <math.h>

int main(void)
{
    int i, j, k, n;
#if 0
    freopen("d131.in", "r", stdin);
#endif
    while (scanf("%d\n", &n)==1 && n) {
        int c[98]={}; /*count all, last prime 97*/
        for (i=n;i>=2;i--)
            for (j=2,k=i;j<=i;j++) if (k%j==0) k/=j, c[j]++, j--;
        printf ("%3d! =", n);
        for (i=2,j=0;i<98;i++) {
            if (c[i]) { /*notice: additional \n will cause WA*/
                if (j==15) { j=0, printf("\n       "); }
                else if (j<15) printf(" ");
                ++j, printf("%2d", c[i]);
            }
        }
        printf ("\n");
    }
    return 0;
}
