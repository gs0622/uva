#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i, j, m, n;
#if 0
    freopen("369.in", "r", stdin);
#endif
    int d[101][101] = {};
    for (i=0;i<=100;i++) d[0][i]=1, d[i][0]=1;
    for (i=1;i<=100;i++)
        for (j=1;j+i<=100;j++)
            d[i][j]=d[i-1][j]+d[i][j-1];
    while (scanf("%d %d", &n, &m)==2 && n+m) {
        /*N things taken M at a time is C exactly*/
        printf("%d things taken %d at a time is %d exactly.\n", n, m, d[n-m][m]);
    }
    return 0;
}
