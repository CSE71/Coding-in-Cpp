
//  Created by Surya Dheeshjith on 02/07/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.


//Word Boggle

// Find words in a 2 D matrix by moving U,L,D,R,UL,UR,DL,DR

#include<bits/stdc++.h>
using namespace std;

set<string> ans;

struct trie{
  trie *arr[256];
  bool end;
  trie()
  {
      for(int i=0;i<256;i++)
      arr[i] = NULL;
      
      end = false;
  }
};

void inserttrie(trie* root, string s)
{
    trie* temp =root;
    for(int i=0;i<s.size();i++)
    {
        int k = s[i]-'A';
        if(!temp->arr[k])
        temp->arr[k]=new trie();
        
        temp=temp->arr[k];
        
    }
    temp->end = true;
}


bool prefix(trie* root, string p)
{
    trie* temp = root;
    for(int i=0;i<p.size();i++)
    {
        int k = p[i]-'A';
        if(temp->arr[k])
        temp = temp->arr[k];
        
        else
        return false;
    }
    return true;
}

bool search(trie* root, string p)
{
    trie* temp = root;
    for(int i=0;i<p.size();i++)
    {
        int k = p[i]-'A';
        if(temp->arr[k])
        temp = temp->arr[k];
        
        else
        return false;
    }
    return temp->end;
}

void check(trie* root,vector<vector<bool>> &vis,vector<vector<char>> a,int i,int j,string p)
{
    if(i<0 || j<0 || i>=a.size() || j>= a[0].size())
    return;
    
    if(search(root,p))
    {
        ans.insert(p);
    }
    if(prefix(root,p) && !vis[i][j])
    {
        vis[i][j]=true;
        p+=a[i][j];
        check(root,vis,a,i+1,j,p);
        check(root,vis,a,i+1,j-1,p);
        check(root,vis,a,i+1,j+1,p);
        check(root,vis,a,i,j+1,p);
        check(root,vis,a,i,j-1,p);
        check(root,vis,a,i-1,j,p);
        check(root,vis,a,i-1,j+1,p);
        check(root,vis,a,i-1,j-1,p);
        
        vis[i][j]=false;
        p.pop_back();
    }
    
}

int main()
 {
    int t,k,m,n;
    char ch;
    string a;
    cin>>t;
    while(t--)
    {
        //Enter code here
        ans.clear();
        cin>>k;
        vector<string> s;
        for(int i=0;i<k;i++)
        {
            cin>>a;
            s.push_back(a);
        }
        cin>>m>>n;
        vector<vector<char>> a(m);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>ch;
                a[i].push_back(ch);
            }
        }
        trie* root = new trie();
        for(int i=0;i<k;i++)
        {
            inserttrie(root,s[i]);
        }
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        string p ="";
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(root->arr[a[i][j]-'A'] && !vis[i][j])
                {
                    vis[i][j]=true;
                    p+=a[i][j];
                    check(root,vis,a,i+1,j,p);
                    check(root,vis,a,i+1,j-1,p);
                    check(root,vis,a,i+1,j+1,p);
                    check(root,vis,a,i,j+1,p);
                    check(root,vis,a,i,j-1,p);
                    check(root,vis,a,i-1,j,p);
                    check(root,vis,a,i-1,j+1,p);
                    check(root,vis,a,i-1,j-1,p);
                    
                    vis[i][j]=false;
                    p.pop_back();
                    
                }
            }
    
      
       
        }
        if(ans.size()==0)
              cout<<-1<<endl;
          else
          {
             for(auto x = ans.begin();x!=ans.end();x++)
             {
                 cout<<*x<<" ";
             }
             cout<<endl;
          }
    
    }
}
