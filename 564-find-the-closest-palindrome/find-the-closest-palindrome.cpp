class Solution {
public:
    using ll = long long;

    string makePalindrome(string prefix, bool odd) {
        string res = prefix;

        int start = odd ? prefix.size() - 2 : prefix.size() - 1;

        for (int i = start; i >= 0; i--) {
            res += prefix[i];
        }

        return res;
    }

    string nearestPalindromic(string n) {
        int len = n.size();
        if(len == 1){
            string ans = "";
            ans += (((n[0]-'0') - 1) + '0');
            return ans;
        }
        int halfLen = (len + 1) / 2;

        // Take first half (including middle for odd length)
        string prefix = n.substr(0, halfLen);

        vector<string> candidates;

        // prefix - 1
        string p1 = to_string(stoll(prefix) - 1);
        candidates.push_back(makePalindrome(p1, len % 2));

        // prefix
        candidates.push_back(makePalindrome(prefix, len % 2));

        // prefix + 1
        string p2 = to_string(stoll(prefix) + 1);
        candidates.push_back(makePalindrome(p2, len % 2));

        // 999...999 (length len - 1)
        candidates.push_back(string(len - 1, '9'));

        // 100...001 (length len + 1)
        candidates.push_back("1" + string(len - 1, '0') + "1");

        string ans = "";
        ll minDiff = LLONG_MAX;

        ll original = stoll(n);

        for (string candidate : candidates) {

            // n itself is not allowed
            if (candidate == n)
                continue;

            ll value = stoll(candidate);
            ll diff = llabs(value - original);

            if (diff < minDiff ||
                (diff == minDiff && value < stoll(ans))) {

                minDiff = diff;
                ans = candidate;
            }
        }

        return ans;
    }
};