#include <stdio.h>
int citizen[30001], n, m, max;
int IsFriend(int p, int q)
{
    return (citizen[p]==citizen[q]); /*1 for yes, 0 for no*/
}
void Union(int p, int q)
{
    int i, gid, cnt;
    if (IsFriend(p, q)) return;
    for (i=1,gid=citizen[p];i<=n;i++)
        if (citizen[i]==gid) citizen[i]=q;
    for (i=1,cnt=0,gid=citizen[q];i<=n;i++) {
        if (citizen[i]==gid) cnt++;
    }
    if (cnt>max) max=cnt;
}
int main(void)
{
    int c, i, p, q;
    scanf("%d", &c); /*cases*/
    while (c--) {
        scanf("%d %d", &n, &m);
        for (i=1;i<=n;i++) citizen[i] = i;
        for (i=1,max=0;i<=m;i++) {
            scanf("%d %d", &p, &q);
            Union(p, q);
        }
        printf("%d\n", max);
    }
    return 0;
}

