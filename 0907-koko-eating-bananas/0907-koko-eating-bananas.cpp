class Solution {
public:
    bool check(vector<int>& piles, long long int h, long long int limit)
    {
        long long int hrs = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            long long int curr = piles[i] / limit;
            curr += (piles[i] % limit == 0) ? 0 : 1;
            hrs += curr;
        }
        return hrs <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int low = 1;
        long long int high = accumulate(piles.begin(), piles.end(), 0LL); // Use 0LL to ensure long long int
        long long int limit = 0;
        while (low <= high)
        {
            long long int mid = (low + (high - low) / 2);
            if (check(piles, static_cast<long long int>(h), mid))
            {
                high = mid - 1;
                limit = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return static_cast<int>(limit); // Cast back to int
    }
};
