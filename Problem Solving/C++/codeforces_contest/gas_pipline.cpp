#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long dp[200006][3];
int length,pipe,pillar;
long long solve(string x,int level,int i){
if (i>length)
{
    return pillar;
}
//if(dp[index][level]!=-1)return dp[index][level];
if(x[i]=='1'){
    if(level==0){
        return 2*pillar+2*pipe+solve(x,1,i+1); 
    }
    else
    {
        return 2*pillar+pipe+solve(x,1,i+1);
    }
    }
    else{
        if(level==0){
            return pipe+pillar+solve(x,0,i+1);            
        }
        else{
        return min(2*pipe+pillar+solve(x,0,i+1),2*pillar+pipe+solve(x,1,i+1));
        }
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        cin>>length>>pipe>>pillar;
        string x;
        cin>>x;
        //memset(dp,-1,sizeof(dp));
        cout<<solve(x,0,1)<<endl;

    }
    return 0;
}
