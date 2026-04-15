class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans = INT_MAX;
        int i = startIndex;
        while(i >= 0){
            if(words[i] == target){
                ans = min(ans,startIndex - i);
                ans = min(ans,(int)words.size() - startIndex + i);
            }
            i--;
        }
        i = startIndex;
        while(i < words.size()){
            if(words[i] == target){
                ans = min(ans,i-startIndex);
                ans = min(ans,(int)words.size() - i + startIndex);
            }
            i++;
        }

        if(ans == INT_MAX)return -1;
        else return ans;
    }
};