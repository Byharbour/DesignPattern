//逻辑判别表达式中的运算项必须要使用括号。
int main(void) 
{  
    unsigned int i, tbc;
    tbc = 0x80;
    if(tbc&0x80 == 0x80)     //违背1
    {
        i = 1;
    } 
    else
    {
        i = 2;
    }
    return (0);
}
