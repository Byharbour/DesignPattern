/*A-1-6-3 动态申请的内存空间用完后及时释放*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    int *x = NULL;
    char *y = "asdfjasefla";
    const char* Name = "Hello Kitty";
    unsigned short len = strlen(Name);
    x = (int *)malloc(sizeof(int)*1);
    if(NULL != x){
    	*x = 2;
    	printf("%d\n",*x);								//提示
    	free(x);
    	x = NULL;
    }

    y = (char *)malloc(sizeof(char)*(len+1));
    if(NULL != y){
		memset(y,0,len+1);
    	strncpy(y,Name,len);
   		printf("%s\n",y);							//提示
    	free(y);
    	y = NULL;
		}
    return (0);
}
