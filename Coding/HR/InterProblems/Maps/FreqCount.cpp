//
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
// Find element with guven frequency efficiently

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
                freqmap[a]--;
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

