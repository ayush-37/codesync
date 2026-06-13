class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string temp = "";
        for(int i = 0; i < words.size(); i++){
            int sum = 0;
            for(int j = 0; j < words[i].size(); j++){
                sum += weights[words[i][j]-'a'];
            }
            sum = sum%26;
            temp += ('a' + (25 - sum));
        }
        return temp;
    }
};