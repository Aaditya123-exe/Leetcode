class Solution {
public:
    bool check(vector<int>&q,int val,int size)
    {
        int cnt=0;
        for(int i=0;i<q.size();i++)
        {
            cnt+=(q[i]/val);
            cnt+=((q[i]%val==0)?0:1);
        }
        return cnt<=size;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        int low=1,high=*max_element(q.begin(),q.end());
        int val=0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(q,mid,n))
            {
                val=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return low;
    }
};