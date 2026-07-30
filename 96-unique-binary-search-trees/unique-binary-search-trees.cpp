class Solution {
public:
    unordered_map<string, int> mp;
    int numTrees(int n) {
        generate(1,n);
        string temp = to_string(1) + "_" + to_string(n);
        return mp[temp];
    }

    int generate(int start, int end){

        string temp = to_string(start) + "_" + to_string(end);

        if(start > end)return mp[temp] = 1;
        if(mp.find(temp) != mp.end())return mp[temp];

        int combn = 0;
        for(int i = start; i <= end; i++){
            int left = generate(start,i-1);
            int right = generate(i+1,end);
            combn += left*right;
        }

        return mp[temp] = combn;
    }
};