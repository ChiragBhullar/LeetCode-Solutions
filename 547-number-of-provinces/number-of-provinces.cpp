class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int provinces=0;
        for(int i=0;i<n;i++){
            if(isConnected[i][i]==0) continue;
            provinces++;
            stack<int> st;
            st.push(i);
            while(!st.empty()){
                int cur=st.top();
                st.pop();
                if(isConnected[cur][cur]==0) continue;
                isConnected[cur][cur]=0;
                for(int j=0;j<n;j++){
                    if(isConnected[cur][j]==1 && isConnected[j][j]==1){
                        st.push(j);
                    }
                }
            }
        }
        return provinces;
    }
};