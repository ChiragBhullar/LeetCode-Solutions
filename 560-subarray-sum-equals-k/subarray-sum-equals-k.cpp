class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0]=1;
        int sum=0,count=0;
        for(int x:nums){
            sum+=x;
            if(freq.find(sum-k)!=freq.end()){
                count+=freq[sum-k];
        }
        freq[sum]++;
        }
        return count;
    }
};