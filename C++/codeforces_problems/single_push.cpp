#include <iostream>
#include <bits\stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        bool checker = false;
        bool checker2 = false;
        int diff = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != b[i])
            {
                if (checker)
                {
                    cout << "NO" << endl;
                    checker2=true;
                    break;
                }
                while (a[i] != b[i] && i < n)
                {
                    if (diff == 0)
                    {
                        diff = b[i] - a[i];
                        if (diff < 0)
                        {
                            cout << "NO" << endl;
                            checker2=true;
                            break;
                        }
                    }
                    else if (b[i] - a[i] != diff)
                    {
                        cout << "NO" << endl;
                        checker2=true;
                        break;
                    }
                    i++;
                }
                if(checker2)break;
                checker=true;
            }
        }
        if(!checker2)
        cout<<"Yes"<<endl;
    }
    return 0;
}
