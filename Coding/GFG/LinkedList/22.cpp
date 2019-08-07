//
//  22.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 07/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Linked list flattening

#include <bits/stdc++.h>
    struct Node{
        int data;
        struct Node * next;
        struct Node * bottom ;
    };
    using namespace std;
    void printList(Node *Node)
    {
        while (Node != NULL)
        {
            printf("%d ", Node->data);
            Node = Node->bottom;
        }
    }
    Node* flatten (Node* root);
    int main(void) {
        int t;
        cin>>t;
        while(t--){
            int n,m,flag=1,flag1=1;
            struct Node * temp=NULL;
            struct Node * head=NULL;
            struct Node * pre=NULL;
            struct Node * tempB=NULL;
            struct Node * preB=NULL;
            cin>>n;
            int work[n];
            for(int i=0;i<n;i++)
            cin>>work[i];
            for(int i=0;i<n;i++){
                m=work[i];
                --m;
                temp = (struct Node*)malloc(sizeof(struct Node));
                scanf("%d",&temp->data);
                temp->next=NULL;
                temp->bottom=NULL;
                if(flag){
                    head=temp;
                    pre=temp;
                    flag=0;
                    flag1=1;
                }
                else{
                    pre->next=temp;
                    pre=temp;
                    flag1=1;
                }
                for(int j=0;j<m;j++){
                    tempB = (struct Node*)malloc(sizeof(struct Node));
                    scanf("%d",&tempB->data);
                    tempB->next=tempB->bottom=NULL;
                    if(flag1){
                        temp->bottom=tempB;
                        preB=tempB;
                        flag1=0;
                    }
                    else{
                        preB->bottom=tempB;
                        preB=tempB;
                    }
                }
            }
            Node *fun = head;
            Node *fun2=head;
            /*
             while(fun!=NULL)
             {
             cout<<fun->data<<" ";
             fun2 = fun->bottom;
             fun=fun->next;
             while(fun2){
             cout<<fun2->data<<" ";
             fun2=fun2->bottom;
             }
             cout<<endl;
             }*/
            Node* root = flatten(head);
            printList(root);
            cout<<endl;
        }
        return 0;
    }
    

/*This is a function problem.You only need to complete the function given below*/
/* Node structure  used in the program
 struct Node{
 int data;
 struct Node * next;
 struct Node * bottom ;
 }; */
/*  Function which returns the  root of
 the flattened linked list. */
Node *flatten(Node *root)
{
    // Your code here
    int arr[1001],k=0;
    Node* temp1 = root;
    Node* temp2 = temp1;
    while(temp1)
    {
        while(temp2)
        {
            arr[k++] = temp2->data;
            temp2 = temp2->bottom;
        }
        temp1 = temp1->next;
        temp2 = temp1;
    }
    
    sort(arr,arr+k);
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = arr[0];
    head->bottom = NULL;
    Node* ret = head;
    
    for(int i=1;i<k;i++)
    {
        Node* temp = (Node*)malloc(sizeof(Node));
        temp->data = arr[i];
        temp->bottom = NULL;
        head->bottom = temp;
        head = temp;
        //cout<<"- "<<head->data<<endl;
    }
    head->bottom = NULL;
    return ret;
}
