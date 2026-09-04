class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string,int> mp;
    vector<vector<int>> par;
    int start;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

        ans.clear();
        mp.clear();
        par.clear();
        
        wordList.push_back(beginWord);

        for(int i = 0; i < wordList.size(); i++){
            mp[wordList[i]] = i;;
        }

        int n = wordList.size();

        if(mp.count(endWord) == 0)return ans;

        vector<int> dis(n,INT_MAX);
        par.resize(n);

        
        queue<int> q;
        q.push(mp[beginWord]);
        dis[mp[beginWord]] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            string temp = wordList[node];

            for(int i = 0; i < temp.size(); i++){
                for(int j = 0; j < 26; j++){
                    string newTemp = temp;
                    char c = 'a' + j;
                    if(temp[i] == c)continue;

                    newTemp[i] = c;
                    if(mp.count(newTemp)){
                        int next = mp[newTemp];
                        if(dis[next] == INT_MAX){
                            dis[next] = dis[node] + 1;
                            par[next].push_back(node);
                            q.push(next);
                        }
                        else if(dis[next] == dis[node] + 1){
                            par[next].push_back(node);
                        }
                    }
                }
            }
        }

        if(dis[mp[endWord]] == INT_MAX)return ans;

        start = mp[beginWord];
        vector<int> path;
        path.push_back(mp[endWord]);
        dfs(path,mp[endWord],wordList);

        return ans;
        
    }

    void dfs(vector<int>& path, int node, vector<string>& wordList){
        if(node == start){
            vector<string> temp;
            for(int i = path.size()-1; i >= 0; i--)temp.push_back(wordList[path[i]]);

            ans.push_back(temp);
            return;
        }

        for(int nbr: par[node]){
            path.push_back(nbr);
            dfs(path, nbr, wordList);
            path.pop_back();
        }
    }
};