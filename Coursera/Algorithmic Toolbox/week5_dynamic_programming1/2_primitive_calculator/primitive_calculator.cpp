#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

vector<int> optimal_sequence(int n)
{
  // std::vector<int> sequence;
  // while (n >= 1) {
  //   sequence.push_back(n);
  //   if (n % 3 == 0) {
  //     n /= 3;
  //   } else if (n % 2 == 0) {
  //     n /= 2;
  //   } else {
  //     n = n - 1;
  //   }
  // }
  // reverse(sequence.begin(), sequence.end());
  // return sequence;
  vector<int> ans(n+1);
  vector<int> res;
  int dp[n+1];
  dp[0] = 0;
  ans[0]=0;
  dp[1] = 0;
  ans[1]=0;
  dp[2] = 1;
  ans[2]=1;
  for (int i = 3; i <= n; i++)
  {
    int a = INT_MAX, b = INT_MAX, c = INT_MAX;
    if (i % 2 == 0)
      a = dp[i / 2] + 1;
    if (i % 3 == 0)
      b = dp[i / 3] + 1;
    c = dp[i - 1] + 1;
    dp[i] = min({a, b, c});
    if (dp[i] == a)
      ans[i]=(i / 2);
    else if (dp[i] == b)
      ans[i]=(i / 3);
    else
      ans[i]=(i - 1);
  }
  res.push_back(n);
  int index=n;
  while (ans[index]>0)
  {
    res.push_back(ans[index]);
    index=ans[index];
  }
  //res.push_back(1);
  reverse(res.begin(),res.end());
  return res;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i)
  {
    std::cout << sequence[i] << " ";
  }
}
