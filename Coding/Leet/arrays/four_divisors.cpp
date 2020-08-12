//https://leetcode.com/contest/weekly-contest-181/problems/four-divisors/

// Solution : Any number n greater than 1 already have two divisors: 1 and n. So, for a number to have exact 4 divisors, there should be only one pair of divisors d and n / d.

// Catch: if d == n / d, the number has 3 divisors, not four.

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {

        int sums =0,cur,last;

        for(int i=0;i<int(nums.size());i++)
        {
            cur = nums[i];
            last =0;
            for(int j=2;j*j<=cur;j++) // There should be only one divisor between j and cur/j
            {
                if(cur%j==0)
                {
                    if(last==0)
                        last = j;

                    else // If another, break
                    {
                        last =0;
                        break;
                    }
                }
            }

            if(last>0 && cur/last != last)
                sums+= 1 + cur + cur/last + last;
        }
        return sums;

    }
};
