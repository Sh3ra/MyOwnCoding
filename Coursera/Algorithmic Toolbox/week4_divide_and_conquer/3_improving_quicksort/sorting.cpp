#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using std::vector;
using std::swap;
using namespace std;
std::pair<int,int> partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  int m2=l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] < x) {
      j++;
      m2++;
      swap(a[m2], a[j]);
      if(i!=m2)swap(a[i], a[j]);
    }
    else if(a[i]==x){
      m2++;
      swap(a[m2],a[i]);
    }
  }
  swap(a[l], a[j]);
  return {j,m2};
}
//int counter=0;
//int arr[]={2,0,2,9,8,9};

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  //int k=arr[counter];
  //counter++;
 // cout<<"k="<<k<<endl;
  swap(a[l], a[k]);
  std::pair<int,int>p = partition2(a, l, r);

  randomized_quick_sort(a, l, p.first-1);
  randomized_quick_sort(a, p.second+1, r);
}

void stressTest()
{
  while (true)
  {
    int n=(rand()%100000)+1;
    vector <int>a(n);
    cout<<n<<endl;;
    for (int i = 0; i < n; i++)
    {
      a[i]=(rand()%1000000000)+1;
      cout<<a[i]<<' ';
    }
    cout<<endl;
    vector<int>t=a;
    sort(t.begin(),t.end());
    randomized_quick_sort(a,0,a.size()-1);
    bool ok=true;
    for (int i = 0; i < n; i++)
    {
      if(a[i]!=t[i]){
        ok=false;
        break;
      }
    }
    if(!ok){
      cout<<"WA"<<endl;
      for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << ' ';
      }
      cout<<endl;
      for (size_t i = 0; i < n; i++)
      {
        cout<<t[i]<<' ';
      }
      break;
    }
    else cout<<"OK"<<endl;
  }
  
}

int main() {
  //stressTest();
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }  
}
