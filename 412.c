/*http://uva.onlinejudge.org/external/4/412.html*/
#include <stdio.h>
#include <math.h>

/*greatest common divisor*/
int gcd(int a, int b)
{
    if (0==b) return a;
    return gcd(b, a%b);
}

int main(int argc, char **argv)
{
    int i, j, n, count, data[64];
    while (scanf("%d\n", &n) != EOF) {
        if (n==0 || n>50) break;
        count = 0;
        for (i=0;i<n;i++) scanf("%d\n", &data[i]);
        for (i=0;i<n;i++) {
            for (j=i+1;j<n;j++) {
                if (1 == gcd(data[i], data[j])) count++;
            }
        }
        if (0==count)
            printf("No estimate for this data set.\n");
        else {
            double v = n*(n-1)/2; /*c(n,2)*/
            printf("%.6f\n", sqrt(6.0*v/(double)count));
        }
    }
    return 0;
}
