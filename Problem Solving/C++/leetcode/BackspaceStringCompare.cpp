class Solution {
#include <bits/stdc++.h>
public:
    bool backspaceCompare(string S, string T) {
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='#')
            {
                int index=i;
                S[i]='X';
                while(index>-1&&(S[index]=='#'||S[index]=='X'))
                    index--;
                if(index>-1)S[index]='X';
            }
        }
        //cout<<1;
        for(int i=0;i<T.size();i++)
        {
            if(T[i]=='#')
            {
                int index=i;
                T[i]='X';
                while(index>-1&&(T[index]=='#'||T[index]=='X'))
                    index--;
                if(index>-1)T[index]='X';
            }
        }
        //cout<<2;
        int i=0,j=0;
        while(i<S.size()&&j<T.size())
        {
           if(S[i]=='X'){
               i++;
               continue;
           }
           if(T[j]=='X'){
                 j++;
               continue;
           }
            if(S[i]!=T[j])return false;
            i++;j++;
        }
        if(i<S.size()-1)
        {
            for(i=i;i<S.size();i++)
                if(S[i]!='X')return false;
        }
        
        if(j<T.size()-1)
        {
            for(j=j;j<T.size();j++)
                if(T[j]!='X')return false;
        }
        return true;
    }
};