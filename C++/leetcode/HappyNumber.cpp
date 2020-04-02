class Solution {
#include <bits/stdc++.h>
#define MOD 1000000007
public:
    vector<int>get_digits(int n) {
        vector<int>t;
        while(n!=0)
        {
            t.push_back(n%10);
            n/=10;
        }
        return t;
    }
public:
    int fast_power(int base, int power) {
    int result = 1;
    while(power > 0) {

        if(power &1) { 
            result = (result*base) % MOD;
        }
        base = (base * base) % MOD;
        power >>= 1;
    }
    return result;
}
public:
    bool isHappy(int n) {
        set<vector<int>>s_v;
        vector<int>digits=get_digits(n);
        while(s_v.find(digits) == s_v.end())
        {
            s_v.insert(digits);
            int sum=0;
            for(int i=0;i<digits.size();i++)
            {
                sum+=fast_power(digits[i],2);
            }
            if(sum==1)return true;
            digits.clear();
            digits=get_digits(sum);
        }
        return false;
    }

};