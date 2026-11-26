class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses, 0);
        for(int i=0; i<prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegrees[prerequisites[i][0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(indegrees[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int& course: adj[node]) {
                indegrees[course]--;
                if(indegrees[course]==0) q.push(course);
            }
        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};
