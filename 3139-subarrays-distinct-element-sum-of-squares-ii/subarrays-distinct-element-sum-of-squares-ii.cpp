class Solution {
public:
    int n;
    const int MOD = 1e9 + 7;
    vector<int> sq, norm, lazy, last;

    void propagate(int idx, int l , int r, int val){
            int len = r - l + 1;

            sq[idx] = (sq[idx]
            + 2LL * val * norm[idx] % MOD
            + 1LL * val * val % MOD * len) % MOD;

            norm[idx] = (norm[idx] + 1LL * len * val) % MOD;

            if(l != r){
                lazy[2*idx + 1] = (lazy[2*idx + 1] + val) % MOD;
                lazy[2*idx + 2] = (lazy[2*idx + 2] + val) % MOD;
            }
    }

    void update(int start, int end, int idx, int l, int r, int val){
        if(lazy[idx] != 0){
            propagate(idx, l, r, lazy[idx]);
            lazy[idx] = 0;
        }

        if(l > end || r < start)return;

        if(l >= start && r <= end){
            propagate(idx, l, r, val);
            return;
        }

        int mid = l + (r-l) / 2;

        update(start, end, 2*idx + 1, l, mid, val);
        update(start, end, 2*idx + 2, mid+1, r, val);

        norm[idx] = (norm[2*idx+1] + norm[2*idx+2]) % MOD;
        sq[idx] = (sq[2*idx+1] + sq[2*idx+2]) % MOD;

    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sq.assign(4*n,0);
        norm.assign(4*n,0);
        lazy.assign(4*n,0);
        last.assign(1e5+1, -1);
        
        int ans = 0;
        for(int i = 0; i < n; i++){
            int start = last[nums[i]] + 1;
            int end = i;
            update(start, end, 0, 0, n-1, 1);
            ans = (ans + sq[0]) % MOD;
            last[nums[i]] = i;
        }

        return ans;
    }
};