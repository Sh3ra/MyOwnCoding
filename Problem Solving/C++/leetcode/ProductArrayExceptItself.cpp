class Solution {
    #include <bits/stdc++.h>
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        ans.push_back(1);
        for(int i=1;i<nums.size();i++)
        {
            ans.push_back(ans.back()*nums[i-1]);
        }
        int prev_mul=1;
        for(int i=nums.size()-2;i>-1;i--)
        {
            ans[i]*=nums[i+1]*prev_mul;
            prev_mul*=nums[i+1];
        }
        return ans;
    }
};                      