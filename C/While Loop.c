#include<stdio.h>

int main()
{
    int n,d,so=0,se=0;
    printf("Enter number: ");
    scanf("%d",&n);
    while(n!=0){
        d=n%10;
        n=n/10;
        if(d%2==0){
            se=se+d;
        }
        else{
            so=so+d;
        }
    }
    printf("%d %d",se,so);
    return 0;
}