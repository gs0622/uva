#include <stdio.h>

int main(int argc, char **argv)
{
    int c, n, i, j, k, sum, data[1024];
    float avg;
    while (scanf("%d", &c) != EOF) {
        for (i=0; i<c; i++) {
            scanf("%d", &n);
            for (j=0, sum=0; j<n; j++) {
                scanf("%d ", &data[j]);
                sum+=data[j];
            }
            avg = sum/n;
            for (j=0, k=0; j<n; j++)
                if (data[j]>avg) k++;
            printf("%.3f%%\n", (float)(k)/(float)(n)*100);
        }
    }
}
