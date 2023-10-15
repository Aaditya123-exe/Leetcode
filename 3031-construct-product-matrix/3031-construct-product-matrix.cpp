class Solution {
#define ll long long
public:
    int mod=12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,1));
        vector<vector<int>>pre(n,vector<int>(m,1));
        vector<vector<int>>suf(n,vector<int>(m,1));
        ll p=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                pre[i][j]=p;
                p*=grid[i][j];
                p%=mod;
            }
        }
        p=1;
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                suf[i][j]=p;
                p*=grid[i][j];
                p%=mod;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                long long mul=pre[i][j]*suf[i][j];
                ans[i][j]=mul%mod;
            }
        }
        return ans;
    }
};