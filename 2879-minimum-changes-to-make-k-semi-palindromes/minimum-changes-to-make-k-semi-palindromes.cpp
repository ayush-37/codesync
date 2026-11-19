class Solution {
public:
    string s;
    int n;
    vector<vector<int>> memo;
    vector<vector<int>> cost;
    int solve(int start, int k){
        if(k == 0 && start < n)return INT_MAX;

        if(start == n){
            if(k == 0)return 0;
            else return INT_MAX;
        }

        if(start + 2*k > n)return INT_MAX;

        if(memo[start][k] != -1)return memo[start][k];

        int ans = INT_MAX;
        for(int end = start + 1; end < n; end++){
            int nxt = solve(end+1,k-1);
            if(nxt == INT_MAX)continue;
            ans = min(ans , nxt + getCost(start, end));
        }

        return memo[start][k] = ans;
    }

    int getCost(int l, int r){
        int len = r - l + 1;

        if(cost[l][r] != -1)
            return cost[l][r];

        int ans = INT_MAX;

        for(int i = 1; i <= len/2; i++){
            if(len % i != 0) continue;

            int curr = 0;

            for(int j = l; j < l+i; j++){
                int st = j;
                int en = j + ((len/i)-1)*i;

                while(st < en){
                    if(s[st] != s[en])
                        curr++;

                    st += i;
                    en -= i;
                }
            }

            ans = min(ans, curr);
        }

        return cost[l][r] = ans;
    }
    
    int minimumChanges(string str, int k) {
        s = str;
        n = s.size();
        memo.resize(n+1,vector<int>(k+1,-1));
        cost.resize(n+1,vector<int>(n+1,-1));
        return solve(0,k);
    }
};