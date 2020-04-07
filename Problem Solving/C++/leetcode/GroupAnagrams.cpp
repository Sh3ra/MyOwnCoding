class Solution {
    #include <bits/stdc++.h>
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>temp=strs;
        unordered_map<string,int>m;
        unordered_map<string,bool>done;
        int index=0;
        
        for(int i=0;i<temp.size();i++)
        {
           // string t=temp[i];
            sort(temp[i].begin(),temp[i].end());
            //temp[i]=t;
            ////cout<<m[t]<<" ";
            if(!done[temp[i]])
            {
                m[temp[i]]=index;
                index++;
                done[temp[i]]=true;
            }  
        }
        vector<vector<string>>res(index);
        for(int i=0;i<strs.size();i++)
        {
            res[m[temp[i]]].push_back(strs[i]);
        }
        return res;
    }
};