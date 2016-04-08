//动态态分配的指针变量第一次使用前必须进行是否为NULL的判别。
#include <malloc.h>
int main(void) 
{  
    int *x = (int *)malloc(sizeof(int));
    *x = 1;                      //违背1
    return (0);
}
