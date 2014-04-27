#include <stdio.h>
#include <string.h>

#define MAX 121
int adj[MAX][MAX];
int visit[MAX];
int parent[MAX];
char course[MAX][20];
int depth;
int C, k, j;

int course_index(char *name)
{
    int a;
    for (a=0; a<k; a++) {
        if (0==strcmp(name, &course[a][0])) return a;
    }
    while (1); /*trap*/
}

void dfs(int s)
{
    int j;
    visit[s] = 1;
    for (j=0; j<MAX; j++) {
        if (adj[s][j] && !visit[j]) {
            parent[j] = s;
            depth++;
            dfs(j);
        }
    }
    printf("%s ", &(course[s][0]));
}

int main(void)
{
#if 1
    freopen("925.in", "r", stdin);
#endif
    scanf("%d", &C);
    while (C--) { /*case*/
        int i;
        bzero((void *)adj, sizeof(adj));
        bzero((void *)visit, sizeof(visit));
        bzero((void *)parent, sizeof(parent));
        scanf("%d", &k);
        //printf("k=%d\n", k);
        for (i=0;i<k;i++) {
            scanf("%s", &(course[i][0]));
            //printf("%d:%s ", i, &(course[i][0]));
        }
        scanf("%d", &j);
        for (i=0;i<j;i++) {
            char name[20];
            int prerequisites, idx;
            scanf("%s %d", &name, &prerequisites);
            idx = course_index(name);
            //printf("%s-%d-%d ", name, idx, prerequisites);
            while (prerequisites--) {
                int idx2;
                scanf("%s", name);
                idx2 = course_index(name);
                //printf("%d:%d ", idx, idx);
                adj[idx2][idx] = 1;
            }
            /*parent[idx] = 0;
            depth = 0;
            dfs(idx);
            printf ("d:%s %d \n", &course[idx][0], depth);
            */
        }
        for (i=0;i<k;i++) {
            bzero((void *)visit, sizeof(visit));
            bzero((void *)parent, sizeof(parent));
            parent[i] = -1;
            depth = 0;
            dfs(i);
            printf("\n");
            //printf ("d: %s %d \n", &course[i][0], depth);
        }
    }
    return 0;
}
