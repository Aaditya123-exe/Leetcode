class Solution {
public:
    int arrangeCoins(int n) {
        long l=1,r=n;
        long ans=1;
        while(l<=r)
        {
            long mid=(l+r)/2;
            long coin=(mid*(mid+1))/2;
            if(coin<=n)
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};