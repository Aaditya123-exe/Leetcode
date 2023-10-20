#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Return the minimum capability of the robber out of all the possible ways to steal at least k houses.
/*
start from highest value(val)vand check that can we rob atleast k houses and have capability vak
capability is max val out of k houses robbed
k houses should not be adjacent
*/
class Solution
{
public:
    bool check(int mid, vector<int> &nums, int k)
    {
        int cnt = 0;
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] <= mid)
            {
                cnt++;
                i += 2;
            }
            else
                i++;
        }
        return cnt >= k;
    }
    int minCapability(vector<int> &nums, int k)
    {
        int l = *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int val = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (check(mid, nums, k))
            {
                val = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return val;
    }
};