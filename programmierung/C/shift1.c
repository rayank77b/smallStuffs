#include <stdio.h>
#include <stdlib.h>

// simple dislpay v as binary, by shifting
// !! is doing fun stuff.
// without !!, you get
// 0: 00000000
// 1: 00000001
// 2: 00000020
// 3: 00000021
void shiftme(int v)
{
    int i=0;
    printf("%x: ", v);
    for(i=7;i>=0;i--) 
    {
        printf("%d", !!(v&(1<<i)));        
    }
    printf("\n");
}
int main()
{
    int a;
    for(a=0;a<16;a++)
    {
        shiftme(a);
    }

    return 0;
}
