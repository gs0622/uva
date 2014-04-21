/*http://uva.onlinejudge.org/external/1/p105.pdf*/
#include <stdio.h>
#include <string.h>

int main(void)
{
    int i=0, j, l, h, r, map[10000+1], max_r=0, skyline=0;
    memset((void *)map, 0, sizeof(map));
    while (scanf("%d %d %d\n", &l, &h, &r) == 3) {
        for (i=l; i<r; i++) {
            if (h>map[i]) map[i] = h;
            if (r>max_r) max_r = r;
        }
    }
#if 0
    for (i=0; i<max_r+1; i++) printf("%.2d ", map[i]);
    printf("\n");
#endif
    for (i=0; i<max_r; i++) {
        if (skyline==map[i]) continue;
        skyline = map[i];
        printf("%d %d ", i, skyline);
    }
    printf("%d 0\n", max_r);
    return 0;
}
