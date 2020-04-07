#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


long long get_fibonacci_huge_fast(unsigned long long n,unsigned long long m) {
    unsigned long long f0=0,f1=1;
    vector<unsigned long long>sequence;
    sequence.push_back(f0);
    sequence.push_back(f1);
    long long i=2;
    while (true)   
    {
        long long temp=f1;
        f1=(f1+f0)%m;
        f0=temp;
        sequence.push_back(f1);
        if(sequence[i-1]==0&&sequence[i]==1)
            break;
        i++;    
    }
    return sequence[n%(sequence.size()-2)];
}


int main() {
    unsigned long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
}
