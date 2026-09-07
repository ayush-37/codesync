class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1e9 + 7;

        // tot = total number of distinct NON-EMPTY subsequences
        // formed so far.
        long long tot = 0;

        // last[c] = total number of distinct subsequences immediately after the PREVIOUS occurrence of character c.
        // We use this to know how many subsequences will become duplicates when we encounter c again.
        vector<long long> last(26, 0);

        for(char x : s) {
            int c = x - 'a';

            // If we add x to every existing subsequence, we get 'tot' new subsequences, plus x itself.
            // But last[c] of these were already created when the previous occurrence of c was processed.
            // Therefore:
            // new unique subsequences = tot + 1 - last[c]
            long long add = (tot + 1 - last[c] + MOD) % MOD;

            // Store the NEW total.
            // This will be used when the same character appears again.
            last[c] = (tot + 1) % MOD;

            // Add the newly created unique subsequences to the total.
            tot = (tot + add) % MOD;

        }

        return tot;
    }
};