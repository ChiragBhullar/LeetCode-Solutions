class Solution {
public:
    static const int MOD=1000000007;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> pos,dig,ans;
        for(int i=0;i<s.size();i++)
            if(s[i]!='0'){
                pos.push_back(i);
                dig.push_back(s[i]-'0');
            }
        int m=dig.size();
        vector<long long> p10(m+1,1),pre(m+1),sum(m+1);
        for(int i=1;i<=m;i++)
            p10[i]=p10[i-1]*10%MOD;
        for(int i=0;i<m;i++){
            pre[i+1]=(pre[i]*10+dig[i])%MOD;
            sum[i+1]=sum[i]+dig[i];
        }
        for(auto &q:queries){
            int l=q[0],r=q[1];
            int L=lower_bound(pos.begin(),pos.end(),l)-pos.begin();
            int R=upper_bound(pos.begin(),pos.end(),r)-pos.begin()-1;
            if(L>R){
                ans.push_back(0);
                continue;
            }
            long long num=(pre[R+1]-pre[L]*p10[R-L+1]%MOD+MOD)%MOD;
            long long sm=sum[R+1]-sum[L];
            ans.push_back(num*sm%MOD);
        }
        return ans;
    }
};