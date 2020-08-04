#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* insert(struct node* head, int ele, int pos)
{
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = ele;
    newnode->next = NULL;

    if(head==NULL)
        return newnode;
    
    else if(pos==1)
    {
        newnode->next = head;
        return newnode;
    }

    struct node* temp = head;
    int c=1;
    while(c<pos-1 && temp->next)
    {
        c++;
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

struct node* delete_node(struct node* head, int pos)
{
    int num=1;
    struct node* temp=head;
    
    if(pos<1)
    {
        printf("Enter valid pos\n");
        return head;
    }
        
    else if(pos==1)
    {
        head = head->next;
        temp->next = NULL;
        free(temp);
        return head;
    }
    
    while(num<pos-1 && temp->next)
    {
        temp=temp->next;
        num+=1;
    }
    
        
    if(num<pos-1)
    {
        printf("Enter valid pos\n");
        return head;
    }
    
    struct node* temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = NULL;
    free(temp2);
        
    return head;
    
}


void display_ll(struct node* head)
{
    while(head->next)
    {
        printf("%d->",head->data);
        head= head->next;
    }
    printf("%d",head->data);
}


int main()
{
    struct node* head = NULL;
    int ch,ele,pos;
    while(1)
    {
        printf("Enter option : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter number : ");
                scanf("%d",&ele);
                printf("Enter position : ");
                scanf("%d",&pos);
                head = insert(head,ele,pos);
                break;
            case 2:
                printf("Enter position : ");
                scanf("%d",&pos);
                head = delete_node(head,pos);
                break;
            case 3:
                display_ll(head);
                break;
            default:
                exit(0);
        }
    }

    return 0;
}


////
//
//cin - > scanf
//cout - > printf
//new - > malloc()
//delete - > free
//class - > struct
