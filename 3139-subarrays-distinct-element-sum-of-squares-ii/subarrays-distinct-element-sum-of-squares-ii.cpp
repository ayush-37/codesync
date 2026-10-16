class Solution {
    static constexpr long long MOD = 1e9 + 7;    // ✅ static constexpr

    struct SegTree {
        int n;
        vector<long long> normal, squared, lazy;

        SegTree(int n) : n(n) {
            normal.assign(4 * n, 0);
            squared.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void apply(int idx, int l, int r, long long val) {
            long long len = r - l + 1;
            squared[idx] = (squared[idx]
                          + 2LL * val % MOD * normal[idx] % MOD
                          + val * val % MOD * len % MOD) % MOD;
            normal[idx] = (normal[idx] + val * len) % MOD;
            lazy[idx] = (lazy[idx] + val) % MOD;
        }

        void push(int idx, int l, int r) {
            if (lazy[idx] == 0 || l == r) return;
            int mid = (l + r) / 2;
            apply(2 * idx + 1, l, mid, lazy[idx]);
            apply(2 * idx + 2, mid + 1, r, lazy[idx]);
            lazy[idx] = 0;
        }

        void update(int idx, int l, int r, int ql, int qr, long long val) {
            if (qr < l || r < ql) return;
            if (ql <= l && r <= qr) {
                apply(idx, l, r, val);
                return;
            }
            push(idx, l, r);
            int mid = (l + r) / 2;
            update(2 * idx + 1, l, mid, ql, qr, val);
            update(2 * idx + 2, mid + 1, r, ql, qr, val);
            normal[idx] = (normal[2 * idx + 1] + normal[2 * idx + 2]) % MOD;
            squared[idx] = (squared[2 * idx + 1] + squared[2 * idx + 2]) % MOD;
        }

        void update(int l, int r, long long val) {
            if (l > r) return;
            update(0, 0, n - 1, l, r, val);
        }

        long long totalSquared() const { return squared[0]; }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        SegTree seg(n);
        unordered_map<int, int> last;
        long long answer = 0;

        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;
            seg.update(prev + 1, i, 1);
            last[nums[i]] = i;
            answer = (answer + seg.totalSquared()) % MOD;
        }

        return (int)answer;
    }
};