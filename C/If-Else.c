#include<stdio.h>

int main()
{
    int a,b;
    printf("Enter the values of a and b: ");
    scanf("%d %d",&a,&b);
    if(a>b)
    {
        printf("greater");
    }
    else if(a<b)
    {
        printf("smaller");
    }
    else{
        printf("equal");
    }
    return 0;
}