class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; 
        for(int i = 0; i < n; i++)pq.push({nums1[i]+nums2[0], {i,0}});
        while(!pq.empty() && ans.size() != k){
            auto [sum, p] = pq.top();
            pq.pop();
            auto [i,j] = p;
            ans.push_back({nums1[i],nums2[j]});
            if(j+1 >= m)continue;

            pq.push({nums1[i] + nums2[j+1], {i, j+1}});
        }
        return ans;
    }
};