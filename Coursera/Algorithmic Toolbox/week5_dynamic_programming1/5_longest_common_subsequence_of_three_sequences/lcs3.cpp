#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c)
{
  int dp[a.size() + 1][b.size() + 1][c.size() + 1];
  dp[0][0][0] = 0;
  for (int i = 0; i <= a.size(); i++)
  {
    for (int j = 0; j <= b.size(); j++)
      dp[i][j][0] = 0;
    for (int j = 0; j <= c.size(); j++)
      dp[i][0][j] = 0;
  }
  for (int i = 1; i <= b.size(); i++)
  {
    for (int j = 1; j <= c.size(); j++)
    {
      dp[0][i][j] = 0;
      //max({dp[0][i - 1][j], dp[0][i][j - 1], dp[0][i - 1][j - 1] + ((b[i - 1] == c[j - 1]) ? 1 : 0)});
    }
  }
  for (int i = 1; i <= a.size(); i++)
  {
    for (int j = 1; j <= b.size(); j++)
    {
      for (int k = 1; k <= c.size(); k++)
      {
        dp[i][j][k] = max({dp[i-1][j][k-1],dp[i-1][j - 1][k],dp[i-1][j][k],dp[i][j - 1][k], dp[i][j][k - 1], dp[i][j - 1][k - 1] ,dp[i-1][j-1][k-1]+ ((b[j - 1] == c[k - 1]&&b[j-1]==a[i-1]) ? 1 : 0)});
      }
    }
  }
    return dp[a.size()][b.size()][c.size()];
}

  int main()
  {
    size_t an;
    std::cin >> an;
    vector<int> a(an);
    for (size_t i = 0; i < an; i++)
    {
      std::cin >> a[i];
    }
    size_t bn;
    std::cin >> bn;
    vector<int> b(bn);
    for (size_t i = 0; i < bn; i++)
    {
      std::cin >> b[i];
    }
    size_t cn;
    std::cin >> cn;
    vector<int> c(cn);
    for (size_t i = 0; i < cn; i++)
    {
      std::cin >> c[i];
    }
    std::cout << lcs3(a, b, c) << std::endl;
    return 0;
  }
