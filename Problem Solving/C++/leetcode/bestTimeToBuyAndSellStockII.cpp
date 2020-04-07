class Solution {
#include <bits/stdc++.h>
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        if(prices.size()==0)return 0;
        for(int i=0;i<prices.size()-1;i++)
        {
            if(prices[i]>=prices[i+1])
                continue;
            int nextI=i+1;
            while(nextI<prices.size()-1)
            {
                if(prices[nextI]>prices[nextI+1])
                    break;
                nextI++;
            }
            profit+=(prices[nextI]-prices[i]);
            i=nextI;
        }
        return profit;
    }
};