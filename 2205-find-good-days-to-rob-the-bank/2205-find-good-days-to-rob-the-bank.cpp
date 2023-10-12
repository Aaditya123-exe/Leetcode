class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n=security.size();
        vector<int>prefix(n);
        vector<int>suffix(n);
        prefix[0]=1;
        int prev=security[0];
        for(int i=1;i<n;i++)
        {
            if(prev>=security[i])
            {
                prefix[i]=1+prefix[i-1];
            }
            else
                prefix[i]=1;
            prev=security[i];
        }
        int next=security[n-1];
        suffix[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            if(next>=security[i])
            {
                suffix[i]=1+suffix[i+1];
            }
            else
                suffix[i]=1;
            next=security[i];
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if((prefix[i]-1>=time)&&(suffix[i]-1)>=time)
                ans.push_back(i);
        }
        return ans;
    }
};