#include <stdio.h>
#include <stdlib.h>

/* insertion sort, a.k.a. selection sort, p == array, n = size
 */
void insertionsort(int *p, int n)
{
	int i, j, key;
    for (i=1;p && i<n;i++) {
        j=i, key=p[j]; /*O(1) space complexity*/
        while (j && p[j-1]>key) /*ascending order*/
            p[j]=p[j-1], j-=1; /*slightly faster then swap version*/
        p[j]=key;
    }
}

int main(void)
{
    int i, c, r, d[512], median, sum;
#if 0
    freopen("10041.in", "r", stdin);
#endif
    while (scanf("%d\n", &c)==1 && c) {
        while (c--) {
            if (scanf("%d", &r)==1 && r>0) {
                for (i=0;i<r;i++) scanf("%d", &d[i]);
                insertionsort(d, r);
                median=d[r/2]; /*shortest sum is median to each family*/
                for (i=0,sum=0;i<r;i++) sum+=abs(d[i]-median);
                printf("%d\n", sum);
            }
        }
    }
    return 0;
}
