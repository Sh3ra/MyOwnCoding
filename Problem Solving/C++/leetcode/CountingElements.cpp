class Solution {
    #include <bits/stdc++.h>
public:
    int countElements(vector<int>& arr) {
        int cnt=0;
        unordered_map<int,int>m;
        for(int x : arr)
        {
            m[x]++;
        }
        for(int x : arr)
        {
            if(m[x+1])
                cnt++;
        }
        return cnt;
    }
};