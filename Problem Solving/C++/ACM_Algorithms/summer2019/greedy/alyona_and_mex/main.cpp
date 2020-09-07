    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
     
    int main()
    {
        int n,m,mex;
        cin >> n >> m;
        bool filled [n]= {false};
        priority_queue<pair<int,int>>indexer;
        vector<pair<int,int>>LR;
        int arr[n];
        std::fill_n(arr, n, 1000000000);
        for(int i=0; i<m; i++)
        {
            int l,r;
            cin >>l >>r;
            if(i==0)
            {
                mex=r-l;
            }
            else
            {
                if(mex>r-l)
                {
                    mex=r-l;
                }
            }
            LR.push_back(make_pair(l-1,r-1));
            indexer.push(make_pair(l-r,i));
        }
     
        for(int i=0;i<n;i++)
        {
            arr[i]=i%(mex+1);
        }
        cout << mex+1<<endl;
        for(int i=0;i<n;i++)cout << arr[i] <<" ";
        return 0;
    }