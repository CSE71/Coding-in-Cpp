
/// Top Down DFS

int dp[100001];
class Solution {

    public:

    int numberOfArrays_util(const string &s, int k, int start) // Making it const string &s passed all test cases without timing out :')))
    {

        if(start==s.size()) return 1;

        if(s[start]=='0') return 0;

        if(dp[start]!=-1) return dp[start];

        long sum=0;
        int ways=0;
        for(int i=start;i<s.length();i++)
        {
            //cout<<sum<<endl;
            sum = sum*10 + s[i]-'0';
            if(sum>k)
                break;
            ways+=numberOfArrays_util(s,k,i+1);
            ways%=1000000007;
        }
        return dp[start] = ways;
    }


    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return numberOfArrays_util(s,k,0);

    }
};



/// Top Down BFS (No recursion)

int numberOfArrays(string s, int k) {
    vector<int> dp(s.size() + 1);
    dp[s.size()] = 1;
    for (int start = s.size() - 1; start >= 0; --start) {
        if (s[start] == '0')
            continue;

        int sum=0;
        for (int j = start; j < s.size(); ++j) {
            sum = sum * 10 + s[j] - '0';
            if (sum > k)
                break;
            dp[start] = (dp[start] + dp[j+1]) % 1000000007;
        }
    }
    return dp[0];
}
