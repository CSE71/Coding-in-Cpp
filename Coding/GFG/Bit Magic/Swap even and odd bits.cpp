
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Swap even and odd bits
#include<bits/stdc++.h>
using namespace std;

unsigned int swapBits(unsigned int n)
{
    unsigned int ev=n & 0xAAAAAAAA; //10101010101010101010101010101010 in binary. We get even bits set if they were in n
    unsigned int od=n & 0x55555555; //01010101010101010101010101010101 in binary. We get odd bits set if they were in n
    
    ev>>=1;// Right Shift the evn obtained previously by 1 positions and store it in evn
    od<<=1;// Left Shift the od obtained previously by 1 positions and store it in odd
    return (ev | od); //Do bitwise OR of evn and od to get the final result
}

