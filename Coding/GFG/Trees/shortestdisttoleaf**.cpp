#include <iostream>
using namespace std;
typedef struct Node{
  
    char data;
    struct Node* left;
    struct Node* right;
}Node;


Node* newNode(char ch)
{
    Node* newnode  = (Node*)malloc(sizeof(Node));
    newnode->data = ch;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int getmin(int a, int b)
{
    if(a<b)
        return a;
    else
        return b;
}


int distfromroot(Node* root)
{
    if(root==NULL)
        return INT_MAX;
    if(root->left==NULL && root->right==NULL)
        return 0;
    return 1 + getmin(distfromroot(root->left),distfromroot(root->right));
}

int findClosestUtil(Node* root,char ch,int index,Node* ancestors[])
{
    
    if(root==NULL)
        return INT_MAX;
    
    if(root->data==ch)
    {
        int res = distfromroot(root); //Just this would give the closest leaf from required node.
        
        
        for(int i=index-1;i>=0;i--)
        {
            res= getmin(res,index - i +distfromroot(ancestors[i])); // Find the closest leaf from the ancestors of required node.
            
            
        }
        return res;
    }
//    for(int i=0;i<index;i++)
//        cout<<ancestors[i]->data<<endl;
    ancestors[index] = root;
    return getmin(findClosestUtil(root->left,ch,index+1,ancestors),findClosestUtil(root->right,ch,index+1,ancestors));

}

int findClosest(Node* root,char ch)
{
    Node* ancestors[100];
    return findClosestUtil(root,ch,0,ancestors);
}

/* Driver program to test above functions*/
int main()
{
    // Let us construct the BST shown in the above figure
    struct Node *root        = newNode('A');
    root->left               = newNode('B');
    root->right              = newNode('C');
    root->right->left        = newNode('E');
    root->right->right       = newNode('F');
    root->right->left->left  = newNode('G');
    root->right->left->left->left  = newNode('I');
    root->right->left->left->right = newNode('J');
    root->right->right->right      = newNode('H');
    root->right->right->right->left = newNode('K');
//
//    char k = 'H';
//    cout << "Distace of the closest key from " << k << " is "<< findClosest(root, k) << endl;
   char k = 'C';
    int l = findClosest(root, k);
    cout << "Distace of the closest key from " << k << " is "<<  l<< endl;
//    k = 'E';
//    cout << "Distace of the closest key from " << k << " is "<< findClosest(root, k) << endl;
//    k = 'B';
//    cout << "Distace of the closest key from " << k << " is "<< findClosest(root, k) << endl;
    
    return 0;
}
