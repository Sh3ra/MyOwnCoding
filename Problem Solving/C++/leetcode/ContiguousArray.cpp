class Solution {
    #include <bits/stdc++.h>
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        int m=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i])sum++;
            else sum--;
            if(!sum) m=max(m,i+1);
            else if(mp[sum])
            {                
                m=max(m,i-mp[sum]+1);
            }
            else 
                mp[sum]=i+1;
        }
        return m;
    }
};