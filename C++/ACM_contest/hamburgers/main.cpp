#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int nb,ns,nc;
    cin>>nb>>ns>>nc;
    int pb,ps,pc;
    cin>>pb>>ps>>pc;
    unsigned long long int r;
    cin>>r;
    int anb=0,ans=0,anc=0;
    while(!s.empty())
    {
        if(s.back()=='B')
            anb++;
        else if(s.back()=='S')
            ans++;
        else if(s.back()=='C')
            anc++;
        s.pop_back();
    }

    unsigned long long int low=0,high=100000000001000;
    unsigned long long int mid;
    while(1)
    {
        mid=(low+high)/2;
        long long int p_b=((mid*anb)-nb)*pb;
        long long int p_s=((mid*ans)-ns)*ps;
        long long int p_c=((mid*anc)-nc)*pc;
        if(p_s<0)
            p_s=0;
        if(p_b<0)
            p_b=0;
        if(p_c<0)
            p_c=0;
        if(low==high&&p_b+p_s+p_c<r)
        {
            while(p_b+p_s+p_c<r)
            {
                mid++;
                p_b=((mid*anb)-nb)*pb;
                p_s=((mid*ans)-ns)*ps;
                p_c=((mid*anc)-nc)*pc;
                if(p_s<0)
                    p_s=0;
                if(p_b<0)
                    p_b=0;
                if(p_c<0)
                    p_c=0;
            }
            mid--;
            break;
        }
        if(low==high&&p_b+p_s+p_c>r)
        {
            while(p_b+p_s+p_c>r)
            {
                mid--;
                p_b=((mid*anb)-nb)*pb;
                p_s=((mid*ans)-ns)*ps;
                p_c=((mid*anc)-nc)*pc;
                if(p_s<0)
                    p_s=0;
                if(p_b<0)
                    p_b=0;
                if(p_c<0)
                    p_c=0;
            }

            break;
        }
        if(p_b+p_s+p_c==r)
        {
            break;
        }
        else if(p_b+p_s+p_c>r)
        {
            high=mid;
        }
        else
            low = mid+1;
    }
    cout<<mid;

    return 0;
}
