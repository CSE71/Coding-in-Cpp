
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//First element to reach freq k

// Go thru array first and then go again from beginning
#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> um;
int main() {
    //code
    
    int t;
    cin >> t;
    
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int a[n];
        
        for(int i = 0;i<n;i++){
            cin >> a[i];
            um[a[i]]++;
        }
        bool flag = false;
        for(int i = 0;i<n;i++){
            if(um[a[i]] == k){
                cout << a[i] << endl;
                flag = true;
                break;
            }
        }
        if(flag == false){
            cout << "-1" << endl;
        }
        um.clear();
    }
    
    return 0;
}
