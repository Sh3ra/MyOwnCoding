// you can use includes, for example:
// #include <algorithm>
#include <bits/stdc++.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<string> &A) {
        unordered_map<string,int>m;
        long log maxi=INT_MIN;
    for(string x:A)
    {
        sort(x.begin(),x.end());
        m[x]=0;
    }
    for(string x:A)
    {
        m[x]++;
        maxi=max(maxi,m[x]);
    }
    return maxi;
}
