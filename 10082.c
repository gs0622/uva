#include <stdio.h>

const char map[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main(void)
{
    char in[1024], remap[256];
    int i;
#if 0
    freopen("10082.in", "r", stdin);
#endif
    for (i=1;map[i];i++) remap[(int)map[i]]=map[i-1];
    while (gets(in)) {
        for (i=0;in[i];i++) printf("%c", in[i]==' '?' ':remap[(int)in[i]]);
        printf("\n");
    }
    return 0;
}

