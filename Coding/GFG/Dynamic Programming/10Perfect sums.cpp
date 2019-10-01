//
//  Coding
//
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Number of subsets to get a specific sum
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    while(T--){
        int n, sum; cin >> n;
        
        vector<int> v(n);
        for(int i = 0; i < n; i++) cin >> v[i];
        cin >> sum;
        
       
        vector<vector<int>> dp(n+1, vector<int>(sum+1, 0));// BASE
        
        for(int i = 0; i <= n; i++) dp[i][0] = 1; // empty subset always sums to 0  // BASE
        for(int j = 1; j <= sum; j++) dp[0][j] = 0; // empty subset cannot generate non zero sum  // BASE
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum; j++){
                dp[i][j] = dp[i-1][j];
                if(v[i-1] <= j)// count of subsets that include (i-1)th element + those that skip (i-1)th element
                dp[i][j] = dp[i-1][j] + dp[i-1][j - v[i-1]];
                
            }
        }
        
        cout << dp[n][sum] << endl;
    }
    
    return 0;
}
