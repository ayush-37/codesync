class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Represent seats 2..9 using bits
        for (auto &seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                mp[row] |= (1 << col);
            }
        }

        int ans = 2 * (n - mp.size());

        for (auto &[row, mask] : mp) {
            bool left  = !(mask & (1 << 2)) &&
                         !(mask & (1 << 3)) &&
                         !(mask & (1 << 4)) &&
                         !(mask & (1 << 5));

            bool middle = !(mask & (1 << 4)) &&
                          !(mask & (1 << 5)) &&
                          !(mask & (1 << 6)) &&
                          !(mask & (1 << 7));

            bool right = !(mask & (1 << 6)) &&
                         !(mask & (1 << 7)) &&
                         !(mask & (1 << 8)) &&
                         !(mask & (1 << 9));

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans += 1;
        }

        return ans;
    }
};