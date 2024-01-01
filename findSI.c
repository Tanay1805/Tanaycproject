#include<stdio.h>
int main()
{ float a,b,c,d,e;
    {printf("Enter the Principle Amount=");
    scanf("%f",&a);
    printf("Enter the Time Period=");
    scanf("%f",&b);
    c= a * b * 9.5;
    d=c/100;
    printf("Simple Interest=%f\n",d);
    e=a+d;
    printf("Total Amount= %f\n",e);
    return 0;
    }
}