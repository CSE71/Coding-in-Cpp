#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<complex>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define sz(x) (int)(x).size()
#define popcount __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 105, INF = 1000000000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int ts, n, m, k;
string s[MX];

int dfs(int i, int j){
	if(s[i][j] == '*') return 1; // Return to res, when reached the destination.
	s[i][j] = 'X';  // Mark as visited
	int cnt = 0, res = 0;
	rep(v,4){
		int ni = i+dx[v]; // Shift to new position
		int nj = j+dy[v]; //
		if(ni>=0&&nj>=0&&ni<n&&nj<m&&s[ni][nj]!='X'){  // Check if safe
			++cnt; // If it is, add one to count (choices)
			res = max(res,dfs(ni,nj)); // DFS. When reached dest, res becomes 1.
		}
	}
	if(!res) return 0; // When reached a dead end.
	return res+(cnt>1); // 1 + no. of choices/2. No.of choices/2 will give the number of times hermione needs to use wand.
}

// Every stage of the dfs, i.e. every cell or loocation, we check the number of choices we have, and we divide them by two to get the number of
// wand uses. It will accumulate in res at every location and finally returns res (1) + number of wand uses.
// Res can  be either 0 or 1. When it reaches or not. When it is 0, we havent reached destination yet so ignore the choices.
// cnt can be 0,1,2 or 3; 0/2 = 0, 1/2 = 0, 2/2 =1, 3/2 =1.

int main(){
	cin >> ts;
	rep(ti,ts){
		cin >> n >> m;
		rep(i,n) cin >> s[i];
		cin >> k;

		int si,sj;
		rep(i,n)rep(j,m){
			if(s[i][j] == 'M') si = i, sj = j;
		}

		string ans = "Oops!";
		if(dfs(si,sj) == k+1) ans = "Impressed";
		cout << ans << endl;
	}

	return 0;
}
