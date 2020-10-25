class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>>pal(s.size(),vector<bool>(s.size(),false));
        string ans;
        int mi=0,yet=1;
        for(int i=0;i<s.size();i++)
        {
            pal[i][i]=true;
            (i+1<s.size())?pal[i][i+1]=(s[i]==s[i+1]):i=i;
//            (i+1<s.size())?pal[i+1][i]=(s[i]==s[i+1]):i=i;
            if(i+1<s.size())
            {
                if(pal[i][i+1])
                {
                    mi=i;
                    yet=2;
                }
            }
            
        }
        for(int i=3;i<=s.size();i++)
        {
            for(int j=0;j<s.size()-i+1;j++)
            {
                int k=j+i-1;
                pal[j][k]=(pal[j+1][k-1]&&s[j]==s[k]);
                if(pal[j][k])
                {
                    if(i>yet)
                    {
                        yet=i;
                        mi=j;
                    }
                }
            }
        }
        ans=s.substr(mi,yet);
        return ans;
    }
};