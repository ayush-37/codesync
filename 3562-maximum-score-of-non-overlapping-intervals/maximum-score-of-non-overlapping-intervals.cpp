class Solution {
/*
    step 1: store which intervals is at which position
    step 2: sort intervals to get them in increasing order of starting time
    step 3: know for each index the next starting non overlapping interval (Binary search)
    step 4: we want to know score obtained and index of selected intervals (so return type int, vector)

    step 5:
        solve(i,j,intervals) return score and index when i am start obtaing score from index i with selecting at most j non non overlapping intervals

        at index i, i have two choices either i take the value of that index and lose available intervals by one or i can skip it and have chances to select j available intervals 

*/
public:
    struct Node{
        long long score = 0;
        vector<int> idx;
    };

    vector<vector<Node>> memo;
    vector<int> nxt;
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        memo.resize(n+1, vector<Node>(5, Node()));
        for(int i = 0; i < intervals.size(); i++){
            intervals[i].push_back(i);
        }

        sort(intervals.begin(), intervals.end());

        auto find = [&](int last){
            int s = 0, e = n-1;
            int mid , res = -1;
            while(s <= e){
                mid = s + (e-s)/2;
                if(last < intervals[mid][0]){
                    res = mid;
                    e = mid-1;
                }
                else s = mid+1;
            }

            return res;
        };
        nxt.assign(n,-1);
        for(int i = 0; i < n; i++){
            int idx = find(intervals[i][1]);
            nxt[i] = idx;
        }

        Node ans = solve(0,4,intervals);
        return ans.idx;
    }

    Node solve(int i, int k, vector<vector<int>>& intervals){
        if(i >= intervals.size() || k == 0)return Node();
        if(memo[i][k].score != 0)return memo[i][k];

        Node skip = solve(i+1, k, intervals);
        long long val = intervals[i][2];
        int next = nxt[i], origIdx = intervals[i][3];
        Node temp = solve(next, k-1, intervals);
        Node take;
        take.score = temp.score + val;
        take.idx = temp.idx;
        take.idx.push_back(origIdx);

        sort(take.idx.begin(), take.idx.end());

        Node res;

        if(skip.score > take.score)res = skip;
        else if(skip.score < take.score)res = take;
        else{
            res = skip.idx < take.idx ? skip: take;
        }

        return memo[i][k] = res;
    }
};