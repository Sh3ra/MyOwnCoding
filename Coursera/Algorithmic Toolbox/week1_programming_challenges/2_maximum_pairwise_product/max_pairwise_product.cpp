#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    int max_index1=0;
    int max_index2=1;
    for (int i = 0; i < n; i++)
    {
        if(numbers[i]>numbers[max_index1])
        {
            max_index2=max_index1;
            max_index1=i;
        }
        else if(i!=max_index1&&numbers[i]>numbers[max_index2]){
            max_index2=i;
        }
    }
    cout<<((long long)(numbers[max_index1]))*numbers[max_index2];
    
    return 0;
}
