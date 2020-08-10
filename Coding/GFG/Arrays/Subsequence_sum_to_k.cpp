

#include</Users/suryad/Coding/Coding/Coding/stdc++.h>

using namespace std;

typedef long long LL;

vector<int> a;

LL dp[102][102][2004];
LL ways(int indx, int remele, int remsum) { //index, remaining elements to fill, remaining sum
    if (remsum == 0)
        return remele == 0;
    if(indx==-1)
        return 0;
    if (remsum < 0)
        return 0;
    if (remele < 0)
        return 0;


    LL &ret = dp[indx][remele][remsum]; // IMP to make it faster
    if(ret==-1) {
    ret = ways(indx-1,remele, remsum) + ways(indx-1,remele - 1, remsum - a[indx]); // Without idx element and with idx element.
    }
    return ret;
}
int main()
{

    memset(dp, -1, sizeof(dp));
    int n=50,sum=20;
    for(int i=0;i<n;i++)
        a.push_back(i+1);
    LL x=0;
    for(int i=1;i<n;i++) // We try to fill i number of elements in a subset each iteration.
    {
         x+=ways(n-1,i,sum);
    }
    cout<<x;
    return 0;
}
