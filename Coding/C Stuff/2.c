//
//  2.c
//  Lab Programs
//
//  Created by Surya Dheeshjith on 11/11/18.
//  Copyright © 2018 Surya Dheeshjith. All rights reserved.
//




DO NOT COMPILE HERE
COPY PASTE AND USE INTERNET COMPILER......................




#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 40


struct stack{
    int top;
    char arr[MAX];
};


typedef struct stack stack;


char pop(stack *s)
{
    if(s->top==-1)
    {
        printf("Stack Underflow");
        exit(0);
    }
    char ele;
    ele = s->arr[s->top--];
    return ele;
}
void push(stack *s,char ele)
{
    if(s->top==MAX-1)
    {
        printf("Stack Overflow");
        exit(0);
    }
    
    s->arr[++s->top]=ele;
}

int precedence(char ch)
{
    switch(ch)
    {
        case '^':
        case '$': return 4;
        case '*':
        case '/': return 3;
        case '+':
        case '-':return 2;
        default :return 1;
    }
}
void infixtopostfix(stack *s,char infix[], char postfix[])
{
    int i,k=0;
    char ele;
    for(i=0;infix[i];i++)
    {
        if(infix[i]=='(')
        {
            push(s,infix[i]);
        }
        else if(infix[i]==')')
        {
            
            
            while(s->arr[s->top]!='(')
            {
                ele=pop(s);
                postfix[k++]=ele;
            }
            
            ele = pop(s);
        }
        else if(isalnum(infix[i]))
        {
            postfix[k++]=infix[i];
        }
        else
        {
            if(s->arr[s->top]=='('||s->top==-1)
                push(s,infix[i]);
            
            else
            {
                while(precedence(s->arr[s->top])>=precedence(infix[i]))
                {
                    ele = pop(s);
                    postfix[k++]=ele;
                }
                push(s,infix[i]);
            }
            
        }
    }
    while(s->top!=-1)
    {
        ele = pop(s);
        postfix[k++]=ele;
    }
    printf("The Postfix expression is -\n");
    for(i=0;i<k;i++)
        printf("%c ",postfix[i]);
    printf("\n");
}




int main()
{
    stack s;
    s.top=-1;
    char arr1[MAX],arr2[MAX];
    while(1)
    {printf("Enter the infix expression: ");
        scanf("%s",arr1);
        infixtopostfix(&s,arr1,arr2);
    }
}
*/
