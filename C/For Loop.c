#include<stdio.h>

int main()
{
    int a=1,b=1,c,i,n;
    printf("Which term is to be printed? ");
    scanf("%d",&n);
    if(n==1){
        printf("1");
    }
    else if(n==2){
        printf("1");
    }
    else{
        for(i=2;i<n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        printf("%d",c);
    }
    return 0;
}