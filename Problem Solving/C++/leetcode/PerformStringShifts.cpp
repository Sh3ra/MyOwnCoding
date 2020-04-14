class Solution {
    #include <bits/stdc++.h>
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int res=0,rigt=0,left=0;
        string ans;
        for(int i=0;i<shift.size();i++)
        {
            if(shift[i][0])rigt+=shift[i][1];
            else left+=shift[i][1];
        }
        bool neg=false;
        res=rigt-left;
        if(res<0)neg=true;
        res=abs(res)%s.size();
        if(neg)res*=-1;
        //cout<<res<<endl;
        if(res>0)
        {
            ans+=s.substr(s.size()-res,s.size()-1);
            ans+=s.substr(0,s.size()-res);
        }
        else if(res<0)
        {
            ans+=s.substr(abs(res),s.size()-1);
            ans+=s.substr(0,abs(res));
        }
        else ans=s;
        return ans;
    }
};