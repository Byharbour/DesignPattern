//数组禁止越界使用。
//注:对经过复杂运算所得出的数组下标，在使用时无法断言一定不会越界的情况下，应对数组下标进行范围判断。
void comp(int a[], int n) //n为数组长度
{
    int i;
    for (i = 0; i <= n; i++) //违背1
    { 
        a[i] = 0; 
    }
}
int main(void)
{
    int array[100];
    comp(array, 100);
    array[100] = 1;          //违背2
    return (0);
}
