class Solution {
    #include <bits/stdc++.h>
public:
    void moveZeroes(vector<int>& nums) {
        int no_index=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                nums[no_index]=nums[i];
                no_index++;
            }
        }
        for(int i=no_index;i<nums.size();i++)
            nums[i]=0;
    }
};