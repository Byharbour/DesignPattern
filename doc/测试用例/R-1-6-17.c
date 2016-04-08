//被free的指针必须指向最初malloc、calloc分配的地址。
#include <stdlib.h>
#include <malloc.h>
int fun(void);
int main(void)
{
    int i;
    i = fun();
    return (0);
}
int fun(void)
{
    int *p = (int *)malloc(3*sizeof(int));
    if(NULL == p)
    {
        return (-1);
    }
    else
    {
        *p = 1;
        p++;
        *p = 2;
        free(p);                      //违背1
        p = NULL;
    }
    return (0);
}
