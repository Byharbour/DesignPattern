/*A-1-1-6 建议用宏或const定义常数*/
#include <stdio.h>
#include <math.h>
#define PI 3.1415926				//遵守

double const pi = 3.1415926; 		//遵守
int main(void)
{
    float r,d,s,v;
    double rr;
    r = 2.0;
    s = r*r*3.1415926;			//提示
    v = r*r*r*PI/3.0;
    d = r*pi;

    rr=PI*PI;

    printf("%f\n,%f\n,%f",d,s,v);

    return (0);
}
