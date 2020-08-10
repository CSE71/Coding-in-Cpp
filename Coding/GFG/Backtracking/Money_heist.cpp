

#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
#include<iostream>
using namespace std;

int max_=INT_MIN;


void print(vector<int> a)
{
    cout<<"a : ";
    for(int i=0;i<int(a.size());i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int calculate_sum(vector<int> a, int n, vector<int> cap, vector<int> fear)
{
    int sum=0;
    for(int i=0;i<int(a.size());i++)
        sum+= cap[a[i]-1] + int(a.size())*fear[a[i]-1];

//    cout<<"sum :"<<sum<<endl;
    return sum;
}

pair<int,int> find_max(vector<int> a, int n, int m, vector<int> cap, vector<int> fear)
{

    if(n==0)
    {
        int k = calculate_sum(a,n,cap,fear);
        if(k<=m)
        {
            pair<int,int> p = {k,int(a.size())};
            return p;
        }

        return make_pair(INT_MIN,0);

    }


    a.push_back(n);

//    print(a);
//    cout<<"n :"<< n<<endl;
    pair<int,int> k1 = find_max(a,n-1,m,cap,fear);
    a.pop_back();
//    print(a);
//    cout<<"-n :"<< n<<endl;
    pair<int,int> k2 = find_max(a,n-1,m,cap,fear);

    if(k1.first<k2.first)
        return k2;

    return k1;



}

int main()
{
    int N,M;
    cin>>N>>M;


    vector<int> cap(N,0);
    vector<int> fear(N,0);
    for(int i=0;i<N;i++)
    {
        cin>>cap[i];
    }

    for(int i=0;i<N;i++)
    {
        cin>>fear[i];
    }

    vector<int> a;
    pair<int,int> ans = find_max(a,N,M,cap,fear);
    cout<<ans.second;


    return 0;
}

/*
5 200
2 5 3 2 4
30 40 10 20 30
 */
s
