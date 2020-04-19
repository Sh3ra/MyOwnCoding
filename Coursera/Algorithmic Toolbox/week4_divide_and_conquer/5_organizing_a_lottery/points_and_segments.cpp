#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cstdlib>

using std::vector;
using namespace std;

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points)
{
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++)
  {
    for (size_t j = 0; j < starts.size(); j++)
    {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}


int main()
{
  //stress_test();
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  vector<pair<int, char>> ans;
  for (size_t i = 0; i < starts.size(); i++)
  {
    std::cin >> starts[i] >> ends[i];
    ans.push_back({starts[i], 'l'});
    ans.push_back({ends[i], 'r'});
  }
  unordered_map<int, vector<int>> ma;
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++)
  {
    std::cin >> points[i];
    ans.push_back({points[i], 'p'});
    ma[points[i]].push_back(i);
  }
  //use fast_count_segments
  //vector<int> cnt = naive_count_segments(starts, ends, points);
  vector<int> cnt(m); //= fast_count_segments(starts,ends, points);
  int lcnt = 0;
  sort(ans.begin(),ans.end());
  for (int i = 0; i < ans.size(); i++)
  {
    if (ans[i].second == 'l')
      lcnt++;
    else if (ans[i].second == 'r')
      lcnt--;
    else
    {
      for (int j = 0; j < ma[ans[i].first].size(); j++)
      {
        cnt[ma[ans[i].first][j]] = lcnt;
      }
    }
  }

  for (size_t i = 0; i < cnt.size(); i++)
  {
    std::cout << cnt[i] << ' ';
  }
}
