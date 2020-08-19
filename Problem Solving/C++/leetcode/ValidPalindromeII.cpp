class Solution {
public:
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        bool err=false;
        int back_up_i=-1,back_up_j=-1;
        while(i<=j)
        {
            //cout<<i<<" "<<s[i]<<" "<<j<<" "<<s[j]<<endl;
            if(s[i]!=s[j])
            {
                
                if(!err)
                {
                    err=true;
                    if(s[i+1]==s[j])
                    {
                        if(s[i]==s[j-1]){back_up_i=i;back_up_j=j-1;}
                        i++;
                        continue;
                    }
                    else if(s[i]==s[j-1]){j--;continue;}
                    else return false;
                }
                else if(back_up_i!=-1)
                {
                    i=back_up_i;
                    j=back_up_j;
                    back_up_j=-1;
                    back_up_i=-1;
                    continue;
                }
                else return false;
            }
            i++;
            j--;
        }
        return true;
    }
};