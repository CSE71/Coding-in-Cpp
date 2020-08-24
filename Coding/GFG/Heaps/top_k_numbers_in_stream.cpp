#include<bits/stdc++.h>
#define ll long long
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define fr(i,n) for(int i=0;i<n;i++)
#define fnr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define sz(arr) sizeof(arr)/sizeof(arr[0])
using namespace std;

#define ppi pair<int,int>
#define F first
#define S second

struct comp {
  bool operator() (const ppi a,const ppi b) {
      if(a.S == b.S)
        return a.F > b.F;
        return a.S<b.S;
  }
};

int main()
{
	int t;cin>>t;
	while(t--) {
	    int n,k;cin>>n>>k;
	    unordered_map<int,int> m;
	    int x;
	    for(int i=0;i<n;i++) {
	        cin>>x;
	        m[x]++;
	    	priority_queue<ppi,vector<ppi>,comp> q(m.begin(),m.end()); // takes O(N) time to build
	        int cnt=0;
	        while(!q.empty() && cnt<k) {
    	        cout<<q.top().F<<" ";
	            q.pop();
	            cnt++;
	        }
	    }
	    cout<<endl;

	}

	return 0;
}
