#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
vector<unsigned long long>sequence;

long long get_seqquence_sum(unsigned long long n,unsigned long long m) {
    unsigned long long f0=0,f1=1;
    sequence.push_back(f0);
    sequence.push_back(f1);
    long long i=2,sum=0;
    while (true)   
    {
        long long temp=f1;
        f1=(f1+f0)%m;
        f0=temp;
        sequence.push_back((f1*f1)%10);
        if(sequence[i-1]==0&&sequence[i]==1)
            break;
        i++;    
    }
    for (int i = 0; i < sequence.size()-2; i++)
    {
        sum+=sequence[i];
    }
    return sum;
}


int main() {
    long long n = 0,sum=0;
    std::cin >> n;
    sum=get_seqquence_sum(n,10);
    int s=sequence.size()-2;
    long long rst=0;
    for(int i=0;i<=n%s;i++)rst+=sequence[i];
    std::cout << ((sum*(n/s))+rst)%10;
}
