#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int sum=0;
  unordered_set<int>s;
  for (int i = 1; i <= n; i++)
  {
    int new_elem=min(i,n-sum);
    if(s.find(new_elem)!=s.end())
    {
      sum-=(i-1);
      summands[summands.size()-1]=n-sum;
      break;
    }
    else
    {
      s.insert(new_elem);
      sum+=new_elem;
      summands.push_back(new_elem);
    }
    if(sum==n)break;
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
