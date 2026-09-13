class Solution {
/*
Each color can only be printed once, so its printed rectangle must cover all occurrences of that color. Therefore, every color has a fixed bounding rectangle determined by its minimum/maximum row and column.

If another color appears inside this rectangle, then the current color must be printed before that other color. Otherwise, printing the current color later would overwrite the other color.

This naturally forms a dependency graph between colors:

Node = Color
Edge A -> B means A must be printed before B
If these dependencies contain a cycle, no valid printing order exists. Otherwise, a topological ordering gives a valid sequence of prints.

*/
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        unordered_map<int,vector<int>> mp;
        int n = targetGrid.size(), m = targetGrid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int col = targetGrid[i][j];
                if(mp.find(col) == mp.end()){
                    mp[col] = {i,i,j,j};
                }
                else{
                    mp[col][0] = min(mp[col][0], i);
                    mp[col][1] = max(mp[col][1], i);
                    mp[col][2] = min(mp[col][2], j);
                    mp[col][3] = max(mp[col][3], j);
                }
            }
        }

        vector<vector<int>> graph(61);
        vector<vector<int>> isEdge(61, vector<int>(61,0));

        for(auto [curr, v] : mp){
            int mnr = v[0], mxr = v[1], mnc = v[2], mxc = v[3];

            for(int i = mnr; i <= mxr; i++){
                for(int j = mnc; j <= mxc; j++){
                    int col = targetGrid[i][j];
                    if(curr != col && isEdge[curr][col] == 0){
                        graph[curr].push_back(col);
                        isEdge[curr][col] = 1;
                    }
                }
            }
        }

        int totCol = mp.size();

        vector<int> deg(61,0);
        for(int i = 1; i <= 60; i++){
            for(int nbr: graph[i]){
                deg[nbr]++;
            }
        }
        
        queue<int> q;
        for(auto [node, _]: mp)if(deg[node] == 0)q.push(node);

        int processCol = 0;
        while(!q.empty()){
            int col = q.front();
            q.pop();
            processCol++;
            for(auto nbr: graph[col]){
                deg[nbr]--;
                if(deg[nbr] == 0)q.push(nbr);
            }
        }

        return totCol == processCol;
    }
};