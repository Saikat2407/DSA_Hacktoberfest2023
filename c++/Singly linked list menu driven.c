//SIngly Linked List Menu Driven PRogram
#include<stdio.h>
#include<stdlib.h>
struct individualnode 
{
    int value;
    struct individualnode* nextnode;
};
void add_after_given_element(struct individualnode** top,int element, int givenelement)
{
    struct individualnode*temporary=(struct individualnode*)malloc(1*sizeof(struct individualnode));
    if(temporary==NULL)
    {
        printf("Memory allocation failed");//To Check if the memory was sucessfully allocated
        return;
    }
    temporary->value=element;
    if((*top)==NULL)
    {
        temporary->nextnode=*top;//there is no list 
        *top=temporary;
        return;
    }
    struct individualnode*current=*top;//current  is used to traverse through the list
    while(current!=NULL)
    {
        if(current->value==givenelement)
        {
            temporary->nextnode=current->nextnode;
            current->nextnode=temporary;//When the Element is found in the list
            return;
        }
        current=current->nextnode;
    }
    //If element not found then we'll insert at the end
    temporary->nextnode = current->nextnode;
    current->nextnode  = temporary ;
}
void deletion_at_location(struct individualnode**top, struct individualnode* givenlocation )
{
    if((*top)==NULL||givenlocation==NULL);
    {
        printf("list does not exist or input is not right ");//if there is no list || the location inputed is invalid
        return;
    }
    struct individualnode*temporary=*top;
    if((*top)==givenlocation)//if the location is same as the top 
    {
        *top=(*top)->nextnode;
        free(temporary);//free the memory location
        return;
    }
    while((temporary->nextnode != NULL && (temporary->nextnode)!=givenlocation ))//temporary is used to traverse through the list
    {
        temporary=temporary->nextnode;
    }
    if((temporary->nextnode)==NULL)
    {
        return;
    }
    temporary->nextnode=givenlocation->nextnode;
    free(givenlocation);
}
void traverse_start(struct individualnode** top)
{
    if((*top)==NULL)
    {
        printf("\nlist does not exist\n");//there is no list
        return;
    }
    struct individualnode *current=*top;//current  is used to traverse through the list
    while(current)
    {
        printf("%d,", current->value);
        current=current->nextnode;
    }
}
void add_at_right(struct individualnode** top,int element)
{
    struct individualnode*Tenporar=(struct individualnode*)malloc(1*sizeof(struct individualnode));
    if(Tenporar==NULL)
    {
        printf("Memory allocation failed");//To Check if the memory was sucessfully allocated
        return;
    }
    Tenporar->value=element;//set the value of temporary to the given value
    if((*top)==NULL)
    {
        Tenporar->nextnode=*top;//there is no list 
        *top=Tenporar;
        return;
    }
    struct individualnode *current = *top;//current is used to traverse through the list 
    while(current->nextnode)
    current=current->nextnode;
    Tenporar->nextnode=current->nextnode;
    current->nextnode=Tenporar;
    return;
}
void add_before_given_element(struct individualnode** top,int element,int givenelement)
{
    struct individualnode*Temporary=(struct individualnode*)malloc(1*sizeof(struct individualnode));
    if(Temporary==NULL)
    {
        printf("Memory allocation failed");//To Check if the memory was sucessfully allocated
        return;
    }
    Temporary->value=element;
    if((*top)==NULL)
    {
        Temporary->nextnode=*top;//there is no list 
        *top=Temporary; 
        return;
    }
    if((*top)->value==givenelement)
    {
        Temporary->nextnode=*top;//when the element is found at the top
        *top=Temporary;
        return;
    }
    struct individualnode*current=*top;//current  is used to traverse through the list 
    while(current->nextnode)
    {
        if(current->nextnode->value == givenelement)
        {
            Temporary->nextnode=current->nextnode;//When the Element is found in the list
            current->nextnode=Temporary;
            return;
        }
        current=current->nextnode;
    }
    Temporary->nextnode=current->nextnode;//If element not found then we'll insert at the end
    current->nextnode=Temporary;
}
void add_at_left(struct individualnode** top,int element)
{
    struct individualnode*Tenporary=(struct individualnode*)malloc(1*sizeof(struct individualnode)); 
    if(Tenporary==NULL)
    {
        printf("Memory allocation failed");//To Check if the memory was sucessfully allocated
        return;
    }
    Tenporary->value=element;//set the value of temporary to the given value
    Tenporary->nextnode=*top; 
    *top=Tenporary;
    return;
}

void deletion_element(struct individualnode** top,int givenelement)
{
   if((*top)==NULL)
   {
        printf("\nThere is no list");//there is no list 
        return;
   }
   struct individualnode*temporary=NULL,*current=*top;
   if((*top)->value==givenelement)//when element is found at top
   {
    *top=temporary;
    free(current);//free the memory location 
    return;
   }
   while(current->nextnode)//current  is used to traverse through the list
   {
    if(current->nextnode->value==givenelement)
    {
        temporary=current->nextnode;
        current->nextnode=temporary->nextnode;//element is found in the list
        free(temporary);
        return;
    }
    current=current->nextnode;
   }
   printf("the given element is not present in the list \n");
}  

void deletion_at_top(struct individualnode** top)
{
    
    if(!(*top))
    {
        printf("\nlist does not exist\n");//there is no list
        return;
    }
    struct individualnode*temporary=*top;
    *top=(*top)->nextnode;//updation of the top pointer
    free(temporary);
    // to free the memory location
}
void deletion_at_end(struct individualnode** top)
{
    
    if((*top)==NULL)
    {
        printf("\nlist does not exist\n");//there is no list
        return;
    }
    struct individualnode*Temporary=NULL;
    if(!((*top)->nextnode))
    {
        Temporary=*top;//when the first node is the last node
        *top=NULL;
        free(Temporary);
        return;
    }
    struct individualnode*current=*top;
    while(current->nextnode->nextnode)//current  is used to traverse through the list
    {
        current=current->nextnode;
    }
    Temporary=current->nextnode;//update the value of temporary
    current->nextnode = NULL;//Update the value at end to null
    free(Temporary);//to free the memory location
}

void traverse_end(struct individualnode** top)
{
    if((*top)==NULL)
    {
        printf("\nlist does not exist\n");//there is no list
        return;
    }
   //use of recurssion
    traverse_end(&((*top)->nextnode));
    printf("%d,", (*top)->value);
}
int main()
{
    struct individualnode *top=NULL;
    char charac;
    int cases,element,givenelement;
    struct individualnode* add=NULL;
    do//use of do while loop to run the loop one extra time atleast
    {
       printf("input your choice:\n1.Add at left\n2.Add at end\n3.Add before a given value\n4.Add after a given value\n5.Remove a node by value\n6.Remove a node by address\n7.remove first node\n8.Remove last node\n9.Traverse from left\n10.Traverse from right: \n");
       scanf("%d",&cases);
       switch (cases)
       {
            case 1:
            {
                printf("\ninput the element to Add at left: ");
                scanf("%d",&element);
                add_at_left(&top,element);
                break;
            }
            case 2:
            {
                printf("\ninput the element to Add at right: ");
                scanf("%d",&element);
                add_at_right(&top,element);
                break;
            }
            case 3:
            {
                printf("\ninput the element to Add : ");
                scanf("%d",&element );
                printf("\nTO be inserted before which element: ");
                scanf("%d",&givenelement);
                add_before_given_element(&top,element,givenelement);
                break;
            }
            case 4:
            {
               printf("\ninput the element to Add : ");
               scanf("%d", &element);             
               printf("\nTO be inserted after which element: ");
               scanf("%d",&givenelement);
               add_after_given_element(&top,element,givenelement);
               break;
            }
            case 5:
            {
                printf("\nInput Value to be removed from list :");
                scanf("%d",&givenelement);
                deletion_element(&top,givenelement);
                break;
            }
            case 6:
            {
                printf("\ninput the address to be removed from list: ");
                scanf("%p",&add);
                deletion_at_location(&top,add);
                break;
            }
            case 7 :
            {
                deletion_at_top(&top);
                break;
            }
            case 8:
            {
                deletion_at_end(&top);
                break;
            }
            case 9:
            {
                traverse_start(&top);
                break;
            }
            case 10:
            {
                traverse_end(&top);
                break;
            }
            default:
            {
                printf("\nInput VAlid values\n");
            }
        }
        printf("\nto continue: Y-yes or to not continue  N-no: ");
        scanf(" %c",&charac);
    }while(charac=='y'||charac=='Y');
    while (top) 
    {
        struct individualnode* Temporary = top;
        top = top->nextnode;
        free(Temporary);
    }
    return 0;
}