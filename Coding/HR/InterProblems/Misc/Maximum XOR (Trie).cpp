//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

//Find Max XOR from two arrays

// Note : Max XOR - Find the opposite bits to get max value
#include <bits/stdc++.h>

using namespace std;


// Complete the maxXor function below.
typedef struct node{
    struct node* arr[2];
}node;

void insert(node* root,int ele)
{
    int l;
    node* temp =root;
    if(temp==NULL)
        return;
    for(int i=31;i>=0;i--)
    {
        l = ele>>i & 1;
        if(!temp->arr[l])
        {
            temp->arr[l] = new node;
        }
        temp = temp->arr[l];
        
    }
    
}
long find(node* root,int ele)
{
    node* temp = root;
    if(temp==NULL)
        return -1;
    int l;
    long ret=0;
    for(int i=31;i>=0;i--)
    {
        l = ele>>i & 1;
        l^=1;
        
        if(!temp->arr[l])
        {
            l^=1;
        }
        
        ret = ret<<1 | l;
        temp = temp->arr[l];
    }
    return ret;
}
int main()
{
    int n,i,x;
    cin>>n;
    
    int a[n];
    for(i=0;i<n;++i) {
        cin>>a[i];
    }
    
    node *trie = new node;
    for(i=0;i<n;++i) {
        // max 32 bits
        insert(trie,a[i]);
    }
    
    int t;
    cin>>t;
    while(t--) {
        cin>>x;
        long q;
        q= find(trie,x);
        cout<<(q^x)<<endl;
    }
    
    return 0;
}
