#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
//#include <bits/stdc++.h>
using std::vector;
using std::string;
using namespace std;
bool mySort (string a,string b)
{
  string ab=a.append(b);
  string ba=b.append(a);
  return ab>ba;
}
string largest_number(vector<string> a) {
  //write your code here
  //sort with respect of the left most digit if equal the next digit and so on till one of them end
  sort(a.begin(),a.end(),mySort);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

void systemTester(){
  int n=rand()%99+1;
  cout<<n<<endl;
  vector<string>a;
  for (int i = 0; i < n; i++)
  {
    int x=rand()%999+1;
    a.push_back(to_string(x));
    cout<<a[i]<<" ";
  }
  cout<<endl;
  cout<<largest_number(a)<<endl;
}

int main() {
 /* while (true)
  {
    char a;
    cin>>a;
    systemTester();
  }
  */
    
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
