class Solution {
public:
    bool solve(int s, vector<int>& arr, vector<int>& vis){
        if(arr[s] == 0)return true;
        
        vis[s] = 1;
        bool c1 = false, c2 = false;
        if(s+arr[s] < arr.size() && vis[s+arr[s]] == 0){
            c1 = solve(s+arr[s],arr,vis);
        }

        if(s-arr[s] >= 0 && vis[s-arr[s]] == 0){
            c2 = solve(s-arr[s],arr,vis);
        }

        return c1 | c2;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int> vis(n,0);
        return solve(start,arr,vis);
    }
};