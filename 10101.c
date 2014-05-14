/* Bangla Numbers - http://uva.onlinejudge.org/external/101/10101.html */
#include <stdio.h>

#define MODEL 0
#if (MODEL==0)
void do_bangla(unsigned long long v)
{
    unsigned long long kuti, lakh, hajar, shata;
    if (v>10000000) {
        do_bangla(v/10000000/100*100);
        if (0==(v/10000000%100)) printf("kuti ");
    }
    kuti=v/10000000%100;
    lakh=v/100000%100;
    hajar=v/1000%100;
    shata=v/100%10;
    v%=100;
    if (kuti) printf("%llu kuti ", kuti);
    if (lakh) printf("%llu lakh ", lakh);
    if (hajar) printf("%llu hajar ", hajar);
    if (shata) printf("%llu shata ", shata);
    if (v) printf("%llu", v);
}
#elif (MODEL==1)
#include <string.h>
void do_bangla(unsigned long long v)
{
    unsigned long long kuti, lakh, hajar, shata;
    char buf[64], *p=buf;
    int len = sprintf(buf, "%llu", v);
    if (len>9) {
        do_bangla(v/10000000/100*100);
        v%=1000000000;
        len = sprintf(buf, "%llu", v);
    }
    if (len>7) {printf("%lu kuti ", strtoul(strndup(p, 2), 0, 10)); p+=2;}
    if (len>5) {printf("%lu lakh ", strtoul(strndup(p, 2), 0, 10)); p+=2;}
    if (len>3) {printf("%lu hajar ", strtoul(strndup(p, 2), 0, 10)); p+=2;}
    if (len>2) printf("%lu shata ", strtoul(strndup(p, 1), 0, 10));
    if (v%100) printf("%llu ", v%100);
}
#elif (MODEL==2)
const char *z[4] = {"shata", "hajar", "lakh", "kuti"};
unsigned long long div[4] = {10, 100, 100, 100};
void bangla(unsigned long long v, int pos)
{
    unsigned int ndivpos = v % div[pos];
    if (!v) return;
    bangla(v/div[pos], (pos+1)%4);    
    if (ndivpos) printf(" %llu %s", v % div[pos], z[pos]);
    else if (pos == 3) printf(" kuti");
}
void do_bangla(unsigned long long v)
{
    bangla(v/100,0);
    if(!(v / 100) || v % 100) printf(" %llu", v % 100);
}
#else
#error MODEL
#endif
int main(int argc, char **argv)
{
    unsigned long long v;
    int i=0;
    while (scanf("%llu", &v) != EOF) {
        printf("%d. ", ++i);
        if (0!=v) do_bangla(v); else printf("0");
        printf("\n");
    }
    return 0;
}
