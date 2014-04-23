/*http://uva.onlinejudge.org/external/5/501.html*/
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    int i, c, m, n, a[30000];
    scanf("%d\n", &c);
    while (c--) {
        std::vector<int> v;
        scanf("%d %d\n", &m, &n);
        for (i=0;i<m; i++) scanf("%d", &a[i]);
        int u, j=0, k=0;
        while (n--) {
            scanf("%u", &u);
            while (j<u) {
                vector<int>::iterator it = lower_bound(v.begin(), v.end(), a[j]);
                v.insert(it, a[j++]);
            }
            printf("%d\n", v[k++]);
        }
        if (c) printf ("\n"); /*last case no blank line*/
    }
    return 0;
}
