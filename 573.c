#include <stdio.h>

int main(void)
{
    int h, u, d, f, i, hh, uu;
#if 0
    freopen("573.in", "r", stdin);
#endif
    while (scanf("%d %d %d %d", &h, &u, &d, &f)==4 && h>0) {
        for (i=0,hh=0;;i++) { /*avoid use float hence multiply by 100 times */
            uu=(u*100-i*u*f), hh += (uu>0)? uu:0; /*climb in day*/
            if (hh>100*h) break; /*success while over*/
            hh -= 100*d; /*fall in night*/
            if (hh<0) break; /*failure while negative*/
        }
        printf("%s on day %d\n", (hh<=0)?"failure":"success", i+1);
    }
    return 0;
}
