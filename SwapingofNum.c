#include <stdio.h>
int main()
{ int a,b,temp;
    printf("Enter the number A=");
    scanf("%d",&a);
    printf("Enter the number B=");
    scanf("%d",&b);

    temp=a;
    a=b;
    b=temp;

    printf("Value of A = %d\n",a);
    printf("Value of B = %d\n",b);
    return 0;
}