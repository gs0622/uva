#include <iostream>

using namespace std;

#define SIZE 1000001

static unsigned short table[SIZE];

int foo(int n)
{
        if ((n<SIZE) && table[n]) return table[n];

        if (n&1) {
            return (n<SIZE)? (table[n]=2+foo((3*n+1)>>1)):2+foo((3*n+1)>>1);
        } else {
            return (n<SIZE)? (table[n]=1+foo(n/2)):1+foo(n/2);
        }
}

int main(void)
{
    unsigned int i, j, k, s, e, c, max;

    table[1] = 1;
    while (cin >> i >> j) {
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
            if (c > max) max = c;
        }
        cout << i << " " << j << " " << max << endl;
    }
    return 0;
}

