#include <stdio.h>

long long zsum(long long a)
{
    long long sum = (a>0)?1:0;
    long long right = 0, digit = 1;
    while (a>0) {
        if (0!=(a%10)) sum+=(a/10)*digit;
        else sum += ((a/10)-1)*digit+(right+1);
        right+=(a%10)*digit;
        a/=10;
        digit*=10;
    }
    return sum;
}

int main(int argc, char **argv)
{
    long long m, n, i;
    while (scanf("%lld %lld", &m, &n) != EOF) {
        if (m<0 || n<0) break;
        i = zsum(n) - zsum(m-1);
        printf("%u\n", i);
    }
}
