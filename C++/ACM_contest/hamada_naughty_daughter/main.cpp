#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
    int m;
    cin>>m;
    for(int h=0;h<m;h++)
    {
        int n;
        cin>>n;
        vector<string>anime;
        vector<string>channel;
        string word;
        pair<string,int>p[n];
        priority_queue<int>p_q;
        for(int i=0;i<n;i++)
        {
            cin>>word;
            anime.push_back(word);
            word.clear();
            cin>>word;
            channel.push_back(word);

        }
        sort(channel.begin(),channel.end());
        int w=0;
        for(int j=0;j<n;j++)
        {
            if(j!=n-1){
            if(channel[j]!=channel[j+1]){
                p[w].first=channel[j];
                p[w].second=count(channel.begin(),channel.end(),channel[j]);
                p_q.push(count(channel.begin(),channel.end(),channel[j]));
                w++;
            }
            }
            else{p[w].first=channel[j];
                p[w].second=count(channel.begin(),channel.end(),channel[j]);
                p_q.push(count(channel.begin(),channel.end(),channel[j]));
                w++;}
        }
        int e=p_q.size();


            for(int j=0;j<e;j++)
            {
                if(p_q.top()==p[j].second)
                    {
                        cout<<p[j].first;
                        break;
                    }
            }
           if(h!=m-1) cout<<endl;
    }
    return 0;
}
