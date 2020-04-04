#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t,T=1;
    cin>>t;
    while(T<=t)
    {
        string s,res;
        cin>>s;
        char maxi='a';
        int last_index=0;
        vector<int>digits;
        int paren_count=0;
        for(int i=0; i<s.size(); i++)
        {
            digits.push_back((int)(s[i]-'0'));
            if(digits[i]==0)
            {
                while (last_index<i)
                {
                    while (paren_count<digits[last_index])
                    {
                        res.push_back('(');
                        paren_count++;
                    }
                    while (paren_count>digits[last_index])
                    {
                        res.push_back(')');
                        paren_count--;
                    }
                    char a=s[last_index];
                    res.push_back(a);
                    last_index++;
                }
                while (paren_count>0)
                {
                    res.push_back(')');
                    paren_count--;
                }
            }
        }
        while (last_index<digits.size())
        {
            while (paren_count<digits[last_index])
            {
                res.push_back('(');
                paren_count++;
            }
            while (paren_count>digits[last_index])
            {
                res.push_back(')');
                paren_count--;
            }
            char a=s[last_index];
            res.push_back(a);
            last_index++;
        }
        while (paren_count>0)
        {
            res.push_back(')');
            paren_count--;
        }

        cout<<"Case #"<<T<<": "<<res<<endl;
        T++;
    }
    return 0;
}
