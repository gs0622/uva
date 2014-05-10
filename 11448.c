#include <stdio.h>
#include <string.h>

typedef struct {
    int len; /*digit length*/
    char dig[10002]; /*digit*/
    int rev[10002]; /*reversed digit*/
} bignum_t;

void digrev(char *p, int *q, int len)   
{
    char *m=p;
    int *n=q+len;
    for(*n--=0; n>=q; ++m, --n) *n=*m-'0';
}

void revdig(int *p, char *q, int len)
{
    int *m=p;
    char *n=q+len;
    for(*n--=0; n>=q; ++m, --n) *n=*m+'0';
}

void numbering(bignum_t *p)
{
    memset(p->rev, 0, 10002);
    p->len=strlen(p->dig), digrev(p->dig, p->rev, p->len);
}

int largethan(bignum_t *p, bignum_t *q) /* ">=" operator*/
{
    int cmp = (p->len == q->len)? strcmp(p->dig, q->dig) : (p->len - q->len);
    return cmp = (cmp >= 0)? 1:0;
}

void minus(bignum_t *p, bignum_t *q, bignum_t *r)
{
    int i, max, cmp = largethan(p, q);
    bignum_t *m, *n;
    r->len = max = (p->len > q->len)? p->len:q->len;
    if (cmp) m=p, n=q; else m=q, n=p;
    for (i=0;i<max;i++) r->rev[i] += m->rev[i] - n->rev[i];
    for (i=0;i<max;i++) if (r->rev[i]<0) r->rev[i]+=10, r->rev[i+1]-=1;
    for (i=max-1;i>0&&r->rev[i]==0;i--, r->len--);
    if (cmp) revdig(r->rev, r->dig, r->len);
    else r->dig[0]='-', revdig(r->rev, r->dig+1, r->len);
}

int main(void)
{
    int i, n;
#if 0
    freopen("11448.in", "r", stdin);
#endif  
    while (scanf("%d", &n)==1 && n>0) {
        for (i=0;i<n;i++) {
            bignum_t x={}, y={}, z={};
            scanf("%s %s", x.dig, y.dig);
            numbering(&x), numbering(&y), minus(&x, &y, &z);
            printf("%s\n", z.dig);
        }
    }
    return 0;
}
