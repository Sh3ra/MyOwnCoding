#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> vp;
int result[9][9];
bool done = false;

vector<vector<int>> get_dimensions(int i, int j)
{
    vector<vector<int>> dimensions(2, vector<int>(2));
    if (i < 3)
    {
        dimensions[0][0] = 0;
        dimensions[1][0] = 2;
    }
    else if (i < 6)
    {
        dimensions[0][0] = 3;
        dimensions[1][0] = 5;
    }
    else
    {
        dimensions[0][0] = 6;
        dimensions[1][0] = 8;
    }
    if (j < 3)
    {
        dimensions[0][1] = 0;
        dimensions[1][1] = 2;
    }
    else if (j < 6)
    {
        dimensions[0][1] = 3;
        dimensions[1][1] = 5;
    }
    else
    {
        dimensions[0][1] = 6;
        dimensions[1][1] = 8;
    }
    return dimensions;
}
bool checker(vector<vector<int>> arr, int i, int j)
{
    unordered_set<int> duplicate_detector;
    int size_checker;
    for (int x = 0; x < 9; x++)
    {
        size_checker = duplicate_detector.size();
        duplicate_detector.insert(arr[x][j]);
        if (size_checker == duplicate_detector.size() && arr[x][j] != 0)
            return false;
    }
    duplicate_detector.clear();
    for (int x = 0; x < 9; x++)
    {
        size_checker = duplicate_detector.size();
        duplicate_detector.insert(arr[i][x]);
        if (size_checker == duplicate_detector.size() && arr[i][x] != 0)
            return false;
    }
    duplicate_detector.clear();
    vector<vector<int>> dimensions(2, vector<int>(2));
    dimensions = get_dimensions(i, j);
    for (int x = dimensions[0][0]; x <= dimensions[1][0]; x++)
    {
        for (int y = dimensions[0][1]; y <= dimensions[1][1]; y++)
        {
            size_checker = duplicate_detector.size();
            duplicate_detector.insert(arr[x][y]);
            if (size_checker == duplicate_detector.size() && arr[x][y] != 0)
                return false;
        }
    }
    return true;
}

void solve(int index, vector<vector<int>> arr)
{
    if (index == vp.size() || done)
    {
        if (done == false)
        {
            for (int a = 0; a < 9; a++)
            {
                for (int b = 0; b < 9; b++)
                {
                    cout<< arr[a][b]<<" ";
                }
            }
            done = true;
        }
        exit(0);
       // return;
    }
    int i = vp[index].first;
    int j = vp[index].second;
    for (int x = 1; x <= 9; x++)
    {
        arr[i][j] = x;
        if (checker(arr, i, j))
        {
            solve(index + 1, arr);
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false),cin.tie(0);
    int t;
    //cin >> t;
    t=1;
    while (t--)
    {
       // vp.clear();
        done=false;
        vector<vector<int>> arr(9, vector<int>(9));
        for (int i = 0; i < 9; i++)
        {
            /*string temp;
            cin >> temp;*/
            for (int j = 0; j < 9; j++)
            {
                //arr[i][j] = temp[j] - '0';
                cin>>arr[i][j];
                if (arr[i][j] == 0)
                    vp.push_back(make_pair(i, j));
            }
        }
        solve(0, arr);
        /*for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << result[i][j];
                cout<<" ";
            }
            cout << endl;
        }
        cout<<endl;*/
    }
    return 0;
}