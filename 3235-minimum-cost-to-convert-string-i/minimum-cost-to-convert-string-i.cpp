class Solution {
private:
    void dfs(int u, pair<long long, long long> p,long long fare, vector<vector<long long>>& tot, vector<vector<pair<int,int>>>& graph){
        int v = p.first;
        int cos = p.second;

        if(tot[u][v] < fare + cos)return;

        tot[u][v] = fare + cos;
        for(int j = 0; j < graph[v].size(); j++){
            dfs(u,graph[v][j],tot[u][v],tot,graph);
        }
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<long long>> tot(26,vector<long long>(26,LLONG_MAX));
        vector<vector<pair<int,int>>> graph(26);

        for(int i = 0; i < original.size(); i++){
            int u = original[i] - 'a';
            int v = changed[i] - 'a';

            graph[u].push_back({v,cost[i]});
            tot[u][v] = min(tot[u][v],(long long)cost[i]);
        }

        for(int i = 0; i < 26; i++){
            tot[i][i] = 0;
        }

        for(int i = 0;i < 26; i++){
            for(int j = 0; j < graph[i].size(); j++){
                dfs(i,graph[i][j],0,tot,graph);
            }
        }

        long long ans = 0;
        for(int i = 0; i < source.size(); i++){
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if(tot[u][v] == LLONG_MAX)return -1;
            ans += tot[u][v];
        }
        return ans;
    }
};