class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]) {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0)
                q.push(i);
        }
        int cnt=0;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            cnt++;
            for(auto it:adj[node]) {
                indegree[it]--;
                if(indegree[it]==0)
                    q.push(it);
            }
        }
        return cnt==numCourses;
    }
};