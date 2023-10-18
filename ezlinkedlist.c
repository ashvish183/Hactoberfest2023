#include <stdio.h>
#include<stdlib.h>//DONT FORGET!!!
struct Node{
    int data;
    struct Node* next;//pointer of type struct node
}*head;// its a pointer of the typre structnode
void createList(){//a linked list consists of head,data and next
    
    int n;
    struct Node *temp;//this is LoCaL
    printf("Enter the no. of nodees");
    scanf("%d",&n);
    head=(struct Node*)(malloc(sizeof(struct Node)));
    scanf("%d",(&head->data));//& is NECESSARY while ccepting values
    head->next=NULL;
    temp=head;

    for(int i=2;i<=n;i++){
        struct Node *new=(struct Node*)(malloc(sizeof(struct Node)));//DONT FORGET!!!
        temp->next=new;
        scanf("%d",&new->data);
        new->next=NULL;
        temp=temp->next;
    }
}

void display(){
    if (head==NULL)
        printf("linked list is empty!!");
    else
    {
        struct Node *temp;
        temp=head;
        while (temp!=NULL){
            printf("displaying: %d\n",temp->data);
            temp=temp->next;
        } 
    }
}

void insertLast(){
    struct Node *new=(struct Node*)(malloc(sizeof(struct Node)));
    struct Node *temp;
    temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
        } 
    temp->next=new;
    printf("enter data for new node in last:");
    scanf("%d",&new->data);//& is VVIP
    new->next=NULL;

}

void insertFront(){
    struct Node *new=(struct Node*)(malloc(sizeof(struct Node)));

    printf("enter data for new node in begining:");
    scanf("%d",&new->data);//& is VVIP
    new->next=head;
    head=new;
}

int main(){
    head=NULL;
    createList();
    insertLast();
    insertFront();
    display();
}