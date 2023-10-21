class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            int req=k-nums[i];
            if(mp.find(req)!=mp.end())
            {
                mp[req]--;
                if(mp[req]==0)
                    mp.erase(req);
                cnt++;
            }
            else{
                mp[nums[i]]++;
            }
        }
        return cnt;
    }
};