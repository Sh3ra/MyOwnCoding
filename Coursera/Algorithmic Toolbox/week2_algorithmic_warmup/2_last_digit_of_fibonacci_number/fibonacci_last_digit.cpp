#include <iostream>

int get_fibonacci_last_digit_fast(int n) {
    int f0=0,f1=1;
    if(n==0)return f0;
    for (int i = 2; i <= n; i++)
    {
        int temp=f1;
        f1=(f0+f1)%10;
        f0=temp;
    }
    return f1;
}

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    return 0;
}   
