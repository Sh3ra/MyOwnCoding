class Solution {
    #include<bits/stdc++.h>
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int>m;
        for(int i=0;i<dominoes.size();i++)
        {
            if(dominoes[i][0]>dominoes[i][1])
            {
                int t=dominoes[i][0];
                dominoes[i][0]=dominoes[i][1];
                dominoes[i][1]=t;
            }
            m[dominoes[i]]++;
        }
        int cnt=0;
        for(int i=0;i<dominoes.size();i++)
        {
            int n=m[dominoes[i]];
            m[dominoes[i]]=0;
            cnt+=((n*(n-1))/2);
        }
        return cnt;
    }
};