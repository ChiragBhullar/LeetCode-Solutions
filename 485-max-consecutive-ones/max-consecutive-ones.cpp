class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int maximum=0;
        int act=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                act+=1;
                maximum=max(act,maximum);
            }
            else act=0;
        }
        return maximum;
    }
};