#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 121
char course[MAX][20];
int dep[MAX][MAX];
int pre[MAX];
int C, k, j;

static int cmp(const void *p, const void *q)
{
	return strcmp((char *)p, (char *)q);
}

int course_index(char *name)
{
    int a;
    for (a=0; a<k; a++)
        if (0==strcmp(name, &course[a][0]))
            return a;
    while (1); /*trap*/
}

int main(void)
{
#if 0
    freopen("925.in", "r", stdin);
#endif
    scanf("%d", &C);
    while (C--) { /*case*/
        char name[20], name2[20];
        int i, a, b, c, prerequisites;
        bzero((void *)dep, sizeof(dep));
        bzero((void *)pre, sizeof(pre));
        scanf("%d", &k);
        for (i=0;i<k;i++) scanf("%s", &(course[i][0]));
        qsort(&(course[0][0]), k, 20, cmp); /*sort course lexicographically*/
        scanf("%d", &j);
        for (i=0;i<j;i++) { /*scan dependancy*/
            scanf("%s %d", &name, &prerequisites);
            a = course_index(name);
            while (prerequisites--) {
                scanf("%s", name2);
                b = course_index(name2);
                dep[a][b]=1;
            }
        }
        for (a=0;a<k;a++) /*build full dependancy*/
            for (b=0;b<k;b++)
                for (c=0;c<k;c++)
                    dep[a][b]|=dep[a][c]&dep[c][b];
        for (a=0;a<k;a++) /*build shotest dependancy*/
            for (b=0;b<k;b++)
                for (c=0;c<k;c++)
                    if (dep[a][b]==1)
                        dep[a][b]^=dep[a][c]&dep[c][b];
        for (a=0;a<k;a++) /*count dependancy*/
            for (b=0;b<k;b++)
                if (dep[a][b]==1)
                    pre[a]+=1;
        for (a=0;a<k;a++) { /*output*/
            if (pre[a]>0) {
                printf("%s %d ", &course[a][0], pre[a]);
                for (b=0;b<k;b++)
                    if (dep[a][b]==1)
                        printf("%s ", &course[b][0]);
                printf("\n");
            }
        }
    }
    return 0;
}
