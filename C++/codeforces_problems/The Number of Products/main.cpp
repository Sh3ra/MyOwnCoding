#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n,pos=0,neg=0,counter=0;
    cin>>n;
    long long arr[n];
    vector<pair<long long ,long long>>data;
    for(int i=0;i<n;i++)
        cin>>arr[i];
        for(int j=0;j<n;j++)
        {
            if(arr[j]<0)
                counter++;
                if(counter%2==0)
                    pos++;
                else neg++;
            data.push_back(make_pair(neg,pos));
        }
        bool swapy=false;
        long long tpos=pos,tneg=neg;
        for(int i=0;i<n;i++)
        {
            if(arr[i]<0)
            {
                    if(swapy)swapy=false;
                    else swapy=true;
            }

                if(!swapy){
                pos+=tpos-data[i].second;
                neg+=tneg-data[i].first;
                }
                else
                {
                    pos+=tneg-data[i].first;
                    neg+=tpos-data[i].second;
                }

        }

    cout<<neg<<" "<<pos;
    return 0;
}
