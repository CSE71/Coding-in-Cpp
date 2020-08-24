// https://leetcode.com/contest/weekly-contest-181/problems/longest-happy-prefix/

// Hashing (Similar to robin karpe)

string longestPrefix(string &s) {
    long h1 = 0, h2 = 0, mul = 1, len = 0, mod = 1000000007;
    for (int i = 0, j = s.length() - 1; j > 0; ++i, --j) {
        int first = s[i] - 'a', last = s[j] - 'a';
        h1 = (h1 * 26 + first) % mod;
        h2 = (h2 + mul * last) % mod;
        mul = mul * 26 % mod;
        if (h1 == h2)
            len = i + 1;
    }
    return s.substr(0, len);
}


// KMP method (Perfect for the problem)
// O(n)
string longestPrefix(string &s) {
        int i=1,len=0;
        int m = int(s.size());
        vector<int> lps(int(s.size()),0);
        lps[0] = 0;

        while(i<m)
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i] = len;
                i++;
            }

            else
            {
                if(len!=0)
                    len = lps[len-1];

                    //This is tricky. Consider the example "ababe......ababa", i is index of 'b', len==4. The longest prefix suffix is "abab",
                   //when pat[i]!=pat[len], we get new prefix "ababe" and suffix "ababa", which are not equal.
                   //This means we can't increment length of lps based on current lps "abab" with len==4. We may want to increment it based on
                   //the longest prefix suffix with length < len==4, which by definition is lps of "abab". So we set len to lps[len-1],
                   //which is 2, now the lps is "ab". Then check pat[i]==pat[len] again due to the while loop, which is also the reason
                   //why we do not increment i here. The iteration of i terminate until len==0 (didn't find lps ends with pat[i]) or found
                   //a lps ends with pat[i].

                else
                {
                    len =0;
                    i++;
                }
            }
        }

        return s.substr(0,len);
    }
