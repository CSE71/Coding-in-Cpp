//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Long integer take binary, flip its bits and output decimal value
// 0 < n < 2^32


long flippingBits(long n) {
    
    int a[100],i;
    for(i=0;n>0;i++)
    {
        a[i]=1-n%2;//Flipped
        n=n/2;
    }
    long ans =0;
    for(int k=0;k<32;k++)
    {
        if(k<i)
            ans+=pow(2,k)*a[k];
        
        else
            ans+=pow(2,k);//Rest 1s
    }
    return ans;
}

