class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n,0);
        ugly[0] = 1;

        set<int> st;
        st.insert(2);
        st.insert(3);
        st.insert(5);

        unordered_map<int,int> ind,nextMul;
        ind[2] = 0, ind[3] = 0, ind[5] = 0;
        nextMul[2] = 2, nextMul[3] = 3, nextMul[5] = 5;

        for(int i = 1; i < n; i++){
            int mini = *st.begin();
            st.erase(*st.begin());

            ugly[i] = mini;

            if(mini == nextMul[2]){
                ind[2]++;
                nextMul[2] = 2*ugly[ind[2]];
                st.insert(nextMul[2]);
            }
            if(mini == nextMul[3]){
                ind[3]++;
                nextMul[3] = 3*ugly[ind[3]];
                st.insert(nextMul[3]);
            }
            if(mini == nextMul[5]){
                ind[5]++;
                nextMul[5] = 5*ugly[ind[5]];
                st.insert(nextMul[5]);
            }
        }

        return ugly[n-1];
    }
};