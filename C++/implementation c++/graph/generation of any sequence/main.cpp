#include <bits/stdc++.h>
using namespace std;
set<int> numbers;
void Generate(string s)
{
    if(atoll(s.c_str()) > 1e9)
        return;
    numbers.insert(atoll(s.c_str()));
    Generate(s + '4');
    Generate(s + '7');
}
int main()
{
    int n;
    cin >> n;
    Generate("");
    int o = 0;
    for(set<int>::iterator it = numbers.begin();it != numbers.end();it++)
    {
        if(*it == n)
        {
           cout << o;
            return 0;
        }
        o++;
    }
    return 0;
}
