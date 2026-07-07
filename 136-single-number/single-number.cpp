class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singlenum=nums[0];
        for(int i=1;i<nums.size();i++){
            singlenum=singlenum^nums[i];
        }
        return singlenum;
    }
};