class Solution {
public:

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        //create adjList
        unordered_map<int, list<pair<int, int>> >adjList;
        for(int i=0; i<flights.size(); i++){
            int u = flights[i][0];  int v = flights[i][1];
            int w = flights[i][2];

            adjList[u].push_back({v, w});
        }

        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue< pair< int, pair<int, int> > > q;  // stop, node, cost from src to node
        
        q.push({0, {src, 0}});

        // dijakstra algo
        while(!q.empty()){
            auto top = q.front();
            q.pop();
        
            int edgeW = top.second.second;  // cost btw src and top
            int stops = top.first;   // all nbr of top will get same stop as they are on same level below src
            for(auto nbr : adjList[top.second.first]){
                if(stops > k) continue;

                if( edgeW + nbr.second < dist[nbr.first]){    // nbr.second = cost btw top and nbr   src --> top --> nbru 
                    dist[nbr.first] = nbr.second + edgeW;
                    q.push({stops+1, {nbr.first, dist[nbr.first]}});
                }
            }
        }
        if(dist[dst] == 1e9){
            return -1;
        }
        return dist[dst];
        
       
    }
};
