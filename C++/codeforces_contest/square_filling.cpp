#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main(){
 ll n,m;
 cin>>n>>m;
 ll i,j;
 ll ar[n][m],ar1[n][m];
 for(i = 0;i<n;i++){
     for(j = 0;j<m;j++){
         cin>>ar[i][j];
         ar1[i][j] = 0;
     }
 }
 vector <pair <ll,ll> > v;
 for(i = 0;i<n-1;i++){
     for(j = 0;j<m-1;j++){
         if(ar[i+1][j+1] && ar[i][j+1] && ar[i][j] && ar[i+1][j]) {
            ar1[i+1][j+1] = 1 , ar1[i][j+1]=1 , ar1[i][j] = 1, ar1[i+1][j] = 1 ;
            v.push_back(make_pair(i,j));
         }
     }
 }
 for(i = 0;i<n;i++){
     for(j = 0;j<m;j++){
         if(ar[i][j] != ar1[i][j] )
         {
             cout<<"-1"<<endl;
             return 0;
         }
     }
 }
 cout<<v.size()<<endl;
 for(i = 0;i<v.size();i++){
     cout<<v[i].first+1<<" "<<v[i].second+1<<endl;
 }
}