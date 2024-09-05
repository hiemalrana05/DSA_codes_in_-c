#include<stdio.h>
#include<stdlib.h>

struct node{//creating a structure for node
    int data;
    struct node* next;
}*dummy,*head,*temp;//creating head,temp,dummy

void delete_head(){
    struct node* temp = dummy->next;//using dummy pointer as next pointer to point next node
    dummy->next = temp->next;//dummy's next will be equal to temp's next
    free(temp);//free the temp pointer
}

void print(){
    struct node* temp = dummy->next;//printing function
    while (temp!=NULL)
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    
}

int main(){
    dummy=(struct node*)malloc(sizeof(struct node));
    dummy->next=NULL;//using dummy as head here so data will be of head here 

    head=(struct node*)malloc(sizeof(struct node));
    dummy->next=head;

    struct node* second;
    struct node* third;
    struct node* fourth;
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));
    fourth=(struct node*)malloc(sizeof(struct node));

    head->data=88;
    head->next=second;

    second->data=66;
    second->next=third;

    third->data=77;
    third->next=fourth;

    fourth->data=22;
    fourth->next=NULL;

    delete_head();//deleting head function
    print();

    return 0;
}
