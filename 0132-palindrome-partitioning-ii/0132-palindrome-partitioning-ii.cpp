class Solution {
public:
    bool valid(string&prefix, int i, int j)
    {

        while (i < j)
        {
            if (prefix[i] != prefix[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string str)
    {
        int n = str.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int minCost = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (valid(str, i, j))
                {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }
};