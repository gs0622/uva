/* http://acm-solution.blogspot.tw/2010/11/acm-uva-103-stacking-boxes.html */
#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

#if 1
struct box_t {
    int id;
    int edge[10];
} box[30];

int dp[30];
int parent[30];

static int k, n; /*k boxes, n dimensionality*/

int cmp(int a, int b)
{
    for (int i=0; i<n; i++)
        if (box[a].edge[i] <= box[b].edge[i]) return 0; /*false*/
    return 1; /*true*/
}

void trace(int i)
{
    if (parent[i] != -1) trace(parent[i]);
    cout << box[i].id << " ";
}

int naive_lis(void)
{
    for (int i=0; i<k; i++) {
        dp[i]=1;
        parent[i]=-1;
    }
    for (int i=0; i<k; i++) {
        for (int j=i+1; j<k; j++) {
            if (cmp(j,i) && (dp[i]+1 > dp[j])) {
                dp[j] = dp[i] + 1;
                parent[j] = i;
            }
        }
    }
    int max = 0, end;
    for (int i=0; i<k; i++) {
        if (max < dp[i]) {
            max = dp[i];
            end = i;
        }
    }
    cout << max << endl;
    trace(end);
    cout << endl;
    return max;
}

int main(void)
{
    while (cin >> k >> n) {
        if (k>30) continue;
        for (int i=0; i<k; i++) {
            box[i].id = i+1;
            for (int j=0; j<n; j++) cin >> box[i].edge[j];
        }
        for (int i=0; i<k; i++) sort(box[i].edge, box[i].edge+n);
        for (int i=k-1; i>0; i--) {
            for (int j=0; j<i; j++)
                if (cmp(j, j+1)) swap(box[j], box[j+1]);
        }
        naive_lis();
    }
    return 0;
}
#else
struct node {   
    int id;
    int d[12];
} a[32];

int k;
int n;
int best[32];
int parent[32];
vector <int> v; 

bool cmp(int x, int y)
{
    for (int i=0; i<n; i++) {
        if (a[x].d[i] <= a[y].d[i]) return false;
    }
    return true;
}

void print_path(int x)
{
    if (x == parent[x]) return;
    print_path(parent[x]);
    v.push_back(a[parent[x]].id);
}

int lis(void)
{
    for (int i = 0; i < k; i++) {
        best[i] = 1;
        parent[i] = i;
    }

    for (int i = 1; i < k; i++) {
        for (int j = 0; j < i; j++) {
            if (cmp (i, j) && best[i] < best[j] + 1) {
                best [i] = best [j] + 1;
                parent [i] = j;
            }
        }
    } 

    int index;
    int max = 0;
    for (int i = 0; i < k; i++) {
        if (max < best[i]) {
            max = best [i];
            index = i;
        }
    }
    print_path(index);
    v.push_back(a[index].id);
    return max;
}

int main(void)
{  
    while (scanf ("%i %i", &k, &n) != EOF) {
        v.clear();
        for (int i=0; i<k; i++) {
            a[i].id = i + 1;
            for (int j=0; j<n; j++) scanf("%d", &a [i].d [j]);
            sort (a[i].d, a[i].d + n);
        }

        // bubble sort
        for (int i=0; i<k; i++) {
            for (int j = i + 1; j<k; j++) {
                    if (cmp(i, j)) swap(a[i], a[j]);
            }
        }

        printf ("%d\n", lis());
        for (unsigned int i=0; i<v.size(); i++) {
            if (i != 0)
                printf (" ");
            printf ("%d", v.at (i));
        }
        printf ("\n");
    }
    return 0;
}
#endif
