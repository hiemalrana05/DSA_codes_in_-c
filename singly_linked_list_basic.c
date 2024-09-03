#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{/*creation of linked list with a data input and structure pointer 
pointing to the next node which is also having data and pointer*/
    int data;
    struct node* next;
};
void print_list(struct node* ptr){//passing the head node as arguement in the function and running the loop till next pointer encounters null value
    while(ptr!=NULL){
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    /*creating structure pointer nodes as per the user preference like in this creating 3 nodes
    head and second node and tail node where it'll be terminated*/
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* second_node=(struct node*)malloc(sizeof(struct node));
    struct node* tail_node=(struct node*)malloc(sizeof(struct node));

    head->data=22;//assigning values and using next pointer to next structure pointer
    head->next=second_node;

    second_node->data=45;
    second_node->next=tail_node;

    tail_node->data=78;
    tail_node->next=NULL;//creating only 3 nodes and after this it'll be pointing to null value

    print_list(head);//printing list
    return 0;
    
}
