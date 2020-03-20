#include <iostream>

using namespace std;
int binarySearch(int a[],int low,int high,int key)
{
   while(low<=high)
   {
     int mid=(low+high)/2;
     if(a[mid]<key)
     {
         low=mid+1;
     }
     else if(a[mid]>key)
     {
         high=mid-1;
     }
     else
     {
         return mid;
     }
   }
   return -1;                //key not found
 }

 int binary_search(vector<int> &a, int query) {
    int left = 0, right = a.size() - 1;
    while (left < right) {
        int middle = (left + right) / 2;
        if (a[middle) < query) {
            left = middle + 1;
        } else {
            right = middle;
        }
    }
    if (a[left] == query) {
        return left;
    }
    return -1;
}

//////////////////////
//sqyare root
/////////////////////
long long f(int x) {
    return (long long)x * x;
}
int square_root(int x) {
    int left = 0, right = x;
    while (left < right) {
        int middle = (left + right) / 2;
        if (f(middle) <= x) {
            left = middle;
        } else {
            right = middle - 1;
        }
    }
    return left;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
