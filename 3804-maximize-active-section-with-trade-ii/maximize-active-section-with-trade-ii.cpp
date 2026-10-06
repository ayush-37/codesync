class Solution {
public:
    vector<int> seg;
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        vector<int> sblock, eblock, zeros;
        int i = 0;
        int sz = s.size(), qn = queries.size();

        vector<int> pref(sz+1,0);
        for(int i = 0; i < sz; i++)pref[i+1] = pref[i] + (s[i] == '1');

        while(i < s.size()){
            if(s[i] == '0'){
                sblock.push_back(i);
                while(i < s.size() && s[i] == '0')i++;
                eblock.push_back(i-1);
                zeros.push_back(eblock.back() - sblock.back() + 1);
            }
            else{
                i++;
            }
        }

        vector<int> pairSum, ans(qn,0);
        for(int i = 1; i < zeros.size(); i++){
            pairSum.push_back(zeros[i] + zeros[i-1]);
        }

        int n = pairSum.size();

        if(n == 0){
            for(int i = 0; i < qn; i++){
                // ans[i] = pref[queries[i][1] + 1] - pref[queries[i][0]];
                ans[i] = pref.back();
            }

            return ans;
        }

        seg.assign(4*n, 0);

        build(0,0,n-1,pairSum);

        for(int i = 0; i < qn; i++){
            int l = queries[i][0], r = queries[i][1];

            // ans[i] = pref[r+1] - pref[l];
            ans[i] = pref.back();

            int bstart = lower_bound(eblock.begin(), eblock.end(), l) - eblock.begin();
            int bend = upper_bound(sblock.begin(), sblock.end(), r) - sblock.begin() - 1;

            // No zero block inside [l,r]
            if(bstart > bend)
                continue;

            // Only one zero block inside [l,r]
            // Cannot perform a trade
            if(bstart == bend)
                continue;
                
            int startingZero = eblock[bstart] - max(l, sblock[bstart]) + 1;
            int trailingZero = min(r,eblock[bend]) - sblock[bend] + 1;

            if(bend - bstart + 1 == 2){
                ans[i] += (startingZero + trailingZero);
                continue;
            }

            int pair1 = startingZero + zeros[bstart+1], pair2 = trailingZero + zeros[bend-1];

            int pair3 = find(bstart+1, bend-2, 0, 0, n-1);

            int tot = max({pair1, pair2, pair3});
            ans[i] += tot;
        }

        return ans;
    }

    void build(int idx, int l, int r, vector<int>& pairSum){
        if(l == r){
            seg[idx] = pairSum[l];
            return;
        }

        int mid = l + (r-l)/2;

        build(2*idx+1, l, mid, pairSum);
        build(2*idx+2, mid+1, r, pairSum);

        seg[idx] = max(seg[2*idx+1], seg[2*idx+2]);
    }

    int find(int start, int end, int idx, int l, int r){
        if(l > end || r < start)return 0;

        if(l >= start && r <= end)return seg[idx];

        int mid = l + (r-l)/2;

        int left = find(start, end, 2*idx+1, l, mid);
        int right = find(start, end, 2*idx+2, mid+1, r);

        return max(left, right);
    }
};