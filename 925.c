#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 150
char course[MAX][30];
int dag[MAX][MAX];
int pre[MAX];
int C, k, j;

static int cmp(const void *p, const void *q)
{
	return strcmp((char *)p, (char *)q);
}

static int course_index(char *name)
{
    int a;
    for (a=0; a<k; a++)
        if (0==strcmp(name, &course[a][0]))
            return a;
    return 0;
}

int main(void)
{
    scanf("%d", &C);
    while (C--) { /*case*/
        char name[30]={}, name2[30]={};
        int i, a, b, c, prerequisites;
        memset((void *)dag, 0, sizeof(dag));
        memset((void *)pre, 0, sizeof(pre));
        memset((void *)course, 0, sizeof(course));
        scanf("%d", &k);
        for (i=0;i<k;i++) scanf("%s", &(course[i][0]));
        qsort(course, k, 30, cmp); /*sort course lexicographically*/
        scanf("%d", &j);
        for (i=0;i<j;i++) { /*scan DAG*/
            scanf("%s %d", name, &prerequisites);
            b = course_index(name);
            while (prerequisites--) {
                scanf("%s", name2);
                a = course_index(name2);
                dag[a][b]=1;
            }
        }
        for (a=0;a<k;a++) /*build extended DAG*/
            for (b=0;b<k;b++)
                for (c=0;c<k;c++)
                    dag[a][b]|=dag[a][c]&dag[c][b];
        for (a=0;a<k;a++) /*build shotest DAG*/
            for (b=0;b<k;b++)
                for (c=0;c<k;c++)
                    if (dag[a][b]==1)
                        dag[a][b]^=dag[a][c]&dag[c][b];
        for (a=0;a<k;a++) /*count shotest prerequisites*/
            for (b=0;b<k;b++)
                if (dag[a][b]==1)
                    pre[b]+=1;
        for (a=0;a<k;a++) { /*output*/
            if (pre[a]>0) {
                printf("%s %d", &course[a][0], pre[a]);
                for (b=0;b<k;b++)
                    if (dag[b][a]==1)
                        printf(" %s", &course[b][0]);
                printf("\n");
            }
        }
    }
    return 0;
}
