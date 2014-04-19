/*
The Input:
    The input consists of a series of lines with each line containing
    9 integers. The first three integers on a line represent the number
    of brown, green, and clear bottles (respectively) in bin number 1,
    the second three represent the number of brown, green and clear
    bottles (respectively) in bin number 2, and the last three
    integers represent the number of brown, green, and clear
    bottles (respectively) in bin number 3.
    For example, the line 10 15 20 30 12 8 15 8 31 indicates that
    there are 20 clear bottles in bin 1, 12 green bottles in bin 2,
    and 15 brown bottles in bin 3.

    Integers on a line will be separated by one or more spaces.
    Your program should process all lines in the input file.
*/
#include <iostream>

using namespace std;

enum { B=0, C=1, G=2 };

int main(void)
{
/* Why WA?
If more than one order of brown, green, and clear bins 
yields the minimum number of movements then the alphabetically
first string representing a minimal configuration should be printed.
*/
    char state[6][3] = { {B,C,G}, {B,G,C}, {C,B,G},
                         {C,G,B}, {G,B,C}, {G,C,B} };
    char str[6][4] = { "BCG", "BGC", "CBG", "CGB", "GBC", "GCB" };
    int i, bin[3][3]/*BGC order*/, all, mov, min, ret;

    while (cin >> bin[0][B] >> bin[0][G] >> bin[0][C]
               >> bin[1][B] >> bin[1][G] >> bin[1][C]
               >> bin[2][B] >> bin[2][G] >> bin[2][C]) {
        for (i=0, all=0; i<9; i++) all+=bin[(i<3)?0:(i<6)?1:2][i%3];
        for (i=0, min=all; i<6; i++) {
            mov = all - bin[0][state[i][0]]
                      - bin[1][state[i][1]]
                      - bin[2][state[i][2]];
            if (min > mov) {
                min = mov;
                ret = i;
            }
        }
        cout << str[ret] << " " << min << endl;
    }
    return 0;
}
