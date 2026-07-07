class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        while(i<n && j<n){
            if(nums[j]!=0){
                j++;
            }
            else{
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
        j=i;
        while(i<n && j<n){
            if(nums[j]!=1){
                j++;
            }
            else{
                swap(nums[i],nums[j]);
                i++;
                j++;
            }
        }
    }
};