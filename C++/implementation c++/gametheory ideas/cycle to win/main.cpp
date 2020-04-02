#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dp[100000];
int game(int n){
    if(dp[n]!=-1){
        return dp[n];
    }
   else if(n==0||n==3)return dp[n]=0;
    else if(n<=4)return dp[n]=1;
   else if(game(n-4)==0||game(n-2)==0||game(n-1)==0)return dp[n]=1;
return dp[n];
}
int main(){
    memset(dp,-1,sizeof dp);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(game(n)==1)cout<<"JELLY\n";
		else cout<<"JACK\n";
	}
}
