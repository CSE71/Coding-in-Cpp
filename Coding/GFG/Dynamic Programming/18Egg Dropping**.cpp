//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Egg dropping puzzle

// k = Number of floors ; n = Number of eggs

/*
 O(n*k^2)
 */
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t,n,k;
    cin>>t;
    while(t--)
    {
        //Enter code here
        cin>>n>>k;
        vector<vector<int>>dp(n+1,vector<int>(k+1,INT_MAX));
        
        for(int i=0;i<=n;i++) // BASE
        {
            dp[i][0]=0;
            dp[i][1]=1;
        }
        for(int i=1;i<=k;i++) // BASE
        dp[1][i] = i;
        
        for(int i=2;i<=n;i++)
        {
            for(int j=2;j<=k;j++)
            {
                for(int l=1;l<=j;l++)
                dp[i][j] = min(max(dp[i-1][l-1],dp[i][j-l])+1,dp[i][j]);
            }
        }
        cout<<dp[n][k]<<endl;
        
        
        
    }
}


/*
O(n*log k)


http://www.cs.umd.edu/~gasarch/BLOGPAPERS/eggold.pdf
Given the simplicity of the formula for the egg-drop
numbers, one might suspect that there is a direct counting technique we could use.
Indeed, there is. Consider a specific sequence of at most n drops with k eggs. Each of
the drops has two possible outcomes: either the egg breaks or the egg does not break.
Let 0 represent a drop without a break and 1 a drop with a break. Our sequence of
drops thus yields a binary word of length at most n and having between zero and k Is.
With this representation of drops, each word corresponds to a unique floor. For
example, in the case of 8 drops and 2 eggs, the word 01001 corresponds to floor 11.
In the general case, we make words of length m < n have length n by adding n - m
trailing zeros. Note that we only need do this for words that have exactly k Is, since
the efficiency of our procedure ensures that words with fewer than k broken eggs are
guaranteed to use all n drops. Also note that the trailing zeros are merely placeholders
and do not represent drops.
Thus, there is a one-to-one correspondence between the floors in our building and
the number of binary words of length n with at least one and no more than k Is. The
latter is easily shown to be k=1 sigma[j=1->k](nCj) while the former is (n,k).
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int bincoeff(int x, int n)
{
    int mul=1,sum=0;
    for(int i=1;i<=n;i++)
    {
        mul*=x-i+1;
        mul/=i;
        sum+=mul;
    }
    return sum;
}
int optimumdrops(int n,int k)
{
    int low=1;
    int high=k;
    
    while(low<high)
    {
        int mid = (low+high)/2;
        if(bincoeff(mid,n)<k) // Always n eggs to be picked
        low = mid+1;
        
        else
        high = mid;
    }
    
    return low;
}
int main()
 {
    int t,n,k;
    cin>>t;
    while(t--)
    {
        //Enter code here
        cin>>n>>k;
        cout<<optimumdrops(n,k)<<endl;
    }
}
