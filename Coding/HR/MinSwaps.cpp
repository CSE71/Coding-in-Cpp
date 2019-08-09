//
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Min swaps to get sorted array

int minimumSwaps(vector<int> arr) {
    
    int n=arr.size();
    pair<int,int> p[n];
    for(int i=0;i<n;i++)
    {
        p[i].first = arr[i];
        p[i].second = i;
    }
    vector<int> v(n,0);
    
    sort(p,p+n);
    int cycle,swaps=0;
    for(int i=0;i<n;i++)
    {
        cycle=0;
        if(v[i]||p[i].second==i)
            continue;
        
        int j=i;
        while(!v[j])
        {
            v[j]=1;
            j = p[j].second;
            cycle++;
            
        }
        swaps += cycle-1;
        
    }
    return swaps;
}
