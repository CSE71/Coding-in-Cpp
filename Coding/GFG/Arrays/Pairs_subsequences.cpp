

#include</Users/suryad/Coding/Coding/Coding/stdc++.h>

using namespace std;

typedef long long LL;

#define MOD 1000000007

int a[3000];
LL dp[102][102][2004];

// void print_dp(LL dp[102][102][2004])
// {
//     for(int i=0;i<102;i++)
//     {
//         for(int j=0;j<102;j++)
//         {
//             for(int k=0;k<2004;k++)
//                 if(dp[i][j][k]!=-1)
//                 cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<";";
//
//
//         }
//
//
//     }
// }

LL ways(int cele, int remele, int remsum) {
    if (remsum == 0)
        return remele == 0;
    if (cele == -1)
        return 0;
    if (remsum < 0)
        return 0;
    if (remele < 0)
        return 0;

    //print_dp(dp);
    LL &ret = dp[cele][remele][remsum]; // IMP
    if(ret==-1) {
     ret = ways(cele - 1, remele, remsum) + ways(cele - 1, remele - 1, remsum - a[cele]);
        if (ret >= MOD)
            ret -= MOD;
}
    return ret;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    int i, m, r, s;
    cin >> m >> r >> s;
    for (i = 0; i < m; i++)
        cin >> a[i];
    if ((r + s) % 2 != 0 || r < s) {
        return 0;
    }
    int v1 = (r + s) / 2, v2 = (r - s) / 2;
    LL ans = 0;
    for (i = 1; i <= m; i++)
       ans += (ways(m - 1, i, v1) * ways(m - 1, i, v2)) % MOD;
    ans %= MOD;
    cout << endl << endl<< ans << endl;
    return 0;
}
