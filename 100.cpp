#include <iostream>

using namespace std;

#define SIZE 1000001

static unsigned short table[SIZE];

int foo(int n)
{
        if (n<=1) return 0;
        if (n%2==1) return 1+foo(3*n+1);
        else return 1+foo(n/2);
}

int main(void)
{
    unsigned int i, j, k, s, e, c, max;

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
            c = 1 + foo(k);
            //cout << c << endl;
            if (c > max) max = c;
        }
        cout << i << " " << j << " " << max << endl;
    }
}

