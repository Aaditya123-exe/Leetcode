#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int group(unordered_map<int, int> &m, int g)
    {
        int ans = 0;
        for (auto i : m)
        {
            int a = i.second;
            if (a < g)
            {
                return 1e9;
            }
            int s = 0;
            s += a / (g + 1);
            a = a % (g + 1);
            if (a != 0 && g - a <= s)
            {
                s++;
            }
            else if (a != 0)
            {
                return 1e9;
            }
            ans += s;
        }
        return ans;
    }
    int minGroupsForValidAssignment(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 1;
        int ans = INT_MAX;
        unordered_map<int, int> m;
        for (auto i : nums)
        {
            m[i]++;
        }
        int mn = INT_MAX;
        for (auto i : m)
            mn = min(mn, i.second);
        for (int i = 1; i <= mn; i++)
        {
            ans = min(ans, group(m, i));
        }
        return ans;
    }
};