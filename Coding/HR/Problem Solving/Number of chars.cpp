//
//  Number of chars.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
//Number of 'a's in a repeated string with specified length
long repeatedString(string s, long n) {
    
    long long int na =0,total =0;
    if(n<=s.length())
    {
        for(int i=0;i<n;i++)
            if(s[i]=='a')
                na++;
        return na;
    }
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='a')
            na++;
    }
    long long int no = n/s.length();
    total = na*no;
    
    int rem = n%s.length();
    for(int i=0;i<rem;i++)
    {
        if(s[i]=='a')
            total++;
    }
    return total;
}
