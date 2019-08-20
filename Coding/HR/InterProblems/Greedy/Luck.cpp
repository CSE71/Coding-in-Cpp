//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Find Luck if k important contents can be lost. More you lose more luck increases. important contests is 1 and not important is 0.


int luckBalance(int k, vector<vector<int>> contests) {
    
    vector<int> a;
    int luck =0;
    
    for(int i=0;i<contests.size();i++)
    {
        if(contests[i][1])
        {
            luck-= contests[i][0];
            a.push_back(contests[i][0]);
        }
        
        else
        luck+=contests[i][0];
    }
    sort(a.begin(),a.end(),greater<int>());
    for(int i=0;i<min(k,(int)a.size());i++)
    {
        luck+= 2*a[i];//Add the subtracted and add it again to increase luck.
    }
    
    return luck;
}

