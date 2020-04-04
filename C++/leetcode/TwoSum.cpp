class Solution {
#include <bits/stdc++.h>
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int>us;
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            if(us.find(nums[i])!=us.end())
            {
                res.push_back(i);
                for(int j=0;j<nums.size();j++)
                {
                    if(nums[j]==target-nums[i])
                    {
                        res.push_back(j);
                        return res;
                    }
                }
            }
            us.insert(target-nums[i]);
        }
        return res;
    }
};