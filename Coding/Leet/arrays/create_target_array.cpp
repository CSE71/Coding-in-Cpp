//https://leetcode.com/contest/weekly-contest-181/problems/create-target-array-in-the-given-order/

class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {

        vector<int> ans;
        for(int i = 0;i < nums.size();i ++)
        {
            ans.insert(ans.begin()+index.at(i), nums.at(i));
        }

        return ans;
    }
};
