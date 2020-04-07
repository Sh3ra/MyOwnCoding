#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long common_tag(vector  <pair<vector<string>,int > > horizontal,vector <pair<vector<string>,pair<int,int> > >verticalresult,pair<int,int>index,long long j,int vtype)
{

    }
}
long long tag12(vector  <pair<vector<string>,int > > horizontal,vector <pair<vector<string>,pair<int,int> > >verticalresult,pair<int,int>index,long long j,int vtype)
{

}
long long tag21(vector  <pair<vector<string>,int > > horizontal,vector <pair<vector<string>,pair<int,int> > >verticalresult,pair<int,int>index,long long j,int vtype)
{

}

long long  get_interest(pair<int,int>index,long long j,vector  <pair<vector<string>,int > > horizontal,vector <pair<vector<string>,pair<int,int> > >verticalresult,int vtype,bool a1[],bool a2[])
{
    if (vtype==1)
    {
        if(a1[j]==false)

        {
            long long min1=min(common_tag(horizontal,verticalresult,index,j,vtype),tag12(horizontal,verticalresult,index,j,vtype));
            return min(min1,tag21(horizontal,verticalresult,index,j,vtype));

        }

    }
    else
    {
        if(a2[j]==false)

        {
            long long min1=min(common_tag(horizontal,verticalresult,index,j,vtype),tag12(horizontal,verticalresult,index,j,vtype));
            return min(min1,tag21(horizontal,verticalresult,index,j,vtype));

        }

    }
}

int main(int argc, char const *argv[])
{
    vector  <pair<vector<string>,int > >  horizontal;
    vector <pair<vector<string>,pair<int,int> > > verticalresult;
    long long max_interset=-1;
    pair <int,int> max_index;
    bool a1[horizontal.size()]={false},a2[verticalresult.size()]={false};
    long long photo_no=horizontal.size()+verticalresult.size();
    pair<int,int>index;
    index.first=0;
    index.second=1;

    while(photo_no-->0)
    {
        max_interset=-1;
    for (long long j=0;j<horizontal.size();j++)
        {
            if(get_interest(index,j,horizontal,verticalresult,1,a1,a2)>max_interset)
            {
                max_interset=get_interest(index,j,horizontal,verticalresult,1,a1,a2);
                max_index.first=j;
                max_index.second=1;

            }

        }for (long long j=0;j<verticalresult.size();j++)
        {
            if(get_interest(index,j,horizontal,verticalresult,2,a1,a2)>max_interset)
            {
                max_interset=get_interest(index,j,horizontal,verticalresult,2,a1,a2);
                max_index.first=j;
                max_index.second=2;

            }

        }
        print_id(index);
        if(index.second==2)
        {
            a2[index.first]=true;
        }if(index.second==1)
        {
            a1[index.first]=true;
        }
        index=max_index;

    }

    return 0;
}
