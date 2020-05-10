#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int get_change(int m) {
  int dp[m];
  dp[0]=0;
  dp[1]=1;
  for (int i = 1; i <= m; i++)
  {
    if(i<3)
    dp[i]=dp[i-1]+1;
    else if(i==3)dp[i]=1;
    else
    {
      dp[i]=min({dp[i-1]+1,dp[i-3]+1,dp[i-4]+1});
    }
  }
  
  return dp[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
