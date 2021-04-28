#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct DLL{
    int data;
    struct DLL *prev;
    struct DLL *next;
};

typedef struct DLL node;
node *head =NULL;
node *getnode(){
    node *nn;
    nn = (node *)malloc(sizeof(node));
    nn->next = nn->prev = NULL;
    scanf("%d",&nn->data);
    return nn;
}

void create()
{
    node *temp, *p;
    p = head;
    temp = getnode();
    if(head==NULL)
        {
            head = temp;
        }
    else{
        while(p->next!=NULL)
            p = p->next;
        p->next = temp;
        temp->prev = p;
    }
}

void display(){
    node *p;
    p = head;
    if(head==NULL)
        printf("The LL is empty\n");
    else{
        printf("Elements currently in the linked list are : ");
        while(p!=NULL){
            printf("%d ",p->data);
            p = p->next;
        }
    }
}


void reverseprint(){
    node *p, *q;
    p = head;
    q = head;
    while(p->next!=NULL)
        p = p->next;
    while(p->prev!=q){
        printf("%d",p->data);
        p = p->prev;
    }
}

void main(){
    int option,n;
    do{
        printf("\n---------------DLL-------------------\n");
        printf("1.Create\n2.Insert Node Front\n3.Insert Node Rear\n4.Delete Node Front\n5.Delete Node Rear\n6.Exit\n");
        scanf("%d",&option);
        switch(option){
            case 1: printf("Enter the number of elements\n");
                    scanf("%d",&n);
                    for(int i=0;i<n;i++)
                        create();
                    display();
                    break;
            case 7: reverseprint();
                    break;
            case 6: exit(0);
            default: printf("Enter valid operation\n");
        }
    }while(option>=1 && option<=10);
}