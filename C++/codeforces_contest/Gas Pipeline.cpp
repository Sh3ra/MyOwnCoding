#include <iostream>
#include <bits/stdc++.h>

using namespace std;
long long dp[200006][3];
int pipe,pillar;
long long solve(string x,int level,int index,int length){
if (index==length)
{
    return 0;
}
//if(dp[index][level]!=-1)return dp[index][level];
if(x[index]=='1'){
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

}

int main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--){
        int l;
        cin>>l>>pipe>>pillar;
        string x;
        cin>>x;
        memset(dp,-1,sizeof(dp));
        cout<<solve(x,0,0,l,pipe,pillar)<<endl;

    }
    return 0;
}
