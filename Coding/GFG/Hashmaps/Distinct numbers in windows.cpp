
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Distinct numbers in windows of array

void countDistinct(int A[], int k, int n)
{
    unordered_map<int,int>mp;
    for(int i=0;i<k;i++)
    {
        mp[A[i]]++;
    }
    cout << mp.size() << " ";
    for(int i=k;i<n;i++)
    {
        mp[A[i]]++;
        mp[A[i-k]]--;
        if(mp[A[i-k]]==0) mp.erase(A[i-k]);
        cout << mp.size() << " ";
    }
}
