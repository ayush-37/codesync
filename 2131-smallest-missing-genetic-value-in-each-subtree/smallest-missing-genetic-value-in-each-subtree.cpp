class Solution {
public:
    /*
    Observation: ans for subtree not containing nums[node] = 1 will always 1
    the nodes that will have different ans will be the ones that comes in the path between node 0 and node with nums[node] = 1

    if we have 1 then we will dfs backwards from node with nums[node] = 1 to root node = 0
    and marks all the seen values of nums[node] in the subtree as not missing and then check which value is missign in the range 1 to 1e5
    
    */


    vector<vector<int>> graph;
    vector<int>vis, seen, values;
    void dfs(int node){
        vis[node] = 1;
        for(auto nbr: graph[node])if(vis[nbr] == 0)dfs(nbr);
        seen[values[node]] = 1;
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int n = parents.size();
        int oneNode = -1;
        vector<int> ans(n,1);
        graph.assign(n,{});
        for(int i = 0; i < n; i++){
            if(parents[i]  != -1)graph[parents[i]].push_back(i);
            if(nums[i] == 1)oneNode = i;
        }

        if(oneNode == -1)return ans;

        int node = oneNode;
        values = nums;
        vis.assign(n,0);
        seen.assign(1e5+1,0);
        int missing = 1;
        while(node != -1){
            dfs(node);
            while(missing < seen.size() && seen[missing])missing++;
            ans[node] = missing;
            node = parents[node];
        }
        return ans;
    }
};