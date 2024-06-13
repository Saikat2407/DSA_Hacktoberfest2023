#include<stdio.h>

int main()
{
    int i,j,n;
    printf("Enter no. of rows: ");
    scanf("%d",&n);
    for(i=5;i>=1;i--){
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}