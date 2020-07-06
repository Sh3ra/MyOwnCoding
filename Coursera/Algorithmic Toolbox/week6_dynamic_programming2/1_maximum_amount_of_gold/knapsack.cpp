#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int optimal_weight(int W, const vector<int> &w) {
  //int val[W+1][w.size()+1];
  vector<vector<int>>val(W+1,vector<int>(w.size()+1));
  for (int i = 0; i <= W; i++)
  {
    val[i][0]=0;
  }
  for (int i = 0; i < w.size()+1; i++)
  {
    val[0][i]=0;
  }
  for (int i = 1; i <w.size()+1; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      val[j][i]=val[j][i-1];
      if(w[i-1]<=j)
      {
        val[j][i]=max({val[j][i],val[j-w[i-1]][i-1]+w[i-1]});
      }
    }
  }
  return val[W][w.size()];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
