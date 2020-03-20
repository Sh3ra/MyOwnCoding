    #include <iostream>
    #include <bits/stdc++.h>

    using namespace std;

int main()
{
    string s, res;
    cin >> s;
    int u = 0, l = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
            u++;
        else
            l++;
    }
    if (u > l)
    {
        for (int i = 0; i < s.length(); i++)
        {
            char temp = s[i];
            temp = toupper(temp);
            res.push_back(temp);
        }
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            char temp = s[i];
            temp = tolower(temp);
            res.push_back(temp);
        }
    }
    cout<<res;
    return 0;
}
