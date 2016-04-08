/*A-1-11-1 建议变量在声明的同时进行初始化*/
//定义性声明算不算声明？extern 声明变量时是不可以初始化的
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct node{
	int item;
	float score;
};

struct node head;  					 //提示
int data3;  					 //提示

enum Etype {
	RED = 0,
	WHITE,
	BLUE
} edata;   					 //提示

int main(void)
{
	int data1;  					 //提示
	edata = BLUE;
	data3 = 32;
	data1 = data3;
	head.item = 43;
	head.score = 122.23;
    printf("%d,%d,%d,%d,%f\n",edata,data1,data3,head.item,head.score);
    return (0);
}
