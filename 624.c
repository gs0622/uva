#include <stdio.h>
#define MAX(a,b)    ((a)>(b)?(a):(b))
int t[21];  /*track*/
int c[120]; /*tape dp*/
int tt[120][21];
int main(void)
{
    int i, j, k, n, tracks;
    //freopen("624.in", "r", stdin);
    while (scanf("%d", &n)!=EOF) {
        if (scanf("%d", &tracks)==1) {
            for (i=0;i<tracks;i++) scanf("%d", &t[i]);
            for (i=0;i<=n;i++) c[i]=0;
            for (i=0;i<=n;i++)
                for (j=0;j<tracks;j++) tt[i][j]=0;
            for (i=0;i<tracks;i++) {
                for (j=n;j-t[i]>=0;j--) {
                    if (c[j]<(c[j-t[i]]+t[i])) {
                        c[j]=c[j-t[i]]+t[i];
                    }
                }
            }
        }
        //for (i=0,j=n;i<tracks;i++)
        //    if (tt[j][i]==1) printf("%d ", t[i]);
        printf("sum:%d\n", c[n]);
    }
    return 0;
}

