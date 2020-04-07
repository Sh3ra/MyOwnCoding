#include<bits/stdc++.h>

using namespace std;
bool hate [16][16];
int maxA=0;
int bitmaskG=0;
set<string>output;
int n;
void Search(int bitmask,int c)
{
    bool correct=true;
    //string binary = std::bitset<16>(bitmask).to_string();
    //cout<<binary<<endl;
    if(c>n)return;
    int counter=0;
    for (int i = 0; i < n; i++)
    {
        int temp=1;
        temp=temp<<i;
        if(bitmask&temp)
        {
            for (int j = 0; j < n; j++)
            {
                int temp2=1;
                temp2=temp2<<j;
                if(bitmask&temp2)
                {
                    if(hate[i][j])
                    {
                        correct=false;
                        break;
                    }
                }
            }
            if(!correct)break;
        }
    }
    counter=__builtin_popcount(bitmask);
    if(counter>maxA&&correct)
    {
        maxA=counter;
        bitmaskG=bitmask;
    }
    bitmask=bitmask<<1;
    c++;
    Search(bitmask,c);
    bitmask=bitmask|1;
    Search(bitmask,c);
    return;        
}
int main(int argc, char const *argv[])
{
    cin>>n;
    int m;cin>>m;
    vector<string>v_s;
    map<string,int>mi;
    for(int i=0;i<n;i++)
    {
        string t;cin>>t;
        mi[t]=i;
        v_s.push_back(t);
    }
    for (int i = 0; i < m; i++)
    {
        string t1,t2;cin>>t1>>t2;
        hate[mi[t1]][mi[t2]]=true;
        hate[mi[t2]][mi[t1]]=true;
    }
    Search(1,1);
    for(int i=0;i<n;i++)
    {
        int temp=1;
        temp=temp<<i;
        if(bitmaskG&temp)
        {
            output.insert(v_s[i]);
        }
    }
    cout<<output.size()<<endl;
    for (auto it=output.begin(); it != output.end(); ++it) 
        cout << *it<<endl; 
    
    return 0;
}
