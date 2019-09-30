//
//  12.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 04/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Find substring in string

int strstr(string s, string x)
{
     //Your code here
     int i=0,j;
     while(i<s.size())
     {
         j=0;
         while(j<x.size() && s[i]==x[j])
         {
            i++;
            j++;
            
         }
         if(j==x.size())
         return i-x.size();
         
         else
         i++;
     }
     return -1;
}
