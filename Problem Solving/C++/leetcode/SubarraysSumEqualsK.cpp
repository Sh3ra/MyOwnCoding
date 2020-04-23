class Solution
{
#include <bits/stdc++.h>
public:
    int subarraySum(vector<int> &nums, int k)
    {
        //vector<int>prefix_sum(nums.size()+1);
        unordered_map<int, int> m;
        // prefix_sum[0]=0;
        //cout<<prefix_sum[0]<<" ";
        //m[prefix_sum[0]]++;
        int ans = 0;
        int sum = 0;
        m[sum]++;
        for (int i = 1; i <= nums.size(); i++)
        {
            //prefix_sum[i]=prefix_sum[i-1]+nums[i-1];
            sum += nums[i - 1];
            //cout<<prefix_sum[i]<<" ";
            //ans+=m[prefix_sum[i]-k];
            ans += m[sum - k];
            //m[prefix_sum[i]]++;
            m[sum]++;
        }
        //unordered_set<int>s;
        /*for(int i=0;i<=nums.size();i++)
        {
            /*if(s.find(prefix_sum[i]-k)==s.end())
            {
                s.insert(prefix_sum[i]);
                m[prefix_sum[i]]++;
            }
            else {*/

        //s.insert(prefix_sum[i]);
        // }
        //}
        return ans;
    }
};