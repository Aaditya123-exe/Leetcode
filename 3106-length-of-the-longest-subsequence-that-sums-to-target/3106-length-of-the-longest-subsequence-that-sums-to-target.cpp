class Solution
{
public:
    int check(vector<int> &nums, int target, int idx, vector<vector<int>> &dp)
    {
        if (target == 0)
            return 0;
        if (idx >= nums.size() || target < 0)
            return -1e9;
        if (dp[idx][target] != -1)
            return dp[idx][target];
        int take = 1 + check(nums, target - nums[idx], idx + 1, dp);
        int nottake = check(nums, target, idx + 1, dp);
        return dp[idx][target] = max(take, nottake);
    }
    int lengthOfLongestSubsequence(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        int ans = check(nums, target, 0, dp);
        return ans > 0 ? ans : -1;
    }
};