
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Merge sorted linked lists
Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
       multiset<int> a;
       for(int i=0;i<N;i++)
       {
           Node *temp = arr[i];
           while(temp)
           {
                a.insert(temp->data);
                temp = temp->next;
           }
       }
       
       Node* res = new Node(0);
       Node* temp = res;
       for(auto x = a.begin(); x!=a.end();x++)
       {
           Node* newnode = new Node(*x);
           temp->next = newnode;
           temp = temp->next;
           
       }
       return res->next;
}
