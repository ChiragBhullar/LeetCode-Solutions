class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int i=0,j=1;
        int profit=0;
        while(i<n && j<n){
            int diff=prices[j]-prices[i];
            if(diff>=0){
                profit=max(profit,diff);
                j++;
            }
            else{
                i++;
            }
        }
        return profit;
    }
};