//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Finding all anagrams
//For example s= [mom], the list of all anagrammatic pairs is [m,m], [mo,om] 

int sherlockAndAnagrams(string s) {

unordered_map<string,int> mp;
for(int i=0;i<s.length();i++)
{
    for(int j=1;j+i-1<s.length();j++) // Both ways forward = i<j, backward = i>j
    {
        string a = s.substr(i,j);
        sort(a.begin(),a.end());
        mp[a]++;
        
    }
}
int count=0;
for(auto x=mp.begin();x!=mp.end();x++)
{
    count+=x->second*(x->second-1)/2;
}
return count;
}
