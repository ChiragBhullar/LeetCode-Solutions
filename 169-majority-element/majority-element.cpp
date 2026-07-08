class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        auto maxEntry=max_element(
        mpp.begin(),mpp.end(),
        [](const auto& p1,const auto& p2) {
            return p1.second<p2.second;
        }
        ); 
        return maxEntry->first;
    }
};