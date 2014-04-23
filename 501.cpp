/*http://uva.onlinejudge.org/external/5/501.html*/
#include <stdio.h>
#include <queue>

using namespace std;

int main(int argc, char **argv)
{
    int i, j, k, m, n, a[30001], u[30001]; // N <= M <= 30000
    std::priority_queue<int, std::vector<int>, std::greater<int> > q; // min-heap
    while (scanf("%d\n", &k) == 1 && k>0) {
        scanf("%d %d\n", &m, &n);
        for (i=0;i<m; i++) scanf("%d ", &a[i]);
        for (i=0;i<n; i++) scanf("%d ", &u[i]);
        for (i=0;i<n; i++) {
            int tmp = i+1; // i-th
            for (j=0;j<u[i];j++) q.push(a[j]);
            while (--tmp) q.pop();
            printf ("%d\n", q.top());
            while (!q.empty()) q.pop();
        }
    }
    return 0;
}
