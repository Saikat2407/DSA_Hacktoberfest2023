#include<stdio.h>

int main()
{
    int i,j,n;
    printf("Enter no. of rows: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("%d",j);
        }
        for(j=n;j>i;j--){
            printf(" ");
        }
        for(j=n;j>i;j--){
            printf(" ");
        }
        for(j=i;j>=1;j--){
            printf("%d",j);
        }
        printf("\n");
    }
    return 0;
}