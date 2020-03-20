#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct line
{
    int x1;
    int y1;
    int x2;
    int y2;
    int lenght;
};

bool fun(int arr[], line a, line b, line c, bool first)
{
    a.x1 = arr[0];
    a.y1 = arr[1];
    a.x2 = arr[2];
    a.y2 = arr[3];
    b.x1 = arr[2];
    b.y1 = arr[3];
    b.x2 = arr[4];
    b.y2 = arr[5];
    c.x1 = arr[0];
    c.y1 = arr[1];
    c.x2 = arr[4];
    c.y2 = arr[5];
    a.lenght = (a.x1 - a.x2) * (a.x1 - a.x2) + (a.y1 - a.y2) * (a.y1 - a.y2);
    b.lenght = (b.x1 - b.x2) * (b.x1 - b.x2) + (b.y1 - b.y2) * (b.y1 - b.y2);
    c.lenght = (c.x1 - c.x2) * (c.x1 - c.x2) + (c.y1 - c.y2) * (c.y1 - c.y2);
    priority_queue<int> pq;
    pq.push(a.lenght);
    pq.push(b.lenght);
    pq.push(c.lenght);
    int line1, line2, line3;
    line1 = pq.top();
    pq.pop();
    line2 = pq.top();
    pq.pop();
    line3 = pq.top();
    pq.pop();
    if(!line1||!line2||!line3)return false;
    if (line2 + line3 == line1)
    {
        if (first)
        {
            cout << "RIGHT";
        }
        else
        {
            cout << "ALMOST";
        }
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    line a, b, c;
    int arr[6];
    for (int i = 0; i < 6; i++)
        cin >> arr[i];

    if (fun(arr, a, b, c, 1))
        return 0;
    arr[0]++;
    if (fun(arr, a, b, c, 0))
        return 0;
    arr[0]--;
    arr[0]--;
    if (fun(arr, a, b, c, 0))
        return 0;
    arr[0]++;

    arr[1]++;
    if (fun(arr, a, b, c, 0))
        return 0;
    arr[1]--;
    arr[1]--;
    if (fun(arr, a, b, c, 0))
        return 0;
    arr[1]++;

    arr[2]++;
    if (fun(arr, a, b, c, 0))
        return 0;
    arr[2]--;
    arr[2]--;
    if (fun(arr, a, b, c, 0))
        return 0;
    arr[2]++;

    arr[3]++;
    if (fun(arr, a, b, c, 0))
        return 0;
    arr[3]--;
    arr[3]--;
    if (fun(arr, a, b, c, 0))
        return 0;
    arr[3]++;

    arr[4]++;
    if (fun(arr, a, b, c, 0))
        return 0;
    arr[4]--;
    arr[4]--;
    if (fun(arr, a, b, c, 0))
        return 0;
    arr[4]++;

    arr[5]++;
    if (fun(arr, a, b, c, 0))
        return 0;
    arr[5]--;
    arr[5]--;
    if (fun(arr, a, b, c, 0))
        return 0;
    arr[5]++;

    cout << "NEITHER";
    return 0;
}
