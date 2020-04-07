class Solution {
#include <bits/stdc++.h>
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int goodOdd=0,goodEven=0,ans=0;
            for(int i=1;i<nums.size();i+=2)
            {
                if(i>0&&i<nums.size()-1&&nums[i]>=min(nums[i-1],nums[i+1]))
                {
                    goodEven+=nums[i]-(min(nums[i-1],nums[i+1])-1);
                }
                else if(i>0&&nums[i]>=nums[i-1])
                {
                    goodEven+=nums[i]-(nums[i-1]-1);
                }
                else if(i<nums.size()-1&&nums[i]>=nums[i+1])
                {
                    goodEven+=nums[i]-(nums[i+1]-1);
                }
            }
            for(int i=0;i<nums.size();i+=2)
            {
                if(i>0&&i<nums.size()-1&&nums[i]>=min(nums[i-1],nums[i+1]))
                {
                    goodOdd+=nums[i]-(min(nums[i-1],nums[i+1])-1);
                }
                else if(i>0&&nums[i]>=nums[i-1])
                {
                    goodOdd+=nums[i]-(nums[i-1]-1);
                }
                else if(i<nums.size()-1&&nums[i]>=nums[i+1])
                {
                    goodOdd+=nums[i]-(nums[i+1]-1);
                }
            }
        return min(goodEven,goodOdd);
    }
};