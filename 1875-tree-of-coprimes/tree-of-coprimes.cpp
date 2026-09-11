class Solution {
/*
"A brute-force solution would be to find the parent of every node and walk upward through all its ancestors, checking the GCD. In a skewed tree, that can take O(N²).

The key observation is that while doing DFS, the ancestors of the current node are exactly the nodes on the current root-to-node path.

Also, the values are limited to 1 through 50. So I maintain an array curr where curr[x] stores the deepest ancestor on the current DFS path whose value is x.

I also precompute which values from 1 to 50 are coprime with each other.

For every node, I iterate over all values coprime with its value. If curr[value] exists, that node is a valid ancestor. Among all candidates I choose the one with maximum depth, because that is the closest ancestor.

Importantly, I calculate the answer before inserting the current node into curr, so the node cannot select itself. Then I insert the current node, recursively process its children, and finally restore the previous value of curr while backtracking.

Since there are at most 50 possible values, each node checks at most 50 values, giving O(50N), which is effectively O(N)."


*/
public:
    vector<vector<int>> coprime;
    vector<int> dis, ans, curr;
    vector<vector<int>> graph;

    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        graph.assign(n, {});

        for(auto x: edges){
            int u = x[0], v = x[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dis.assign(n,0);
        ans.assign(n,-1);
        curr.assign(51,-1);

        coprime.assign(51,{});
        
        for(int i = 1; i <= 50; i++){
            for(int j = 1; j <= 50; j++)if(gcd(i,j) == 1)coprime[i].push_back(j);
        }

        dfs(0,-1,nums);

        return ans;
    }

    void dfs(int node, int par, vector<int>& nums){

        int nodeValue = nums[node];

        int best = -1;
        for(auto val: coprime[nodeValue]){
            if(curr[val] != -1){
                int anc = curr[val];
                if(best == -1 || dis[anc] > dis[best]){
                    best = anc;
                }
            }
        }
        ans[node] = best;

        int prevNode = curr[nodeValue];
        curr[nodeValue] = node;

        for(auto nbr: graph[node]){
            if(nbr != par){
                dis[nbr] = dis[node] + 1;
                dfs(nbr, node, nums);
            }
        }

        curr[nodeValue] = prevNode;
    }
};

/*
    0 - 1
    1 - 2, 3
    par -> -1, 0, 1,1
    ans -> -1, 0, 0, 1


*/