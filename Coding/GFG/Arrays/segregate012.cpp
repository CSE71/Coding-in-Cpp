#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;


void segregate0_1(vector<int> &s, int n)
{
    int left=0,right=n-1;
    while(left<right)
    {
        while(s[left]==0)
            left++;

        while(s[right]==1)
            right--;

        if(left<right)
        {
            int temp = s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
        }

    }


}

void segregate0_1_2(vector<int> &s, int n)
{
    int left=0,right=n-1;
    while(left<right)
    {
        while(s[left]==0)
            left++;

        while(s[right]==1 || s[right]==2)
            right--;

        if(left<right)
        {
            int temp = s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
        }


    }

    left=0;
    right=n-1;

    while(s[left]==0)
    left++;

    while(left<right)
    {
        while(s[left]==1)
            left++;

        while(s[right]==2)
            right--;

        if(left<right)
        {
            int temp = s[left];
            s[left]=s[right];
            s[right]=temp;
            left++;
            right--;
        }


    }
}

int main()
{
    vector<int> s;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
    {
        int ele;
        cin>>ele;
        s.push_back(ele);
    }

    segregate0_1_2(s,n);
    for(int i=0;i<n;i++)
        cout<<s[i]<<" ";


}
