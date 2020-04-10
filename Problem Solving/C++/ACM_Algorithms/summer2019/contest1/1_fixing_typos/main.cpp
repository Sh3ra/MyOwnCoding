#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string res;
    int triple=0,index=0;
    bool prev_rep=false,incoming=false;
    res=res+s[0];
    index++;
    for(unsigned int i=1;i<s.length();i++)
    {
            if(s[i]==res[index-1])
            {
                triple++;
                if(triple>=2)continue;
                if(prev_rep&&incoming)
                {
                    prev_rep=false;
                    incoming=false;
                    continue;
                }
                    res+=s[i];
                    index++;
                    prev_rep=true;
            }
            else{
                    if(prev_rep&&!incoming)incoming=true;
                    else
                    {prev_rep=false;
                    incoming=false;}
                    triple=0;
                    res+=s[i];
                    index++;
                 }
    }
    cout << res;
    return 0;
}
