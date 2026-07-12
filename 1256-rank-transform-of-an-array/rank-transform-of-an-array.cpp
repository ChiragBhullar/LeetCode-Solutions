class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int> sorted_arr=arr;
        sort(sorted_arr.begin(),sorted_arr.end());
        sorted_arr.erase(unique(sorted_arr.begin(),sorted_arr.end()),sorted_arr.end());
        for(int i=0;i<n;i++){
            arr[i]=lower_bound(sorted_arr.begin(),sorted_arr.end(),arr[i])-sorted_arr.begin()+1;
        }
        return arr;
    }
};