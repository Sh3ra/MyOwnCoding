#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int numb(int a[],char x)
{
    switch(x)
    {
        case 'a':return a[0];
        break;
        case 'b':return a[1];
        break;
        case 'c':return a[2];
        break;
        case 'd':return a[3];
        break;
        case 'e':return a[4];
        break;
        case 'f':return a[5];
        break;
        case 'g':return a[6];
        break;
        case 'h':return a[7];
        break;
        case 'i':return a[8];
        break;
        case 'j':return a[9];
        break;
        case 'k':return a[10];
        break;
        case 'l':return a[11];
        break;
        case 'm':return a[12];
        break;
        case 'n':return a[13];
        break;
        case 'o':return a[14];
        break;
        case 'p':return a[15];
        break;
        case 'q':return a[16];
        break;
        case 'r':return a[17];
        break;
        case 's':return a[18];
        break;
        case 't':return a[19];
        break;
        case 'u':return a[20];
        break;
        case 'v':return a[21];
        break;
        case 'w':return a[22];
        break;
        case 'x':return a[23];
        break;
        case 'y':return a[24];
        break;
        case 'z':return a[25];
        break;
    }
    return 0;
}

int main()
{
    int n,threshold;

    cin>>n>>threshold;
    int a[26];
    vector<string>v;
    string temp;
    string temp1;
    for(int i=0;i<26;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        temp1=temp;
        int y=temp.size();
        int sum=0;
        for(int j=0;j<y;j++)
        {
            sum=sum+numb(a,temp.back());
            temp.pop_back();
        }
        if(sum>=threshold)
            v.push_back(temp1);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<endl;


    return 0;
}
