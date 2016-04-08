//禁止使用已被释放了的内存空间。
#include <stdlib.h>
#include <malloc.h>
int main(void) 
{  
    int *x = (int *)malloc(sizeof(int));
    int y;
    int *p;
    p=NULL;
    if(NULL != x)
    {
        *x = 1;  
        //……
        free(x);
        x = NULL;
    }
    else
    {
        return (-1);
    }
    y = (*x);                     //违背1
    return (0);
}
