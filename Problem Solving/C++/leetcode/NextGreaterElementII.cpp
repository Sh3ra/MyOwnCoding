class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
       int n=nums.size();
        vector<int>ans(n);
        stack<int>s;
        int t=2;
        while(t--){
            for(int i=n-1;i>-1;i--)
            {
                while(!s.empty()&&nums[s.top()]<=nums[i])
                {
                    s.pop();
                }
                 if(s.empty())
                {
                    ans[i]=-1;
                    s.push(i);
                }
                else{
                    ans[i]=nums[s.top()];
                    s.push(i);
                }
            }
        }
        return ans;
    }
};