#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i =0; i < t  ;i++){
        int n ,m ;
        cin >> n;
        cin >> m;
        int arr[n][m];
        for (int j = 0; j < n ; j++){
                string s;
                cin>>s;
            for (int k = 0; k < m ; k++){
                arr[j][k] = s[k] - '0';
            }
        }
        int border = 0;
        int inner = 0;
        for (int j = 0; j < n ; j++){
            for (int k = 0; k < m ; k++){
                if (j == 0 || j == n - 1 || k== 0 || k == m - 1){
                    if (arr[j][k] == 0){
                        border++;
                    }
                } else if (j != 0 && j != n - 1 && k!= 0 && k != m - 1){
                    if (arr[j][k] == 1){
                        inner++;
                    }
                }
            }
        }

        if (border <= inner){
            cout << border << endl;
        }else {
            cout << -1 << endl;
        }
    }
    return 0;
}
