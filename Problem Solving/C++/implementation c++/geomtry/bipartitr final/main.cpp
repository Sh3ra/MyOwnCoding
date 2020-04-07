#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <stdio.h>
#include <ctype.h>
#define ll long long
#include <algorithm>
using namespace std;
ll l = 0,r = 0;
void dfs(vector<ll>A[], ll B[], ll depth, ll check){
    if(check == 0){
        l++;
    }else {
        r++;
    }
    B[depth] = 1;
    for(ll i = 0; i < A[depth].size(); i++) {
        if(B[A[depth][i]] == 0){
            ll c = 0;
            if(check == 0){
                c = 1;
            } else{
                c = 0;
            }
            dfs(A,B,A[depth][i],c);
        }
    }
}
int main()
{
    //std::ifstream in("test.txt");
    //std::cin.rdbuf(in.rdbuf());
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll n;
    cin>>n;
    vector<ll>A[n];
    ll b = n - 1;
    for(ll i = 0; i < b; i++){
        ll c,v;
        cin>>c;
        cin>>v;
        c--;
        v--;
        A[c].push_back(v);
        A[v].push_back(c);
    }
    ll B[n] = {0};
    dfs(A, B, 0, 0);
    l = l * r;
    l -= b;
    if(l < 0){
        l = 0;
    }
    cout<<l;
    return 0;
}
