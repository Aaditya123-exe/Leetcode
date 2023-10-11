class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
       vector<int>start,end;
        for(int i=0;i<flowers.size();i++)
        {
            start.push_back(flowers[i][0]);
            end.push_back(flowers[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        vector<int>res;
        for(int i=0;i<people.size();i++)
        {
            int idx=people[i];
            int started=upper_bound(start.begin(),start.end(),idx)-start.begin();
            int ended=lower_bound(end.begin(),end.end(),idx)-end.begin();
            res.push_back(started-ended);
        }
        return res;
    }
};