class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int curr = 0;
        int n = seq.size();
        stack<char> st;
        vector<int> temp(n,0);
        for(int i = 0; i < seq.size(); i++){
            if(seq[i] == '('){
                st.push(seq[i]);
                temp[i] = (int)st.size();
            }
            else{
                temp[i] = (int)st.size();
                st.pop();
            }
        }

        for(int i = 0; i < n; i++){
            temp[i] = temp[i]%2;
        }

        return temp;
        
    }
};