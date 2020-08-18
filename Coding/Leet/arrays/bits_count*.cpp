#include <bits/stdc++.h>
using namespace std;

// method returns total number of substring having K ones
int countOfSubstringWithKOnes(string s, int K)
{
    int N = s.length();
    int res = 0;
    int countOfOne = 0;
    int freq[N + 1] = {0};

    // initialize index having zero sum as 1
    freq[0] = 1;

    // loop over binary characters of string
    for (int i = 0; i < N; i++) {

        // update countOfOne variable with value
        // of ith character
        countOfOne += (s[i] - '0');

        // if value reaches more than K, then
        // update result
        if (countOfOne >= K) {

            // add frequency of indices, having
            // sum (current sum - K), to the result
            res += freq[countOfOne - K];
        }

        // update freqency of one's count
        freq[countOfOne]++;
    }
    return res;
}

// Driver code to test above methods
int main()
{
    string s = "10010";
    int K = 1;
    cout << countOfSubstringWithKOnes(s, K) << endl;
    return 0;
}

/*

freq - Frequency of ones array. Stores the number of substrings for each number of ones.

Ex. 1 - 1000101, k=2

        - ; countOfOne = 0 ; freq = {1,0,0,0,0,0,0}   ; Substrings for count=0 = {} //empty is one substring
        1 ; countOfOne = 1 ; freq = {1,1,0,0,0,0,0}   ; Substrings for count=1 = {1}
        0 ; countOfOne = 1 ; freq = {1,2,0,0,0,0,0}   ; Substrings for count=1 = {1, 10}
        0 ; countOfOne = 1 ; freq = {1,3,0,0,0,0,0}   ; Substrings for count=1 = {1, 10, 100}
        0 ; countOfOne = 1 ; freq = {1,4,0,0,0,0,0}   ; Substrings for count=1 = {1, 10, 100, 1000}
        1 ; countOfOne = 2 ; res+ = freq[2-2] = 1 ; freq = {1,4,1,0,0,0,0}   ; Substrings for count=2 = {10001}

        Basically counts the number of substrings at the first index

        0 ; countOfOne = 2 ; res+ = freq[2-2] = 1+1=2 ; freq = {1,4,2,0,0,0,0}   ; Substrings for count=2 = {10001,100010}
        1 ; countOfOne = 3 ; res+ = freq[3-2] = 2+4=6 ; freq = {1,4,2,1,0,0,0}   ; Substrings for count=3 = {10001,100010,000101,00101,0101,101}


*/
