#include<stdio.h>

int main()
{
    char type[10];
    printf("Enter data type: ");
    scanf("%s",type);
    if(type[0] == 'I'){
        printf("%d",sizeof(int));
    }
    else if(type[0] == 'L'){
        printf("%d",sizeof(long));
    }
    else if(type[0] == 'F'){
        printf("%d",sizeof(float));
    }
    else if(type[0] == 'C'){
        printf("%d",sizeof(char));
    }
    else if(type[0] == 'D'){
        printf("%d",sizeof(double));
    }
    else{
        printf("Invalid choice");
    }
    return 0;
}