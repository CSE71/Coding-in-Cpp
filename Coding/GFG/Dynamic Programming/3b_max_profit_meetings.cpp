#include<bits/stdc++.h>
using namespace std;


typedef struct meet{
    int start,finish,profit;

}meet;


bool compare(meet a, meet b)
{
    if(a.finish!=b.finish)
        return a.finish<b.finish;

    return a.start<b.start;
}

//void print_dp(vector<int> dp,int n)
//{
//    for(int i=0;i<n;i++)
//    {
//        cout<<dp[i]<<" ";
//
//    }
//    cout<<endl;
//}

int find_max(vector<meet> m,int n)
{
    vector<int> dp(n,0);
    sort(m.begin(),m.end(),compare);

    for(int i=0;i<n;i++)
        dp[i]=m[i].profit;

    int maxi = INT_MIN;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            //print_dp(dp,n);
            if(m[j].finish<=m[i].start && dp[i]<dp[j]+m[i].profit)
                dp[i]=dp[j]+m[i].profit;


            maxi = max(maxi,dp[i]);

        }

    }



    return maxi;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int start,end,profit;

        vector<meet> m;
        for(int i=0;i<n;i++)
        {
            cin>>start>>end>>profit;
            m.push_back({start,end,profit});

        }
        cout<<find_max(m,n);
    }
}
/*
 1
 4
 1 2 50
 3 5 20
 6 19 100
 2 100 200
 */
