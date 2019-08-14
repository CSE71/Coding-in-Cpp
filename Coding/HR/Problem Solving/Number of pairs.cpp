//
//  Number of pairs.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//

//Find number of pairs of socks
// 1 <= arr[i] <=100

int sockMerchant(int n, vector<int> ar) {
    
    vector<int> aux(100,0);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(aux[ar[i]-1]==0)
            aux[ar[i]-1]=1;
        else if(aux[ar[i]-1]==1)
        {
            aux[ar[i]-1]=0;
            sum++;
        }
    }
    
    
    return sum;
}
