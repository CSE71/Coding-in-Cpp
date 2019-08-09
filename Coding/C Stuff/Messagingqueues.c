


//
//  3.c
//  Lab Programs
//
//  Created by Surya Dheeshjith on 11/11/18.
//  Copyright © 2018 Surya Dheeshjith. All rights reserved.
//

#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 10


struct queue{
    
    int f;
    int r;
    char qt[MAX][20];
    
};

typedef struct queue queue;
void sendm(queue *q)
{

    if(q->f==(q->r+1)%MAX)
    {
        printf("Queue Full");
    
    }
    else{
    char arr[20];
    printf("Enter the message ");
    gets(arr);
    if(q->f==-1)
    {
        q->f=0;
    }
   
    q->r=(q->r+1)%MAX;
    strcpy(q->qt[q->r],arr);
    
    }
}

void receivem(queue *q)
{
    
    if(q->f==-1)
    {
        printf("Queue empty");
    
    }
    else{
    char *qtp;
        qtp =q->qt[q->f];
    printf("Received message is %s",qtp);
    if(q->r==q->f)
    {
        q->r=-1;
        q->f=-1;
    }
    else{
        q->f=(q->f+1)%MAX;
    }
    }
}

void displayquq(queue *q)
{
    int i;
    if(q->f==-1)
    {
        printf("Queue empty ");
        return;
    }
    for(i=q->f;i!=q->r;i=(i+1)%MAX)
        printf("%s\n",q->qt[i]);
    printf("%s\n",q->qt[q->r]);
}

int main()
{
    queue q;
    q.f=-1;
    q.r=-1;
    int ch;
    printf("Press 1. Send message 2. Receive Message 3. Display 4. Exit    ");
    while(1)
    {
        scanf("%d",&ch);getchar();
        switch(ch)
        {
            case 1:
                sendm(&q);
                break;
            case 2: receivem(&q);
                break;
            case 3: displayquq(&q);
                break;
            case 4: exit(0);
            
        }
    }
}

