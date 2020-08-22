#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;

class LRUCache {

    list<int> a; // Vector would perform worse as there is need of deletion in the middle.
    map<int,list<int>::iterator> mp;
    int csize; // maximum capacity of cache

public:
    LRUCache(int);
    void refer(int);
    void display();
};

// Declare the size
LRUCache::LRUCache(int n)
{
    csize = n;
}

// Refers key x with in the LRU cache
void LRUCache::refer(int x)
{
    // Write your code here
    if(mp.find(x)==mp.end())
    {
        if(int(a.size())==csize)
        {
            int temp = a.back();
            mp.erase(temp);
            a.pop_back();

        }
    }

    else
        a.erase(mp[x]);

    a.push_front(x);
    mp[x]=a.begin();


}

// Function to display contents of cache
void LRUCache::display()
{
  // Write your code here
    for(auto x=a.begin();x!=a.end();x++)
        cout<<*x<<" ";

    cout<<endl;

}

// Driver Code
int main()
{
    LRUCache ca(4);

    ca.refer(1);
    ca.display();
    ca.refer(2);
    ca.display();
    ca.refer(3);
    ca.display();
    ca.refer(1);
    ca.display();
    ca.refer(4);
    ca.display();
    ca.refer(5);
    ca.display();

    return 0;
}
