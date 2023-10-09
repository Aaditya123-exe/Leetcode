#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
    XOR of all elements will give single element
    TC:O(n)
    */
    /*
    based on indexes
    before single elements first occ of every ele comes in even position
    after single elements first occ of every ele comes at odd pos
    eg: 3 3 4 4 5 5 6 6 8 8 9  10 10 12 12 14 14
    find mid and if the mid is odd then check its prev element nd see if both matches then this number appears before single numbe
    */
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (mid & 1)
            {
                if (nums[mid - 1] == nums[mid])
                {
                    low = mid + 1;
                }
                else
                    high = mid;
            }
            else
            {
                if (mid + 1 < n && nums[mid] == nums[mid + 1])
                {
                    low = mid + 1;
                }
                else if (mid - 1 >= 0 && nums[mid] == nums[mid - 1])
                {
                    high = mid - 1;
                }
                else
                    return nums[mid];
            }
        }
        return 0;
    }
};