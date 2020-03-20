#include <iostream>
#include <bits/stdc++.h>
#define M_PI 3.14159265358979323846

using namespace std;

int main(int argc, char const *argv[])
{
    long long h,l;
    cin >> h>>l;
    double x,angel;
    angel=atan(l/(h*1.0));
    x=tan(2*angel-M_PI/2)*l;
    printf("%.12lf",x);
    return 0;
}
