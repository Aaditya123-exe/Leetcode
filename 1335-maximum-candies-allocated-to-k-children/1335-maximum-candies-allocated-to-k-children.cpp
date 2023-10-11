class Solution {
public:
    bool check(vector<int>& candies,long long int limit,long long int mid)
    {
        unordered_map<long long int,long long int>mp;
        for(int i=0;i<candies.size();i++)
        {
            long long int curr=candies[i]/mid;
            long long int rem=candies[i]%mid;
            mp[mid]+=curr;
            mp[rem]++;
        }
        if(mp[mid]>=limit)
            return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long int low=1,high=*max_element(candies.begin(),candies.end());
        int num=0;
        while(low<=high)
        {
            long long int mid=low+(high-low)/2;
            if(check(candies,k,mid))
            {
                low=mid+1;
                num=mid;
            }
            else
                high=mid-1;
        }
        return num;
    }
};