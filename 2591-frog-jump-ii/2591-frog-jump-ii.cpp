class Solution
{
public:
    bool check(int maxJump, vector<int> &stones)
    {
        vector<int> g;
        g.push_back(0);
        int i = 1, n = stones.size();
        while (i < n)
        {
            if (stones[i] - stones[g.back()] > maxJump)
            {
                if (i - 1 != g.back())
                    g.push_back(i - 1);
                else
                    return false;
            }
            else
                i++;
        }
        int c = n - 1;
        i = n - 2;
        while (i >= 0)
        {
            if (g.back() == i && i != 0)
            {
                i--;
                g.pop_back();
            }
            else
            {
                if (stones[c] - stones[i] > maxJump)
                    return false;
                else
                {
                    c = i;
                    i--;
                }
            }
        }
        return true;
    }
    int maxJump(vector<int> &stones)
    {
        int l = 1, r = 1e9;
        int ans = 1e9;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (check(mid, stones))
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};