class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double mi=-1,ma=-1,sum=0,mo,moC=-1;
        long long cnt=0;
        vector<double>ans;
        for(int i=0;i<count.size();i++)
        {
            if(count[i]!=0)
            {
                if(mi==-1)
                {
                    mi=i;
                }
                ma=i;   
                cnt+=count[i];
                sum+=count[i]*i;
                if(count[i]>moC)
                {
                    mo=i;
                    moC=count[i];
                }
            }
        }
        ans.push_back(mi);
        ans.push_back(ma);
        ans.push_back(sum/cnt);
        if(cnt%2==1)
        {
            long long c=0;
            for(int i=0;i<count.size();i++)
            {
                c+=count[i];
                if((cnt/2)+1<=c)
                {
                    ans.push_back(i);
                    break;
                }
            }
        }
        else {
            long long c=0,c1=(cnt)/2,c2=c1+1;
            double me=-1;
            for(int i=0;i<count.size();i++)
            {
                c+=count[i];
                if(c1<=c&&me==-1)
                {
                    me=i;
                }
                if(c2<=c)
                {
                    me+=i;
                    me/=2;
                    ans.push_back(me);
                    break;
                }
            }
        }
        ans.push_back(mo);
        return ans;
    }
};