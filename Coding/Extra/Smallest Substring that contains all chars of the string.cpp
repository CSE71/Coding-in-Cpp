//
//  //  Coding
//
//  Created by Surya Dheeshjith on 09/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//Smallest substring that contains all the characters of the string itself

#include</Users/suryad/Coding/Coding/Coding/stdc++.h>
using namespace std;

int Max_c = 256;

string findminsubstring(string str)
{
    int n=str.length();
    
    int dist_count =0;
    vector<int> ch(Max_c,0);
    for(int i=0;i<n;i++)
    {
        if(ch[str[i]]==0)
        {
            ch[str[i]]=1;
            dist_count++;
        }
        
    }
    int start =0,start_index=-1,minlen = INT_MAX;
    int count =0;
    vector<int>curr_count(Max_c,0);
    
    for(int i=0;i<n;i++)
    {
        curr_count[str[i]]++;
        
        if(curr_count[str[i]]==1)
            count++;
        
        if(count==dist_count)
        {
            while(curr_count[str[start]]>1)
            {
                curr_count[str[start]]--;
                start++;
            }
            
            int l = i-start+1;
            if(l<minlen)
            {
                minlen=l;
                start_index=start;
            }
        }
    }
    return str.substr(start_index,minlen);
}
int main()
{
    string str;
    cin>>str;
    cout << "Smallest window containing all distinct"
    " characters is " << findminsubstring(str)<<endl;
    return 0;
}

