//
//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.
//Find if common words are present in magazine

void checkMagazine(vector<string> magazine, vector<string> note) {

int n=magazine.size(),m=note.size();
unordered_map<string,int> mp;
unordered_map<string,int> :: iterator it;

for(int i=0;i<n;i++)
{
    it = mp.find(magazine[i]);
    if(it==mp.end())
    {
        mp.insert(pair<string,int>(magazine[i],1));
    }
    else
        mp[magazine[i]]++;
}

for(int i=0;i<m;i++)
{
    it = mp.find(note[i]);
    if(it==mp.end())
    {
        cout<<"No\n";
        return;
        }
        else if(mp[note[i]]==0)
        {
            cout<<"No\n";
            return;
        }
        else
        mp[note[i]]--;
        }
        cout<<"Yes\n";
        
    }
