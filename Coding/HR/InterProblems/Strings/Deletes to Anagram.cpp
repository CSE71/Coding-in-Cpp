//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// How many deletions to get an anagram

#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    auto count = 0;
    vector<int> freq(26, 0);
    for (auto c : a) { ++freq[c - 'a']; }
    for (auto c : b) { --freq[c - 'a']; }
    for (auto val : freq) { count += abs(val); }//Can be negative as string b can have elements that a does not.
    return count;
}

