#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int a,m;
    cin>>a>>m;
    if(s.size()%a==0)
    {
        cout<<"Yes"<<endl;
        cout<<s.size()/a<<endl;
        for(int i=0; i<s.size(); i++)
        {
            if(i%a==0&&i!=0)
                cout<<endl;
            cout<<s[i];
        }
    }

    else if(s.size()%m==0)
    {
        cout<<"Yes"<<endl;
        cout<<s.size()/m<<endl;
        for(int i=0; i<s.size(); i++)
        {
            if(i%m==0&&i!=0)
                cout<<endl;
            cout<<s[i];
        }
    }

    else if(a+m<=s.size())
    {
        bool check=false;
        int x=1,y=1;
        while(1)
        {
            if(check)
                break;
            y=1;
            if(a*x>s.size())
                break;

            while(1)
            {

                if(a*x+m*y==s.size())
                {
                    check=true;
                    break;

                }
                else if(a*x+m*y>s.size())
                {
                    break;
                }
                else
                    y++;
            }
            if(!check)
                x++;

        }
        if(check)
        {
            int w=0;
            cout<<"Yes"<<endl;
            cout<<x+y<<endl;
            for(int i=0;i<x;i++)
            {
                for(int j=0;j<a;j++)
                {
                    cout<<s[w];
                    w++;
                }
                    cout<<endl;
            }
            for(int i=0;i<y;i++)
            {
                for(int j=0;j<m;j++)
                {
                    cout<<s[w];
                    w++;
                }
                    if(i!=y-1)cout<<endl;
            }
        }
        else
            cout<<"No";
    }
    else
        cout<<"No";
    return 0;
}
