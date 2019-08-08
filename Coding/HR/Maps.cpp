//
//  Counting valleys.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Implementing maps

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin>>t;
    string str;
    long long int no;
    map<string,long long int> mp;
    while(t--)
    {
        cin>>str>>no;
        mp.insert(pair<string,long long>(str,no));
        
    }
    while(cin>>str)
    {
        if(mp.find(str) != mp.end())
        {
            cout<<str<<"="<<mp.find(str)->second<<endl;
        }
        else
            cout<<"Not found"<<endl;
    }
    return 0;
}

