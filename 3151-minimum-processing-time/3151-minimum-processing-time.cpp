#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks)
    {
        sort(processorTime.begin(), processorTime.end(), greater<int>());
        sort(tasks.begin(), tasks.end());
        int ans = 0;
        int curr = 0;
        int j = 0;
        for (int i = 0; i < tasks.size(); i++)
        {
            if (i % 4 == 0&&i!=0)
            {
                ans = max(curr, ans);
                j++;
                curr = processorTime[j] + tasks[i];
            }
            else
            {
                curr = max(processorTime[j] + tasks[i], curr);
            }
        }
        ans = max(curr, ans);
        return ans;
    }
};