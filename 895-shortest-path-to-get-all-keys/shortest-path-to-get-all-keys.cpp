class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();

        map<char, int> keyToIndex;
        int cnt = 0, sr = -1, sc = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '@')sr = i, sc = j;
                else if(grid[i][j] >= 'a' && grid[i][j] <= 'z'){
                    if(keyToIndex.count(grid[i][j]) == 0){
                        keyToIndex[grid[i][j]] = cnt;
                        cnt++;
                    }
                }
            }
        }

        if(cnt == 0)return 0;

        vector<vector<vector<int>>> best(n,vector<vector<int>>(m,vector<int>(1<<cnt, INT_MAX)));
        vector<int> dir = {-1,0,1,0,-1};
        struct State{
            int cx, cy, cmsk, cmov;
        };

        queue<State> q;
        q.push({sr,sc,0,0});
        best[sr][sc][0] = 0;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto cur = q.front();
                q.pop();
                int x = cur.cx, y = cur.cy, msk = cur.cmsk, mov = cur.cmov;

                if(msk == (1<<cnt) - 1)return mov;

                for(int i = 0; i < 4; i++){
                    int nx = x + dir[i], ny = y + dir[i+1];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;

                    int nmsk = msk, nmov = mov+1;
                    if(grid[nx][ny] == '#')continue;
                    else if(grid[nx][ny] >= 'a' && grid[nx][ny] <= 'z'){
                        nmsk |= (1 << keyToIndex[grid[nx][ny]]);
                    }
                    else if(grid[nx][ny] >= 'A' && grid[nx][ny] <= 'Z'){
                        char c = ('a' + (grid[nx][ny] - 'A'));
                        int bitOn = (nmsk >> keyToIndex[c]) & 1;
                        if(!bitOn)continue;
                    }

                    if(nmov >= best[nx][ny][nmsk])continue;
                    best[nx][ny][nmsk] = nmov;

                    q.push({nx,ny,nmsk,nmov});
                }
            }
        }

        return -1;
    }
};