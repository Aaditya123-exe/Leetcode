class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int threshold=nums.size()/3;
        for(auto &val:mp)
        {
            int ele=val.first;
            int cnt=val.second;
            if(cnt>threshold)
                ans.push_back(ele);
        }
        return ans;
    }
};