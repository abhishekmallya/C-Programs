#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct LL{
    int data;
    struct LL *next;
    struct LL *prev;
};

typedef struct LL node;
node *head = NULL;
node *getnode(){
    node *nn;
    nn = (node *)malloc(sizeof(node));
    scanf("%d",&nn->data);
    nn->next = NULL;
    return nn;
}

void create()
{
    node *temp,*p;
    temp = getnode();
    if(head==NULL)
        head = temp;
    else{
        p = head;
        while(p->next!=NULL){
            p = p->next;            
        }
        p -> next = temp;
    }
}

void reverse(){
    node *prev, *current, *nextnode;
    if(head==NULL)
        printf("Nothing to reverse\n");
    else{    
            prev = NULL;
            current = nextnode = head;
            while(nextnode!=NULL){
                nextnode = nextnode->next;
                current->next = prev;
                prev = current;
                current = nextnode;
            }            
            head = prev;
        }
}

void deletenodeByData(){
    node *prev, *current, *nextnode;
    int del;
    if(head==NULL)
        printf("Nothing to delete\n");
    else{
        printf("Enter the data you want to delete\n");
        scanf("%d",&del);
        if(del == head->data)
        {
            node *temp;
            temp = head;
            head = head->next;
            free(temp);
        }
        else{
        prev = NULL;
        current = head;
        nextnode = current->next;
        while(current->data!=del){
            prev = current;
            current = current->next; 
            nextnode =current->next;
        }
        current->next = NULL;
        prev->next = nextnode;            
            }
    }
}



void deletenodeByPos(){
    node *currpos, *nextpos;
    if(head==NULL){
        printf("Nothing to delete");
    }
    else{
    int pos,i=1;
    
    printf("Enter the position to be deleted\n");
    scanf("%d",&pos);
    if(pos==1)
        {
            node *temp;
            temp = head;
            head = head->next;
            free(temp);
        }
        else{
        currpos = head;
        while(i<pos-1){
        currpos = currpos->next;
        i++;
        }
        nextpos = currpos->next;
        currpos->next = nextpos->next;
        free(nextpos);
            }
    }
}



void display(){
    node *p;
    int count=0;
    if(head==NULL)
        printf("The LL is empty\n");
    else{
        p = head;
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p = p->next;
            count++;
        }
        printf("\nThe total number of nodes in the LL is %d\n",count);
    }
}

void insertByPos(int pos){
    node *temp,*q,*p, *element;
    element = getnode();   
    if(head==NULL){
        head = element;
    }
    else{
        if(pos == 1){
            element -> next = head;
            head = element;
        }
        else{
        temp = head;
        int count=0;
        while(count!=pos-2){
            temp = temp->next;
            count++;
        }
        q = temp -> next;
        temp -> next = element;
        element -> next = q;
        }
    }
}

void main(){
    int option,n,pos;
    do{
    printf("\n--------------------LL-------------------\n");
    printf("1.Create nodes\n2.Reverse the LL\n3.Delete a node by data\n4.Delete node by position\n5.Insert Node to a position\n6.Exit\n");
    scanf("%d",&option);
    switch(option){
        case 1: printf("Enter the number of elements to be added\n");
                scanf("%d",&n);
                for(int i=0;i<n;i++)
                    create();
                display();
                break;
        case 2: reverse();
                display();
                break;
        case 3: deletenodeByData();
                display();
                break;
        case 4: deletenodeByPos();
                display();
                break;
        case 5: printf("Enter the position where the element needs to be added\n");
                scanf("%d",&pos);
                if(pos>0 && pos<=n)
                    insertByPos(pos);
                display();
                break;
        case 6: exit(0);
        default : printf("Enter valid operation\n");
        }
    }while(option>=1 && option<=10);
}