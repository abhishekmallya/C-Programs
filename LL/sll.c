#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct student{
    char name[25],USN[12],branch[10],pno[10];
    int sem;
    struct student * link;
};

typedef struct student node;
node *head =NULL;
node *getnode()
{
    node *nn;
    nn = (node *)malloc(sizeof(node));
    printf("Enter Student Details\n");
    printf("----------------------\n");
    printf("Enter the name of the student\n");
    scanf("%s",nn->name);
    printf("Enter USN\n");
    scanf("%s",nn->USN);
    printf("Enter the branch\n");
    scanf("%s",nn->branch);
    printf("Enter Phone Number\n");
    scanf("%s",nn->pno);    
    printf("Enter Semester\n");
    scanf("%d",&nn->sem);
    nn->link =NULL;
    return nn;
}

void display()
{
    node *p;
    int count = 0;
    if(head==NULL)
        printf("No student details Available\n");
    else{
        p = head;
        printf("Name \t USN \t Branch \t Ph.No \t Sem \n");
        while(p!=NULL)
        {
            count ++;
            printf("%s \t %s \t %s \t %s \t %d \n",p->name,p->USN,p->branch,p->pno,p->sem);
            p = p->link;
        }
        printf("Number of students = %d\n",count);
    }
}

void create()
{
    node *temp;
    temp = getnode();
    if(head==NULL)
        head = temp;
    else{
        temp -> link = head;
        head = temp;
    }
}

void insertfront(){
    create(head);
    display();
}

void insertrear(){
    node *temp, *p;
    p =head;
    temp = getnode();
    if(head==NULL)
        head = temp;
    else{
        while(p->link!=NULL)
            p = p->link;
    }
    p->link = temp;
    display();
}

void deletefront(){
    node *p;
    if(head == NULL)
        printf("No data to delete");
    else{
        p = head;
        p = p->link;    
    }
    free(p);
    display();
}

void deleterear(){
    node *p,*q;
    if(head == NULL)
        printf("Nothing to delete");
    else{
        while((p->link)->link!=NULL)
            {
                p = p->link;
            }
            q = p->link;
            p->link = NULL;
            free(q);
            display();        
        }
}


void main(){
    int ch,n,i;
    do{
        printf("\n---------------------Student Details-------------------\n");
        printf("1.Create\n2.Display\n3.Insert front\n4.Insert rear\n5.delete Front\n6.Delete Rear\n7.Exit the program\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("Enter the number of students");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                        create();
                    break;
            case 2: display();
                    break;
            case 3: insertfront();
                    break;
            case 4: insertrear();
                    break;
            case 5: deletefront();
                    break;
            case 6: deleterear();
                    break;
            case 7: exit(0);
            default : printf("Enter an option betweeen 1 and 7");
            

        }
    }while(ch>=1 && ch<=7);
}

