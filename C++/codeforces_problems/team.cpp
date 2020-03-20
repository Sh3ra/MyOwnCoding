#include <iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int z, o;
    cin >> z >> o;
    int total = z + o;
    if (z - 1 > o || o>(z+1)*2)
        cout << -1;
    else
    {
        while (total > 0)
        {

            if (o > z + 1)
            {
                o -= 2;
                cout << 11;
            }
            else if (o > 0&&o>=z)
            {
                cout << 1;
                o--;
            }
            if (z > 0)
            {
                cout << 0;
                z--;
            }
            total = z + o;
        }
    }

    return 0;
}
