#include <stdio.h>

void do_bangla(unsigned long long v)
{
    unsigned long long kuti, lakh, hajar, shata;
    if (v>10000000) {
        do_bangla(v/10000000/100*100);
        if (0==(v/10000000%100)) printf(" kuti");
    }
    kuti=v/10000000%100;
    lakh=v/100000%100;
    hajar=v/1000%100;
    shata=v/100%10;
    v%=100;
    if (kuti) printf(" %llu kuti", kuti);
    if (lakh) printf(" %llu lakh", lakh);
    if (hajar) printf(" %llu hajar", hajar);
    if (shata) printf(" %llu shata", shata);
    if (v) printf(" %llu", v);
}

int main(int argc, char **argv)
{
    unsigned long long v;
    int i=0;
#if 0
    freopen("10101.in", "r", stdin);
#endif
    while (scanf("%llu", &v) != EOF) {
        printf("%4d.", ++i);
        if (0!=v) do_bangla(v); else printf(" 0");
        printf("\n");
    }
    return 0;
}
