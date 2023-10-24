#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
    check fuel for each index
    fuel+=gas[i]-cost[i]
    if at any index fuel<0 then it indicates that its not possible to travel all station from any index from 0 to i
    so set start index to i+1 and check again
    */
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalCost = 0, fuel = 0, start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            totalCost += gas[i] - cost[i];
            fuel += gas[i] - cost[i];
            if (fuel < 0)
            {
                fuel = 0;
                start = i + 1;
            }
        }
        if (totalCost < 0)
            return -1;
        return start;
    }
};