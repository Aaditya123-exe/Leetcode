class Solution {
public:
    int minimumTime(int n, vector<vector<int>>&course, vector<int>& time) {
        vector<vector<int>>adjList(n);
        vector<int>inDegree(n),cTime(n,0);
        for(int i=0;i<course.size();i++)
        {
            adjList[course[i][0]-1].push_back(course[i][1]-1);
            inDegree[course[i][1]-1]++;
        }
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            if(!inDegree[i])
            {
                q.push({i,0});
            }
        }
        while(!q.empty())
        {
            int node=q.front().first;
            int t=q.front().second;
            q.pop();
            int completionTime=t+time[node];
            cTime[node]=completionTime;
            for(int i=0;i<adjList[node].size();i++)
            {
                cTime[adjList[node][i]]=max(cTime[adjList[node][i]],completionTime);
                if(!--inDegree[adjList[node][i]])
                    q.push({adjList[node][i],cTime[adjList[node][i]]});
            }
        }
        return *max_element(cTime.begin(),cTime.end());
    }
};