/*http://uva.onlinejudge.org/external/112/11218.html*/
#include <stdio.h>

typedef struct {
    unsigned short team; /*bitset 1-9*/
    unsigned short score;
} group_t;

int main(int argc, char **argv)
{
    int i, j, k, n, a, b, c, s, t, score, max_s, cnt = 0;
    const unsigned short bitmask = (1<<10)-2; /*0b1111111110*/
    group_t ktv[81];
    while (scanf("%d\n", &n) == 1 && n>0 && n<81) {
        for (i=0;i<n;i++) {
            scanf("%d %d %d %d\n", &a, &b, &c, &s);
            t = 1<<a;
            t |= 1<<b;
            t |= 1<<c;
            ktv[i].team = t;
            ktv[i].score = s; 
        }
        max_s = -1;
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                for (k=0;k<n;k++) {
                    if (bitmask == (ktv[i].team | ktv[j].team |
                        ktv[k].team)) { /*disjoint*/
                        score = ktv[i].score + ktv[j].score +
                            ktv[k].score;
                        if (score > max_s) max_s = score;
                    }
                }
        printf("Case %d: %d\n", ++cnt, max_s);
    }
    return 0;
}
