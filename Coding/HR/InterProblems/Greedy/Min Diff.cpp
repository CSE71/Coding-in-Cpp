//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Minimum Difference

int minimumAbsoluteDifference(vector<int> arr) {
    
    int min = 999999999;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;i++)
    {
        if(arr[i+1]-arr[i]<min)
        min = arr[i+1]-arr[i];
    }
    return min;
}
