#include <iostream>
#include <bits\stdc++.h>

using namespace std;

void removeSpaces(char *str)
{
    // To keep track of non-space character count
    int count = 0;

    // Traverse the given string. If current character
    // is not space, then place it at index 'count++'
    for (int i = 0; str[i]; i++)
        if (str[i] != ' ')
            str[count++] = str[i]; // here count is
                                   // incremented
    str[count] = '\0';
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while (t--)
    {
        int q, m;
        cin >> q >> m;
        bool arr[q][4];
        bool arr2[q][4];
        bool check[q];
        memset(arr, false, sizeof(arr));
        memset(arr2, true, sizeof(arr2));
        memset(check, false, sizeof(check));
        for (int i = 0; i < m; i++)
        {
            string temp;
            string temp2;
            int index = 0;
            for (int j = 0; j < q; j++)
            {
                cin >> temp;
                cin >> temp2;
                //cout<<temp<<endl;
                //cout<<temp2<<endl;
                if (temp2[0] == 'T')
                {
                    check[j] = true;
                    arr[j][temp[0] - 'A'] = true;
                }
                else
                    arr2[j][temp[0] - 'A'] = false;
            }
        }
        bool done = false;
        for (int i = 0; i < q; i++)
        {
                char l;
            if (check[i] == true)
            {
                done = false;
                for (int j = 0; j < 4; j++)
                {
                    if (arr[i][j])
                    {
                        l = j + 'A';
                       if(i!=q-1) cout << l << " ";
                       else cout<<l;
                        break;
                    }
                }
            }
            else
            {
                int countyer = 0;
                for (int j = 0; j < 4; j++)
                {
                    if (arr2[i][j])
                    {
                        countyer++;
                        l=j+'A';
                    }
                }
                if(countyer==1){
                if(i!=q-1)cout<<l<<" ";
                else cout<<l;
                }
                else if(i!=q-1)cout<<"?"<<" ";
                else cout<<"?";
            }
        }
            cout << endl;
    }

        return 0;
    }
