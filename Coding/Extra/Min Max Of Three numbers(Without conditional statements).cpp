//
//  //  Coding
//
//  Created by Surya Dheeshjith on 09/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Min and Max of three numbers without conditional statements

#include<iostream>
using namespace std;

int max(int a, int b, int c)
{
    int max = a;
    (max<b) && (max=b);
    (max<c) && (max=c);
    
    return max;
    
}

int min(int a, int b, int c)
{
    int min=a;
    (min>b) && (min=b);
    (min>c) && (min =c);
    
    return min;
}
