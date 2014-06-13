#include <stdio.h>

int main(void)
{
    int n, a, b;
#if 0
    freopen("11172.in", "r", stdin);
#endif
    while (scanf("%d\n", &n) == 1 && n) {
        while (n--) {
            scanf("%d %d\n", &a, &b);
            printf("%c\n", (a>b)?'>':(a<b)?'<':'=');
        }
    }
    return 0;
}
