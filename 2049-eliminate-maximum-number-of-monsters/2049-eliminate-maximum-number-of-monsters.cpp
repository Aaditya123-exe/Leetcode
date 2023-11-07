class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<int>time;
        for(int i=0;i<dist.size();i++)
        {
            time.push_back((dist[i]/speed[i])+((dist[i]%speed[i])>0?1:0));
        }
        sort(time.begin(),time.end());
        int count=1;
        int t=1;
        for(int i=1;i<time.size();i++)
        {
            time[i]-=t;
            t++;
            if(time[i]>0)
                count++;
            else
                break;
        }
        return count;
    }
};