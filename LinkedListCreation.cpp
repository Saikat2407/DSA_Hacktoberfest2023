#include<iostream>
using namespace std;

struct node{
  int data;
  struct node *next;
}
struct node *head = NULL;
struct node *p,*temp;

void creation(int x){
    p = (struct node*)malloc(sizeof(struct node));
    p->data = x;
    p->next = NULL;
    if(head == NULL){
        head = p;
    }
    else{
        temp = head;
        while(temp->next != NULL){
              temp = temp->next;
        }
        temp->next = p;
    }

void display(){
  temp = head;
  while(temp->next != NULL){
          cout << temp->data << " ";
  }
        cout << temp->data << endl;
}
