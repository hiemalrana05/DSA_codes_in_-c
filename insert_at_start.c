#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
    int data;
    struct node* next;
}*head,*newnode;
//so we created a structure for data and structure pointer to next node
//and a head node and a newnode for reference below
void insert_at_start(struct node* newnode){
    newnode=NULL;//initiated it with null
    newnode=(struct node*)malloc(sizeof(struct node));//created the node
    newnode->data=72;//allocate the data
    newnode->next=head;//we want to insert at start so first position will be of newnode
    head=newnode;//new value of head is newnode therefore storing 
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
    struct node* fourth;
    head->data=22;//we allocated the data and next pointer pointing to next node
    head->next=second;
    
    second->data=44;
    second->next=third;

    third->data=66;
    third->next=NULL;//after this we stop therefore only 3 nodes

    insert_at_start(fourth);//we will insrt this node at first
    print(head);//printing the list
    
    return 0;
}
