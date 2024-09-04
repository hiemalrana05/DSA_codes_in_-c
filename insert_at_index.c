#include<stdio.h>
#include<stdlib.h>
//created a node here with data and next pointer
struct node{
    int data;
    struct node* next;
}*head,*newnode;//head node for head of linked list and newnode for function
void insert_index(struct node* head,int index){//arguements are head node and index to be inserted the node in 
    newnode=NULL;//initiated it with null
    newnode=(struct node*)malloc(sizeof(struct node));//created a node herer
    newnode->data=88;
    int n=0;//initiated a variable with 0
    while(n!=index-1){//loop wil go till the desired index-1th position(array indexing concept)
        head=head->next;//traversing head till th desired position
        n++;//incrementind the value till the position
    }
    newnode->next=head->next;//now storing the value of newnode next in head node next after the loop
    head->next=newnode;//head's next node will be the newnode
    
}
void print(struct node* head){//printing function
    while(head!=NULL){
        printf("%d\n",head->data);
        head=head->next;
    }
}
int main(){
    head=NULL;//initiated it with NULL value here
    head=(struct node*)malloc(sizeof(struct node));//created head node
    struct node* second_node=(struct node*)malloc(sizeof(struct node));//created some more nodes
    struct node* third_node=(struct node*)malloc(sizeof(struct node));
    struct node* fourth_node=(struct node*)malloc(sizeof(struct node));

    head->data=55;
    head->next=second_node;

    second_node->data=22;
    second_node->next=third_node;

    third_node->data=33;
    third_node->next=fourth_node;

    fourth_node->data=11;
    fourth_node->next=NULL;//end of the list

    insert_index(head,3);//now suppose we want to insert at 3rd position therefore the loop will go 0,1,2 positions
    print(head);//printing the required list now
    return 0;


}
