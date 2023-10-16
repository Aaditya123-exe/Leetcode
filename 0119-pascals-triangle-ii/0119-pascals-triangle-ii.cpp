class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>prev(1,1);
        int k=2;
        for(int i=1;i<=rowIndex;i++)
        {
            vector<int>curr(k++,0);
            for(int j=0;j<prev.size();j++)
            {
                curr[j]+=prev[j];
                curr[j+1]+=prev[j];
            }
            prev=curr;
        }
        return prev;
    }
};