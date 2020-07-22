#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

Node* insert(Node* head, int ele, int pos)
{
     Node* newnode = new Node();
    newnode->data = ele;
    newnode->next = NULL;

    if(head==NULL)
        return newnode;
    
    else if(pos==1)
    {
        newnode->next = head;
        return newnode;
    }

    Node* temp = head;
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

void display_ll(Node* head)
{
    while(head->next)
    {
        cout<<head->data<<"->";
        head= head->next;
    }
    cout<<head->data;
}

int main()
{
    Node* head = NULL;
    int ch;
    cout<<"Enter option : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
            int ele,pos;
            cout<<"Enter number : ";
            cin>>ele;
            cout<<"Enter position : ";
            cin>>pos;
            head = insert(head,ele,pos);
            break;
        case 2:
            display_ll(head);
    }

    return 0;
}