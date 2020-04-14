class Solution {
    #include <bits/stdc++.h>
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue <int> pq;
        for(int i=0;i<stones.size();i++)
        {
            pq.push(stones[i]);
        }
        int x,y;
        while(!pq.empty())
        {
            x=pq.top();
            pq.pop();
            if(!pq.empty())
            {
                y=pq.top();
                pq.pop();
                if(abs(x-y)!=0)
                {
                    pq.push(abs(x-y));
                }
                else x=0,y=0;
            }
        }
        return x;
        
    }
};