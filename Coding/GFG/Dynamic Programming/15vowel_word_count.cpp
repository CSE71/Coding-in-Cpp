//http://anothercasualcoder.blogspot.com/2019/10/count-vowels-permutation-standard-dp.html

#include <bits/stdc++.h>

using namespace std;


#define MOD 1000000007


int countPerms(int n) {

    if(n==1)
    return 5;

    vector<long> prev(5,1);
    vector<long> cur(5,0);

    long sumP = 4;
    for(int i=2;i<=n;i++)
    {
        cur[0] = prev[1];

        cur[1] = (prev[0]+prev[2])%MOD;

        cur[2] = sumP;

        cur[3] = (prev[2]+prev[4])%MOD;

        cur[4] = prev[0];

        sumP = 0;
        for(int j=0;j<5;j++)
        {
            prev[j] = cur[j];
            if(j!=2)
            sumP +=prev[j];
        }
        sumP%=MOD;

    }

    long ans = (cur[0]+cur[1]+cur[2]+cur[3]+cur[4])%MOD;

    return (int)ans;


}
