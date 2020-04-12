class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        unordered_map<int,int>num;
        unordered_map<int,int>index;
        for(int i=0;i<=m;i++)
        {
            num[i]=i+1;
            index[i+1]=i;
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            /*for(int w=0;w<=m;w++)
                cout<<w<<"->"<<num[w]<<"  ";
            cout<<endl;
            for(int w=0;w<=m;w++)
                cout<<w<<"->>"<<index[w]<<"  ";
            cout<<endl;*/
            int e=index[queries[i]];
            ans.push_back(e);
            int prev=0;
            for(int j=0;j<=e;j++)
            {
                index[num[j]]++;
                int update=num[j];
                if(j!=0)num[j]=prev;
                prev=update;                
            }
            index[queries[i]]=0;
            num[0]=queries[i];
        }
        return ans;
        
    }
};