#include <stdio.h>
#include <string.h>

int gcd(int a, int b)
{
    if (0==b) return a;
    return gcd(b, a%b);
}

int main(void)
{
    int n, i, j, g[501], f[501][501];
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g)); /*g[1] is 0*/
    for (i=1;i<501;i++) {
#if 0
        for (j=i+1;j<=501;j++) {
            f[i][j] = f[j][i]? f[j][i]: gcd(i,j);
            g[j] += f[i][j];
        }
        g[i]+=g[i-1];
#else
        for (j=i+1;j<=501;j++) {
            f[i][j] = f[i][j-1] + gcd(i,j);
            g[j] += f[i][j];
        }
#endif
    }
    while (scanf("%d\n", &n)==1 && n && n<501) {
        printf("%d\n", g[n]);
    }
    return 0;
}


