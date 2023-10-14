class Solution
{
public:
    int solve(vector<int>&cost,vector<int>&time,int idx,int size,vector<vector<int>>&dp)
    {
        if(size<=0)
            return 0;
        if(idx>=cost.size())
            return 1e9;
        if(dp[idx][size]!=-1)
            return dp[idx][size];
        int nottake=solve(cost,time,idx+1,size,dp);
        int take=cost[idx]+solve(cost,time,idx+1,size-1-time[idx],dp);
        return dp[idx][size]=min(nottake,take);
    }
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        vector<vector<int>> dp(501,vector<int>(501,-1));
        return solve(cost,time,0,time.size(),dp);
    }
};