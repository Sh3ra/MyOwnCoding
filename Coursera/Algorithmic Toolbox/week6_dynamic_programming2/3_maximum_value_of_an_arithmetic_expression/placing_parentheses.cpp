#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

unordered_map<int,char>oper;
long long min_table[30][30];
long long max_table[30][30];
pair<long long,long long>min_and_max(int i,int j)
{
  long long mi=INT_MAX,ma=INT_MIN;
  for (int k = i; k <j ; k+=2)
  {
    long long a=eval(max_table[i][k],max_table[k+2][j],oper[k+1]);
    long long b=eval(max_table[i][k],min_table[k+2][j],oper[k+1]);
    long long c=eval(min_table[i][k],max_table[k+2][j],oper[k+1]);
    long long d=eval(min_table[i][k],min_table[k+2][j],oper[k+1]);
    mi=min({mi,a,b,c,d});
    ma=max({ma,a,b,c,d});
  }
  return {mi,ma};
}
long long get_maximum_value(const string &exp) {
  for (int i = 1; i < exp.size(); i+=2)
  {
    oper[i]=exp[i];
  }
  for (int i = 0; i < exp.size(); i+=2)
  {
    min_table[i][i]=exp[i]-'0';
    max_table[i][i]=exp[i]-'0';
    for (int s = 0; s < exp.size(); s+=2)
    {
      for (int i = 0; i <= exp.size()-s; i+=2)
      {
        int j=i+s;
        if(i==j)continue;
        pair<long long,long long>ans=min_and_max(i,j);
        min_table[i][j]=ans.first;
        max_table[i][j]=ans.second;
      }
    }
  }
  
  return max_table[0][exp.size()-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
