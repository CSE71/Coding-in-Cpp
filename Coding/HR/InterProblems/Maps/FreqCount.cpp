//
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
// Find element with given frequency efficiently
//You are given  queries. Each query is of the form two integers described below:
//- 1 x : Insert x in your data structure.
//- 2 y : Delete one occurence of y from your data structure, if present.
//- 3 z : Check if any integer is present whose frequency is exactly z. If yes, print 1 else 0.
//The queries are given in the form of a 2-D array  of size  where  contains the operation, and contains the data element.

vector<int> freqQuery(vector<vector<int>> queries) {
    
    vector<int> ret;
    unordered_map<long,int> map;
    unordered_map<int,long> freqmap; //Efficiency
    ret.clear();
    for(int i=0;i<queries.size();i++)
    {
        
        if(queries[i][0]==1)
        {
            
            freqmap[map[queries[i][1]]]--;
            map[queries[i][1]]++;
            freqmap[map[queries[i][1]]]++;
        }
        else if(queries[i][0]==2)
        {
            
            int a = map[queries[i][1]];
            if(a>0)
            {
                freqmap[map[queries[i][1]]]--;
                map[queries[i][1]]--;
                freqmap[map[queries[i][1]]]++;
                
            }
        }
        else if(queries[i][0]==3)
        {
            
            if(freqmap[queries[i][1]]>0)
                ret.push_back(1);
            else
                ret.push_back(0);
            
        }
        
    }
    return ret;
    
    
}

