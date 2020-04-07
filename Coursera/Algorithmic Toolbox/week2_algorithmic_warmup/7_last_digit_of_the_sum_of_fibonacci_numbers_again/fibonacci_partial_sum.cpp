#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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
        sequence.push_back(f1);
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
    long long n = 0,m,sum=0;
    std::cin >> n>>m;
    sum=get_seqquence_sum(m,10);
    int s=sequence.size()-2;
    long long rst=0;
    for(int i=0;i<=m%s;i++)rst+=sequence[i];
    long long ans1=((sum*(m/s))+rst)%10+sequence[n%s];
    rst=0;
    for(int i=0;i<=n%s;i++)rst+=sequence[i];
    long long ans2=((sum*(n/s))+rst)%10;


    std::cout << ans1-ans2;
}
