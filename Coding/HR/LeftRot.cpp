//
//  Counting valleys.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Left Rotation

vector<int> rotLeft(vector<int> a, int d) {
    
    int n=a.size();
    vector<int> b;
    b.push_back(a[d]);
    for(int i=(d+1)%n;i!=d;i=(i+1)%n)
        b.push_back(a[i]);
    
    return b;
}
