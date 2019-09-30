//
//  12.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// A TO I
int atoi(string str)
{
    //Your code here
    int a=0;
    bool neg;
    
    for(int i=0;i<str.size();i++)
    {
        if(i==0 && str[i]=='-')
        neg = true;
        
        else if((str[i]-'0')<0 || (str[i]-'0')>9)
        return -1;
        
        else
        a = a*10 + str[i]-'0';
        
    }
    if(neg)
    return -a;
    
    return a;
}
