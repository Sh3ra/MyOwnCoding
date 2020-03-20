#include <iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

int main()
{
    int j=0;
    char c;
    string w;
    string l;
    cin>>w;
    sort(w.begin(),w.end());
        pair<char,int>n[w.size()];
        priority_queue<int>srt;
        for(unsigned int i=0;i<w.size();i++)
        {
            if(i!=w.size()-1){
            if(w[i]!=w[i+1]){
            n[j].first=w[i];
            n[j].second=count(w.begin(),w.end(),w[i]);
            srt.push(count(w.begin(),w.end(),w[i])*-1);
            j++;}}
            else{
            n[j].first=w[i];
            n[j].second=count(w.begin(),w.end(),w[i]);
            srt.push(count(w.begin(),w.end(),w[i])*-1);
            j++;}
        }
        int x=srt.size();
        for(unsigned int i=0;i<x;i++)
        {
            for(j=0;j<x;j++)
            {
                if(srt.top()*-1==n[j].second)
                {
                    n[j].second=-1;
                    l.push_back(n[j].first);
                    srt.pop();
                    break;
                }
            }
        }
        if(l.size()%2==0)
        {
            x=l.size();
            for(j=0;j<(x-1)/2;j++)
            {
                l.pop_back();
            }
            c=l.back();
            l.pop_back();
            cout<<l.back()<<c;
        }
        else {
            x=l.size();
                        for(j=0;j<(x)/2;j++)
            {
                l.pop_back();}
                cout<<l.back();

        }


    return 0;
}
