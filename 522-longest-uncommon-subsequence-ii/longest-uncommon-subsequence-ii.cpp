class Solution {
public:
    bool isSeq(string a, string b){
        if(a.size() > b.size())return false;

        int i = 0, j = 0;
        while(i < a.size() && j < b.size()){
            if(a[i] == b[j]){
                i++;
                j++;
            }
            else j++;
        }
        if(i == a.size())return true;
        return false;
    }

    int findLUSlength(vector<string>& strs) {
        auto cmp = [&](string& a, string& b){
            return a.size() > b.size();
            
        };

        sort(strs.begin(), strs.end(), cmp);

        for(int i = 0; i < strs.size(); i++){
            // cout<<strs[i]<<" ";
            bool isNot = true;
            for(int j = 0; j < strs.size(); j++){
                if(j == i)continue;
                if(isSeq(strs[i], strs[j])){
                    isNot = false;
                    break;
                }
            }
            cout<<endl;
            if(isNot)return (int)strs[i].size();
        }
        return -1;
    }
};