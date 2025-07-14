class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1){
            return{0};
        }
        //create adjList
        unordered_map<int, list<int> >adjList;
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

        vector<int>degree(n);
        for(int i=0; i<n; i++){  // find degree of all nodes
            for(auto nbr : adjList[i]){
                degree[i]++;
            }
        }
        
        queue<int> q;
        for(int i=0; i<n; i++){ // store all node with degree =1
            if(degree[i] ==1){
                q.push(i);
            }
        }

        while(n>2){
            int size = q.size();
            n=n-size; // as nodes with degree = 1 can not be root for min height
            while(size > 0){
                int front = q.front();  // degree =1
                q.pop();
                for(auto nbr : adjList[front]){  // after poping front reduce degree of nodes to which it was pointing
                    degree[nbr]--;
                    if(degree[nbr] == 1){
                        q.push(nbr);
                    }
                }
                size--;
    
            } 
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
        
    }
};
