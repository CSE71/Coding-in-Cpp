//
//  main.c
//  Lab Programs
//
//  Created by Surya Dheeshjith on 11/11/18.
//  Copyright © 2018 Surya Dheeshjith. All rights reserved.
//


//1.c

#include <stdio.h>
#include<stdlib.h>
#define SIZE 10

struct stack{
    int top;
    int data[SIZE];
};
int Y;
typedef struct stack stack;

void push(stack *s,int ele)
{
    if(s->top==SIZE-1)
    {
        printf("Stack Overflow");
        return;
    }
    
        
    s->data[++s->top]=ele;
    
}
int pop(stack *s)
{
    if(s->top==-1)
    {
        printf("Stack underflow");
        return -1;
    }
    int ele = s->data[s->top--];
    return ele;
}
void popn(stack *s, int n)
{
    if(s->top+1<n)
    {
        printf("Enter valid n");
        return;
    }
    int i;
    for(i=1;i<=n;i++)
        pop(s);
}
void bottom3(stack *s)
{
    stack s1;
    s1.top=-1;
    
    if(s->top+1<3)
    {
        printf("Not enough elements");
        return;

    }
    int i;
    int l = s->top;
    for(i=l;i>=2;i--)
        push(&s1,pop(s));
    Y = s1.data[s1.top];
    printf("Value of Y is %d",Y);
    while(s1.top!=-1)
    {
        push(s,pop(&s1));
    }
    
    
}
void top3(stack *s)
{
    stack s1;
    s1.top=-1;
    
    if(s->top+1<3)
    {
        printf("Not enough elements");
        return;
        
    }
    push(&s1,pop(s));
    push(&s1,pop(s));
    
    Y = s->data[s->top];
    printf("Value of Y is %d",Y);
    while(s1.top!=-1)
    {
        push(s,pop(&s1));
    }
}


int main()
{
    stack s;
    s.top=-1;
    
    int ch,Y,n;
    int i;
    
    
    printf("Press\n 1. Display bottom third\n 2. Pop n elements\n 3. Display top third\n 4. Push\n 5. Display\n 6. Exit\n");
    while(1)
    {
        printf("Enter choice >>>> ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                bottom3(&s);
                break;
            
            case 2:
                printf("Enter number of elements to pop ");
                scanf("%d",&n);
                popn(&s,n);
                break;
            case 3:
                top3(&s);
                break;
            case 4:
                printf("Enter value to be inserted ");
                scanf("%d",&n);
                push(&s,n);
                break;
            case 5:
                    printf("Elements are - \n");
                for(i=s.top;i>=0;i--)
                    printf("%d \n",s.data[i]);
                break;
            case 6: exit(0);
            default: printf("Enter valid choice");
        }
        printf("\n");
    }
    
}
