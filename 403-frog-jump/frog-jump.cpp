class Solution {
public:
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1)return false;
        vector<vector<int>> mp(2002,vector<int>(2002,-1));
        unordered_map<int,int> noToInd;
        for(int i = 0; i < stones.size(); i++){
            noToInd[stones[i]] = i;
        }
        return solve(1, 1, stones,mp, noToInd);
    }
    bool solve(int i, int j, vector<int>& stones, vector<vector<int>>& mp, unordered_map<int,int>& noToInd){
        if(i == stones.size() - 1)return true;
        if(mp[i][j] != -1)return mp[i][j];

        bool canJump = false;
        if(j - 1 > 0 && noToInd.count(stones[i] + j - 1))
            canJump |= solve(noToInd[stones[i] + j - 1], j - 1, stones, mp, noToInd);

        if(noToInd.count(stones[i] + j))
            canJump |= solve(noToInd[stones[i] + j], j, stones, mp, noToInd);

        if(noToInd.count(stones[i] + j + 1))
            canJump |= solve(noToInd[stones[i] + j + 1], j + 1, stones, mp, noToInd);

        return mp[i][j] = canJump;
    }
};