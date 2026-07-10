class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> order(n);
        for(int i=0;i<n;i++) order[i]=i;
        sort(order.begin(),order.end(),[&](int a,int b){return nums[a]<nums[b];});
        vector<int> rank(n);
        for(int i=0;i<n;i++) rank[order[i]]=i;
        vector<int> sortedVal(n);
        for(int i=0;i<n;i++) sortedVal[i]=nums[order[i]];
        vector<int> reach(n);
        int j=0;
        for(int i=0;i<n;i++){
            if(j<i) j=i;
            while(j+1<n&&sortedVal[j+1]-sortedVal[i]<=maxDiff) j++;
            reach[i]=j;
        }
        int LOG=1;
        while((1<<LOG)<n) LOG++;
        LOG++;
        vector<vector<int>> up(LOG,vector<int>(n));
        up[0]=reach;
        for(int k=1;k<LOG;k++)
            for(int i=0;i<n;i++)
                up[k][i]=up[k-1][up[k-1][i]];
        vector<int> ans(queries.size());
        for(int qi=0;qi<queries.size();qi++){
            int a=rank[queries[qi][0]],b=rank[queries[qi][1]];
            int lo=min(a,b),hi=max(a,b);
            if(lo==hi){ ans[qi]=0; continue; }
            int cur=lo,hops=0;
            for(int k=LOG-1;k>=0;k--){
                if(up[k][cur]<hi){
                    cur=up[k][cur];
                    hops+=(1<<k);
                }
            }
            ans[qi]=(reach[cur]>=hi)?hops+1:-1;
        }
        return ans;
    }
};