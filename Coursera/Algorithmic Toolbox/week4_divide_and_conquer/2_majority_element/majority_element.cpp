#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right)
{
  if (left == right)
    return -1;
  if (left + 1 == right){
    //std::cout << a[left] <<" ";
    return a[left];
  }
  int mid = left + (right - left) / 2;
  int l = get_majority_element(a, left, mid);
  int r = get_majority_element(a, mid, right);
  int lc=0,rc=0;
  //std::cout << left <<" "<< right<<std::endl;
  if(l!=-1||r!=-1){
    for (int i = left; i < right; i++)
    {
      if(l!=-1&&a[i]==l)lc++;
      if(r!=-1&&a[i]==r)rc++;
    }
  }
  if(lc>(right-left)/2)return l;
  if(rc>(right-left)/2)return r;
  return -1;
}

int main()
{
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i)
  {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
