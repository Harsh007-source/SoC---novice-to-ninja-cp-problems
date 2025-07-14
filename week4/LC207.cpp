class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // create adjList
        unordered_map<int, list<int>> adjList;
        for(int i=0; i<prerequisites.size(); i++){
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            adjList[u].push_back(v);
        }

        vector<int>inDegree(n);
        for(int i=0; i<n; i++){
            for(auto nbr : adjList[i]){
                inDegree[nbr]++;
            }
        }
        stack<int>s;
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0){
                s.push(i);
            }
        }
        vector<int>topo;
        while(!s.empty()){
            int top = s.top();
            topo.push_back(top);
            s.pop();

            for(auto nbr : adjList[top]){
                inDegree[nbr]--;
                if(inDegree[nbr] == 0){
                    s.push(nbr);
                }
            }
        }
        return topo.size() == n;
       
    }
};
