#include <iostream>
#include <vector>

using std::vector;
long long merge(vector<int> &a,size_t left,size_t ave, size_t right)
{
  vector<int>ans;
  long long t=0;
  size_t mid=ave;
  int start=left;
  while (left<mid&&ave<right)
  {
    if(a[left]<=a[ave]){
      ans.push_back(a[left]);
      left++;
      t+=(ave-mid);
    }
    else
    {
      ans.push_back(a[ave]);
      ave++;
    }
  }
  if(left<mid)
    {
      for (size_t i = left; i < mid; i++)
      {
        ans.push_back(a[i]);
        //if(i>left)
          t+=(right-mid);
      }
    }
  if(ave<right)
    {
      for (size_t i = ave; i < right; i++)
      {
        ans.push_back(a[i]);
      }
    }
    int j=0;
    for (size_t i = start; i < right; i++)
    {
      a[i]=ans[j];
      j++;
    }
  return t;
}
long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  number_of_inversions+=merge(a,left,ave,right);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
