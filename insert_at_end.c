#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node* next;
}*head,*newnode;
//so we created a structure for data and structure pointer to next node
//and a head node and a newnode for reference below

void insert_end(struct node* head){//passing head as arguement to traverse the list till null
    newnode=NULL;//created node and initiated it with 0 
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=72;
    while(head->next!=NULL){//running next pointer till it encounters null value
        head=head->next;
    }
    head->next=newnode;//after encountering null value we will add newnode as the previous list is over
    newnode->next=NULL;//after newnode it'll be again pointing to null
}
void print(struct node* head){
    while(head!=NULL){
        printf("%d\n",head->data);//printing till the value becomes nulll (traversing) 
        head=head->next;
    }
}
int main(){
    head=NULL;//we initiated it with null because starting value is 0 
    head=(struct node*)malloc(sizeof(struct node));//we created more pointers for the list
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    struct node* new_1;
    head->data=22;//we allocated the data and next pointer pointing to next node
    head->next=second;
    
    second->data=44;
    second->next=third;

    third->data=66;
    third->next=NULL;//after this we stop therefore only 3 nodes

    insert_end(head);//we will pass head for the function arguement
    print(head);//printing the list
    
    return 0;
}
