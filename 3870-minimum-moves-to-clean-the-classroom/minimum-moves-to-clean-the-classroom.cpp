/*
    Time Complexity:
    O(n * m * 2^L * E)

    L = number of litter cells
    E = maximum energy

    For every (x, y, mask), we may update the state
    multiple times as we find better energy values.
    Each state checks 4 directions.

    Space Complexity:
    O(n * m * 2^L + n * m)

    best -> O(n * m * 2^L)
    BFS queue -> O(n * m * 2^L) in the worst case
*/

class Solution {
public:
    int n, m, fullMsk;

    // Maps each litter position to a unique ID for bitmasking.
    map<pair<int,int>, int> mp;

    // Represents current position, collected litter mask, and remaining energy.
    struct State {
        int cx, cy, cmsk, ce;

        State(int x, int y, int msk, int e) {
            cx = x, cy = y, cmsk = msk, ce = e;
        }
    };

    int minMoves(vector<string>& classroom, int energy) {

        int cnt = 0;
        int sr = -1, sc = -1;

        n = classroom.size();
        m = classroom[0].size();

        // Assign each litter a unique bit index and find the starting cell.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(classroom[i][j] == 'L') {
                    mp[{i,j}] = cnt++;
                }
                else if(classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
            }
        }

        // No litter means no moves are needed.
        if(cnt == 0)
            return 0;

        // best[x][y][mask] = maximum energy reached at this state.
        vector<vector<vector<int>>> best(
            n,
            vector<vector<int>>(
                m,
                vector<int>(1 << cnt, -1)
            )
        );

        // Example: cnt=3 -> fullMsk=111, meaning all litter is collected.
        fullMsk = (1 << cnt) - 1;

        // Four movement directions: up, right, down, left.
        vector<int> dir = {-1, 0, 1, 0, -1};

        // BFS state: row, column, collected litter mask, remaining energy.
        queue<State> q;

        State source(sr, sc, 0, energy);
        q.push(source);

        // Initially, no litter is collected and energy is full.
        best[sr][sc][0] = energy;

        int mov = 0;

        while(!q.empty()) {

            // Process all states having the same number of moves.
            int sz = q.size();

            while(sz--) {

                auto curr = q.front();
                q.pop();

                int x = curr.cx;
                int y = curr.cy;
                int msk = curr.cmsk;
                int e = curr.ce;

                // BFS guarantees this is the minimum number of moves.
                if(msk == fullMsk)
                    return mov;

                // No energy means we cannot move further.
                if(e == 0)
                    continue;

                for(int i = 0; i < 4; i++) {

                    int nx = x + dir[i];
                    int ny = y + dir[i + 1];

                    // Ignore cells outside the classroom.
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;

                    // Walls cannot be entered.
                    if(classroom[nx][ny] == 'X')
                        continue;

                    // Every move consumes one unit of energy.
                    int ne = e - 1;

                    // Start with the same collected-litter mask.
                    int nmsk = msk;

                    // Turn ON the bit corresponding to this litter.
                    if(classroom[nx][ny] == 'L') {
                        int id = mp[{nx, ny}];
                        nmsk |= (1 << id);
                    }

                    // Recharge cells restore energy to the maximum.
                    if(classroom[nx][ny] == 'R') {
                        ne = energy;
                    }

                    // Same state with more energy is useful; otherwise skip.
                    if(ne <= best[nx][ny][nmsk])
                        continue;

                    // Store the best energy seen for this position and mask.
                    best[nx][ny][nmsk] = ne;

                    // Add the improved state to BFS.
                    State newState(nx, ny, nmsk, ne);
                    q.push(newState);
                }
            }

            // Move to the next BFS level.
            mov++;
        }

        // No valid path can collect all litter.
        return -1;
    }
};
