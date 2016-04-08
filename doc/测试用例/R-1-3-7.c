//动态分配的指针变量定义时如未被分配空间必须初始化为NULL。
#include <stdlib.h>
#include <malloc.h>
int main(void) 
{  
    int *x;                 //违背1
    //...
    x = (int *)malloc(sizeof(int));
    if(NULL != x)                
    {
        *x = 1;                      
    }
    else
    {
        return (-1);
    }
    return (0);
}
