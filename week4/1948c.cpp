#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    
    vector<vector<char>> grid(2, vector<char>(n));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];
    
    // Visited 
    vector<vector<bool>> visited(2, vector<bool>(n, false));
    
    // BFS queue: stores (row, col)
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;
    
    while (!q.empty()) {
        pair<int, int> curr = q.front(); 
        q.pop();
        
        int x = curr.first;  
        int y = curr.second;
        
        // Try all possible free moves: up, down, left, right
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < directions.size(); i++) { 
            int dx = directions[i].first;
            int dy = directions[i].second;
            
            // Check if the free move is within the grid
            int newX = x + dx;
            int newY = y + dy;
            
            if (newX >= 0 && newX < 2 && newY >= 0 && newY < n) {
                // After the free move, follow the arrow in the new cell
                int nextX = newX;
                int nextY = newY;
                if (grid[newX][newY] == '>') {
                    nextY++;
                } else if (grid[newX][newY] == '<') {
                    nextY--;
                }
                
                // Check if the arrow move is valid and the resulting cell is unvisited
                if (nextY >= 0 && nextY < n && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    q.push({nextX, nextY});
                }
            }
        }
    }
    
    // Check if the target cell (2, n) (0-based: 1, n-1) is reachable
    if (visited[1][n-1]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) solve();
    
    return 0;
}
