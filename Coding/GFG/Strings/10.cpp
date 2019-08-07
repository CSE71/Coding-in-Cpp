//
//  10.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Longest palindrome

#include<bits/stdc++.h>

using namespace std;

string longestPalindrome(string A) {
    
    int i,high,low,len,start=0,max=1;
    len=A.size();
    
    for(i=1;i<len;i++){
        
        //EVEN
        low=i-1;
        high=i;
        while(low>=0 && high<len && A[low]==A[high]){
            if(high-low+1>max){
                max=high-low+1;
                start=low;
            }
            --low;
            ++high;
        }
        
        //ODD
        low=i-1;
        high=i+1;
        while(low>=0 && high<len && A[low]==A[high]){
            if(high-low+1>max){
                max=high-low+1;
                start=low;
            }
            --low;
            ++high;
        }
        
    }
    return A.substr (start,max);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        cout<<longestPalindrome(str)<<endl;
    }
    return 0;
}
