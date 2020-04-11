#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  vector<pair<double,pair<int,int>>>vp;
  for (int i = 0; i < weights.size(); i++)
  {
    vp.push_back({(1.0*values[i])/weights[i],{weights[i],values[i]}});
  }
  sort(vp.begin(),vp.end());
  int i=weights.size()-1;
  while (capacity>0)
  {
    int weight_taken=min(capacity,vp[i].second.first);
    value+=(vp[i].first*weight_taken);
    capacity-=weight_taken;
    i--;
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
