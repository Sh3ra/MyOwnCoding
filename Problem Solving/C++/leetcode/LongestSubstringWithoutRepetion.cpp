class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,ans=0;
        map<char,bool>m;
        while(l<=r&&r<s.size())
        {
            //cout<<l<<" "<<r<<endl;
            m[s[l]]=true;
            if(l==r)
            {
                r++;
                continue;
            }
            if(m[s[r]])
            {
                ans=max((r-l),ans);
                while(s[l]!=s[r]&&l<r)
                {
                    m[s[l]]=false;
                    l++;
                }
                if(l!=r)
                {
                    m[s[l]]=false;
                    l++;
                }
            }
            else
            {
                m[s[r]]=true;
                r++;
                ans=max((r-l),ans);
            }
        }
        ans=max((r-l),ans);

        return ans;
        
    }
};
