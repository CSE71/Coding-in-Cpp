//
//  Counting valleys.cpp
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//
// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    
    int lev =0,val=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='U')
        {
            lev++;
            if(lev==0)
                val++;
            
        }
        else
        {
            lev--;
        }
    }
    return val;
}
