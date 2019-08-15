//
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//Find triplets of G.P


long countTriplets(vector<long> arr, long r) {
    
    map<long,long> mp1,mp2;  //mp1 contains second element of GP triplet. mp2 contains the third element of the triplet.
    long res =0;
    for(int i=0;i<arr.size();i++)
    {
        if(mp2.count(arr[i])) // If third element is also part of arr then we add onto res. //Count() : to check if key is there in map
        {
            res+=mp2[arr[i]];
        }
        if(mp1.count(arr[i]))
        {
            mp2[arr[i]*r]+=mp1[arr[i]];  //Predicting the future. Second Step.
        }
        mp1[arr[i]*r]++;  //Predicting the future. First step.
    }
    return res;
    
}

