#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;



// subset stores the sums. cur is the subset idx.
bool util_check_partition(vector<int> a,  vector<int> subset,  vector<bool> visited, int sum, int n, int k, int cur, int last)
{

    if(subset[cur]==sum)
    {
        if(cur==k-2) // No need to check last one as it is a given it will sum to 'sum'
            return true;

        return util_check_partition(a, subset, visited, sum, n, k, cur+1, n-1);
    }

    for(int i=last;i>=0;i--)
    {
        if(visited[i])
            continue;

        int temp = subset[cur]+a[i];
        if(temp<=sum)
        {
            visited[i]=true;
            subset[cur] = temp;
            bool nxt = util_check_partition(a, subset, visited, sum, n, k, cur, last-1);

            if(nxt)
                return true;


            visited[i]=false;
            subset[cur] -=a[i];



        }
    }
    return false;
}
bool check_partition(vector<int> a, int n, int k)
{
    if(n<k)
        return false;
    if(k==1)
        return true;

    int sum=0;
    for(int i=0;i<n;i++)
        sum+=a[i];

    if(sum%k!=0)
        return false;

    vector<int> subset(n,0); // Holds sum for each of the K subset.
    vector<bool> visited(n,false);

    subset[0] = a[n-1];
    visited[n-1] = true;
    sum = sum/k;
    return util_check_partition(a,subset,visited,sum,n,k,0,n-1);

}

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int> a(n,0);

    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<check_partition(a,n,k);

}

/*
 10 3
 2 2 3 4 4 6 7 8 9 9
 */
