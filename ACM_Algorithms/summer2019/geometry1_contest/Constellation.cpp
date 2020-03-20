#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    long double lenght;
};

bool fun(long arr[])
{
    line a,b,c;
    a.x1 = arr[0];
    a.y1 = arr[1];
    a.x2 = arr[2];
    a.y2 = arr[3];
    b.x1 = arr[2];
    b.y1 = arr[3];
    b.x2 = arr[4];
    b.y2 = arr[5];
    c.x1 = arr[0];
    c.y1 = arr[1];
    c.x2 = arr[4];
    c.y2 = arr[5];
    long double temp1;
    temp1=(a.x1 - a.x2) ;
    temp1*=temp1;
    long double temp2;
    temp2= (a.y1 - a.y2) ;
    temp2*=temp2;
    a.lenght = sqrtl(temp1+temp2);
    temp1=(b.x1 - b.x2) ;
    temp1*=temp1;
    temp2= (b.y1 - b.y2) ;
    temp2*=temp2;
    b.lenght = sqrtl(temp1+temp2);
    temp1=(c.x1 - c.x2)  ;
    temp1*=temp1;
    temp2= (c.y1 - c.y2) ;
    temp2*=temp2;
    c.lenght = sqrtl(temp1+temp2);
    priority_queue<long double> pq;
    pq.push(a.lenght);
    pq.push(b.lenght);
    pq.push(c.lenght);
    long double line1, line2, line3;
    line1 = pq.top();
    pq.pop();
    line2 = pq.top();
    pq.pop();
    line3 = pq.top();
    pq.pop();
    long double xc = line2 + line3 - line1; 
    if (line2 + line3 - line1>1e-3)
    {
        return true;
    }
    return false;
}


int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    vector<pair<pair<long,long>,long>>coor;
    for(int i=0;i<n;i++)
    {
        long x,y;
        cin>>x>>y;
        coor.push_back(make_pair(make_pair(x,y),i+1));
    }
    sort(coor.begin(),coor.end());
    int i=0;
    while(i+2<n)
    {
        long arr[6];
        arr[0]=coor[i].first.first;
        arr[4]=coor[i+1].first.first;
        arr[2]=coor[i+2].first.first;
        arr[1]=coor[i].first.second;
        arr[5]=coor[i+1].first.second;
        arr[3]=coor[i+2].first.second;
        
        if (fun(arr))
        {
            break;
        }
        i++;
    }
        if(i+2!=n)
        cout<<coor[i].second<<" "<<coor[i+1].second<<" "<<coor[i+2].second;
         else if(n!=3) cout<<coor[i].second<<" "<<coor[i+1].second<<" "<<n;
        else cout<<coor[i].second<<" "<<coor[i+1].second<<" "<<1;
        return 0;
}
