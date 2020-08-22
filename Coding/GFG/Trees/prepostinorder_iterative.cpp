#include<bits/stdc++.h>
using namespace std;


typedef struct node{

    int data;
    node* left;
    node* right;

    node(int x){
        data=x;
        left = NULL;
        right = NULL;
    }

}node;

void preorder(node* head)
{
    stack<node*> stk;
    cout<<"Preorder - \n";
    node* cur = head;
    while(cur!=NULL || !stk.empty())
    {
        if(cur!=NULL){
        cout<<cur->data<<" ";
        stk.push(cur);
        cur = cur->left;
        }

        else{
            cur = stk.top();
            stk.pop();
            cur=cur->right;
        }
    }
}


void inorder(node* head)
{
    stack<node*> stk;
    node* cur = head;
    cout<<"Inorder traversal - \n";
    while(cur!=NULL || !stk.empty())
    {
        if(cur!=NULL)
        {
            stk.push(cur);
            cur = cur->left;
        }

        else{
            cur = stk.top();
            stk.pop();
            cout<<cur->data<<" ";
            cur=cur->right;
        }
    }

}

//Opposite of preorder
void postorder(node* head)
{
    stack<node*> stk;
    node* cur = head;
    cout<<"Postorder traversal - \n";
    vector<int> ans;
    while(cur!=NULL || !stk.empty())
    {
        if(cur!=NULL)
        {
            stk.push(cur);
            ans.push_back(cur->data); //Opposite of preorder
            cur=cur->right; //Opposite of preorder

        }
        else{
            cur = stk.top();
            stk.pop();
            cur = cur->left; //Opposite of preorder



        }

    }
    int n = int(ans.size());
    for(int i=n-1;i>=0;i--)
    {
        cout<<ans[i]<<" ";
    }

}

int main()
{
    node* head = new node(1);
    head->left = new node(2);
    head->right = new node(3);
    head->left->left = new node(4);
    head->left->right = new node(5);

    preorder(head);
    cout<<endl;
    inorder(head);
    cout<<endl;
    postorder(head);



}
