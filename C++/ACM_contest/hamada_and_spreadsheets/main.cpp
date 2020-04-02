#include <iostream>
#include<string>
#include<algorithm>
#include<string.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    while(n!=0)
    {
        string cell,c;
        unsigned int i=0,type=0,r,col_num=0;
        cin>>cell;
        char temp;
        if(cell[0]=='R')
        {
            while(i<cell.size())
            {
                temp=cell[i];
                if(temp>=48&&temp<=57&&i<cell.size()-2)
                    if(cell[i+1]=='C')
                    {
                        type=1;
                        break;
                    }
                i++;
            }
        }
        if(type)
        {
            c=cell.substr(1,i);
            r=stoi(c);
            c.clear();
            c=cell.substr(i+2,cell.size()-1);
            col_num=stoi(c);
            c.clear();
            while(col_num>0)
            {
                c.push_back(col_num%26+64);
                col_num/=26;
            }
            reverse(c.begin(),c.end());
        cout<<c<<r<<endl;
        }
        else
        {
           for(i=0;i<cell.size();i++)
           {
               temp=cell[i];
                if(temp>=48&&temp<=57)break;
           }
           c=cell.substr(i,cell.size()-1);
           r=stoi(c);
           c.clear();
           c=cell.substr(0,i);
           i=1;
           while(!c.empty())
           {
             col_num=col_num+(c.back()-64)*i;
             c.pop_back();
             if(i==1)i+=25;
             else i+=26;
           }
           cout<<"R"<<r<<"C"<<col_num<<endl;

        }


        c.clear();

        n--;
    }
    return 0;
}
