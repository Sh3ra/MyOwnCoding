#include <iostream>

int get_change(int m) {
  int ans=0;
  ans+=m/10;
  m-=10*(m/10);
  ans+=m/5;
  m-=5*(m/5);
  ans+=(m/1);
  return ans;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
