#include<stdio.h>
int main()
{int a,fact,i;
    {printf("Enter the Number =");
    scanf("%d",&a);
    for (i=a; i>=1; i--)
        fact=fact*i;
        printf("Factorial = %d\n", fact);
    }
}