/* Bangla Numbers - http://uva.onlinejudge.org/external/101/10101.html */
#include <stdio.h>
#if 1
void do_bangle(unsigned long long v)
{
    unsigned long long w;
    unsigned long long kuti, lakh, hajar, shata;
    if (v>10000000) do_bangle(v/10000000/100*100);
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

int main(int argc, char **argv)
{
    unsigned long long v;
    while (scanf("%llu", &v) != EOF) {
        do_bangle(v);
        printf("\n");
    }
}
#else
#include <string.h>
void do_bangle(unsigned long long v)
{
    unsigned long long w;
    unsigned long long kuti, lakh, hajar, shata;
    char buf[64], buf2[4], *p;
    int len = sprintf(buf, "%llu", v);
    if (len>9) {
        w = v/1000000000;
        do_bangle(w);
        v%=1000000000;
        len = sprintf(buf, "%llu", v);
    }
    p=buf;
#if 0 /*TBD*/
    //printf("%s\n", p);
    //printf("%s\n", strndup(p, 2));
    if (len>7) {printf("%lu kuti ", strtoul(strndup(p, 2), 0, 10)); p+=2;}
    if (len>5) {printf("%lu lakh ", strtoul(strndup(p, 2), 0, 10)); p+=2;}
    if (len>3) {printf("%lu hajar ", strtoul(strndup(p, 2), 0, 10)); p+=2;}
    if (len>2) printf("%lu hajar ", strtoul(strndup(p, 1), 0, 10));
    if (v%100) printf("%llu ", v%100);
#endif
}

int main(int argc, char **argv)
{
    unsigned long long v;
    while (scanf("%llu", &v) != EOF) {
        do_bangle(v);
        printf("\n");
    }
}
#endif

