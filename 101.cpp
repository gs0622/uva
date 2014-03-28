/*
The Input:
    The input begins with an integer n on a line by itself
    representing the number of blocks in the block world.
    You may assume that 0 < n < 25.

    The number of blocks is followed by a sequence of block
    commands, one command per line. Your program should process
    all commands until the quit command is encountered.

    You may assume that all commands will be of the form
    specified above. There will be no syntactically incorrect
    commands.
*/
#include <iostream>
#include <string>

using namespace std;

static int blk[25][25];
static int loc[25];
static int top[25];

static void reset_all(int n)
{
    memset((void *)blk, -1, sizeof(int)*n*25);
    for (int i=0; i<n; i++) {
        blk[i][0]=i;
        loc[i]=i;
        top[i]=0;
    }
}

static void show_result(int n)
{
    for (int i=0; i<n; i++) {
        cout << i << ":";
        for (int j=0; blk[i][j]!=-1; j++) cout << " " << blk[i][j]; 
        cout << endl;
    }
}

static void reset_block(int a)
{
    for (int j=loc[a], i=top[j]; blk[j][i]!=a; i--, top[j]--) {
        blk[blk[j][i]][0]=blk[j][i];
        blk[j][i]=-1;
        loc[blk[j][i]]=blk[j][i];
        top[blk[j][i]]=0;
    }
}

static void pop_block(int a)
{
    blk[loc[a]][top[loc[a]]]=-1;
    top[loc[a]]--;
}

static void push_block(int a, int b)
{
    top[loc[b]]++;
    blk[loc[b]][top[loc[b]]]=a;
    loc[a]=loc[b];
}

static void pile_block(int a, int b)
{
    int i, j;
    if (loc[a] == loc[b]) return;
    for (i=top[loc[a]], j=1; blk[loc[a]][i]!=a; i--, j++) loc[blk[loc[a]][i]]=loc[b];
    memcpy((void *)&blk[loc[b]][top[b]+1], (void *)&blk[loc[a]][i], j*sizeof(int));
    memset((void *)&(blk[loc[a]][i]), -1, j*sizeof(int));
    top[loc[a]]-=j;
    top[loc[b]]+=j;
    loc[a]=b;
}

void move_onto(int a, int b)
{
    reset_block(a);
    reset_block(b);
    blk[loc[a]][0]=-1;
    blk[loc[b]][1]=a;
    loc[a]=b;
    top[loc[b]]++;
}

void move_over(int a, int b)
{
    reset_block(a);
    pop_block(a);
    push_block(a, b);
}

void pile_onto(int a, int b)
{
    reset_block(b);
    pile_block(a, b);
}
void pile_over(int a, int b)
{
    pile_block(a, b);
}

int main(void)
{
    int n, a, b;
    string act, opt;

    while (cin >> n) {
        reset_all(n);
        while (cin >> act) {
            if (act == "quit") {
                show_result(n);
                break;
            }
            cin >> a >> opt >> b;
            if (act == "move") {
                if (opt == "onto") move_onto(a, b);
                if (opt == "over") move_over(a, b);
            }
            if (act == "pile") {
                if (opt == "onto") pile_onto(a, b);
                if (opt == "over") pile_over(a, b);
            }
        }
    };
    return 0;
}
