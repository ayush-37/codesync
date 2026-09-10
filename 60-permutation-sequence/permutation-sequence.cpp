class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> fac(n+1,1);
        for(int i = 1; i <= n; i++){
            ans.push_back('0'+i);
            fac[i] = fac[i-1] * i;
        }
        if(n == 1 || k == 1)return ans;

        int digChange = 0;
        for(int i = 0; i < n; i++){
            if(fac[i+1] >= k){
                digChange = i+1;
                break;
            }
        }
        set<int> st;
        for(int i = n; i >= 1 && digChange > 0; i--, digChange--){
            st.insert(i);
            // cout<<i<<" ";
        }
        // cout<<endl;

        string temp = "";

        while(st.size() >= 1){
            int restLen = st.size()-1;
            int q = (k / fac[restLen]), r = (k % fac[restLen]);

            // cout<<k<<" "<<restLen<<"   "<<q<<" "<<r<<"   ";
            if(r == 0){
                q--;
                int flag = 0;
                for(auto itr = st.begin(); itr != st.end(); itr++){
                    if(flag == q){
                        temp.push_back('0' + *itr);
                        st.erase(*itr);
                        break;
                    }
                    flag++;
                }

                for(auto itr = st.rbegin(); itr != st.rend(); itr++){
                    temp.push_back('0' + *itr);
                }

                break;
            }
            else{
                int flag = 0;
                // cout<<"r != 0 => "<<q<<" "<<r<<"  size- ";
                for(auto itr = st.begin(); itr != st.end(); itr++){
                    if(flag == q){
                        temp.push_back('0' + *itr);
                        st.erase(*itr);
                        break;
                    }
                    flag++;
                }
                // cout<<st.size()<<endl;
                k = r;
            }
        }
        // cout<<temp<<endl;
        string res = "";

        for(int i = 1; i <= (n-temp.size()); i++)res.push_back('0'+i);
        for(int j = 0; j < temp.size(); j++)res.push_back(temp[j]);
        return res;
        
    }
};