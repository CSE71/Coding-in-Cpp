//
//  Counting valleys.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Implementing maps

long long getBin(int n)
{
    long long int a = 0;
    while(n)
    {
        int rem = n%2;
        a = a*10 + rem;
        n = n/2;
    }
    return a;
}

long consOnes(long long int bin)
{
    long int cons=0,len=0;
    int rem;
    while(bin)
    {
        rem = bin%2;
        if(rem==1)
            len++;
        else
            len =0;
        
        if(len>cons)
            cons = len;
        
        bin = bin/10;
    }
    return cons;
}
int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    long long int bin = getBin(n);
    long int cons = consOnes(bin);
    cout<<cons;
    return 0;
}
