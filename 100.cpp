#include <iostream>
#include <ctime>

using namespace std;

#define SIZE 1000001

static unsigned short table[SIZE];

#if 1
int foo(int n)
{
        if ((n<SIZE) && table[n]) return table[n];

        if (n&1) {
            return (n<SIZE)? (table[n]=2+foo((3*n+1)>>1)):2+foo((3*n+1)>>1);
        } else {
            return (n<SIZE)? (table[n]=1+foo(n/2)):1+foo(n/2);
        }
}
#else
int foo(int n)
{
        if (n<=1) return 1;
        if (n%2==1) {
            return 1+foo(3*n+1);
        } else {
            return 1+foo(n/2);
        }
}
#endif

int main(void)
{
    unsigned int i, j, k, s, e, c, t, max;

    table[1] = 1;
    while (cin >> i >> j) {
        t = clock();
        max = 0;
        if (j>=i) {
            s=i;
            e=j;
        } else {
            s=j;
            e=i;
        }
        for (k=s;k<=e;k++) {
            c = foo(k);
            //cout << c << endl;
            if (c > max) max = c;
        }
        cout << i << " " << j << " " << max << " " << clock()-t << endl;
    }
}

