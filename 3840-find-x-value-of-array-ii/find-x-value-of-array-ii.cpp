class Solution {
public:

    struct Node {
        int prod;
        array<long long, 5> rem{};

        Node() {
            prod = 0;
        }

        Node(int val, int k) {
            prod = val % k;
            rem.fill(0);
            rem[prod] = 1;
        }
    };

    struct SegmentTree {
        int n, k;
        vector<Node> seg;

        SegmentTree(int n, int k) {
            this->n = n;
            this->k = k;
            seg.resize(4 * n);
        }

        Node merge(const Node& left, const Node& right) {

            Node curr;

            curr.prod = (1LL * left.prod * right.prod) % k;

            // Prefixes completely inside left
            for(int i = 0; i < k; i++) {
                curr.rem[i] += left.rem[i];
            }

            // Prefixes which take:
            // entire left + prefix of right
            for(int i = 0; i < k; i++) {

                int r = (1LL * left.prod * i) % k;

                curr.rem[r] += right.rem[i];
            }

            return curr;
        }

        void build(int idx, int l, int r, vector<int>& nums) {

            if(l == r) {
                seg[idx] = Node(nums[l], k);
                return;
            }

            int mid = l + (r - l) / 2;

            build(2 * idx + 1, l, mid, nums);
            build(2 * idx + 2, mid + 1, r, nums);

            seg[idx] = merge(
                seg[2 * idx + 1],
                seg[2 * idx + 2]
            );
        }

        void updateRange(
            int index,
            int val,
            int idx,
            int l,
            int r
        ) {

            if(l == r) {
                seg[idx] = Node(val, k);
                return;
            }

            int mid = l + (r - l) / 2;

            if(index <= mid) {
                updateRange(
                    index,
                    val,
                    2 * idx + 1,
                    l,
                    mid
                );
            }
            else {
                updateRange(
                    index,
                    val,
                    2 * idx + 2,
                    mid + 1,
                    r
                );
            }

            seg[idx] = merge(
                seg[2 * idx + 1],
                seg[2 * idx + 2]
            );
        }

        void update(int index, int val) {
            updateRange(index, val, 0, 0, n - 1);
        }

        // Merge "right" after the current accumulated segment.
        void append(Node& current, const Node& right) {

            Node temp;

            temp.prod =
                (1LL * current.prod * right.prod) % k;

            // Prefixes that were already completely
            // inside current.
            for(int i = 0; i < k; i++) {
                temp.rem[i] = current.rem[i];
            }

            // Entire current + prefix of right.
            for(int i = 0; i < k; i++) {

                int r =
                    (1LL * current.prod * i) % k;

                temp.rem[r] += right.rem[i];
            }

            current = temp;
        }

        void query(
            int start,
            int end,
            int idx,
            int l,
            int r,
            Node& ans,
            bool& found
        ) {

            if(r < start || l > end)
                return;

            if(l >= start && r <= end) {

                if(!found) {
                    ans = seg[idx];
                    found = true;
                }
                else {
                    append(ans, seg[idx]);
                }

                return;
            }

            int mid = l + (r - l) / 2;

            // IMPORTANT:
            // left first, then right.
            query(
                start,
                end,
                2 * idx + 1,
                l,
                mid,
                ans,
                found
            );

            query(
                start,
                end,
                2 * idx + 2,
                mid + 1,
                r,
                ans,
                found
            );
        }

        Node find(int start, int end) {

            Node ans;
            bool found = false;

            query(
                start,
                end,
                0,
                0,
                n - 1,
                ans,
                found
            );

            return ans;
        }
    };


    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {

        int n = nums.size();

        SegmentTree segment(n, k);

        segment.build(0, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for(auto& q : queries) {

            int i = q[0];
            int v = q[1];
            int start = q[2];
            int r = q[3];

            segment.update(i, v);

            Node x = segment.find(start, n - 1);

            ans.push_back(x.rem[r]);
        }

        return ans;
    }
};