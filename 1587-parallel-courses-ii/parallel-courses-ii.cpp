class Solution {
public:
    vector<vector<int>> graph;
    vector<int> memo;
    int sub, limit, tot; 

    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        sub = n, limit = k;

        // graph[u] contains all courses that depend on course u.
        // If u -> v, then u must be completed before v.
        graph.clear();
        graph.resize(n);

        for(auto x: relations){
            int u = x[0]-1, v = x[1]-1;
            graph[u].push_back(v);
        }

        // We use a bitmask to represent which courses are completed.
        // For example, if n = 4:
        // mask = 0101 means courses 0 and 2 are already completed.
        // tot = 1111 means all courses are completed.
        tot = (1 << n) - 1;

        // memo[mask] = minimum semesters required to complete
        // all remaining courses when 'mask' courses are already completed.
        memo.assign(tot+1,-1);

        return solve(0);
    }

    int solve(int msk){

        // Base case:
        // If all courses are completed, no more semesters are required.
        if(msk == tot)return 0;

        // If we have already solved this state, return the stored answer.
        if(memo[msk] != -1)return memo[msk];

        // deg[i] represents the number of prerequisites of course i
        // that are still not completed.
        // We calculate this only for the current state because some prerequisites may already be present in 'msk'.
        vector<int> deg(sub,0);

        for(int i = 0; i < sub; i++){

            // If course i is already completed, we don't need to consider its outgoing dependencies.
            if((msk >> i) & 1)continue;

            // Every course j that depends on i currently has one prerequisite: i.
            for(auto j: graph[i]){
                deg[j]++;
            }
        }

        // temp will store all courses that are currently available,
        // i.e. courses whose prerequisites have already been completed.
        // We represent these available courses using another bitmask.
        int temp = 0, cnt = 0;

        for(int i = 0; i < sub; i++){

            // Course i must:
            // 1. Not already be completed
            // 2. Have no remaining prerequisite
            // Such a course can be taken in the current semester.
            if(!((msk >> i) & 1) && deg[i] == 0){

                // Mark course i as available.
                temp |= (1<<i);

                cnt++;
            }
        }

        // ans stores the minimum number of semesters from this state.
        int ans = sub+1;

        // If the number of currently available courses is <= k,
        // we can take ALL of them in this semester.
        // There is no reason to take fewer because all of them are currently available and taking an additional course doesn't prevent us from taking another course.
        
        if(cnt <= limit){
            // We spend 1 semester taking all available courses.
            // Then recursively solve the remaining courses.
            ans = min(ans, 1 + solve(msk|temp));
        }
        else{

            // More than k courses are available.
            // We cannot take all of them because at most k courses can be taken in one semester.
            // Therefore, we must try every possible subset of 'temp' containing exactly k courses.
            // ((nmsk - 1) & temp) generates all subsets of temp.
            for(int nmsk = temp; nmsk ; nmsk = (nmsk-1) & temp){

                // We only want subsets containing exactly k courses.
                int currCnt = __builtin_popcount(nmsk);

                if(currCnt != limit)continue;

                // Take this subset of courses in the current semester.
                // nmsk | msk = new set of completed courses.
                // +1 because we just used one semester.
                
                ans = min(ans, 1 + solve(nmsk|msk));
            }
        }

        // Store the answer for this mask so that if we reach
        // the same state again, we don't recompute it.
        return memo[msk] = ans;
    }
};