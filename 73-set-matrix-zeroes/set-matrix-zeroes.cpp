class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map <int,pair<int,int>> mpp;
        int k=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    mpp.insert({k,{i,j}});
                    k++;
                }
            }
        }
        for(int i=0;i<mpp.size();i++){
            int row=mpp[i].first;
            for(int j=0;j<matrix[0].size();j++){    
                matrix[row][j]=0;
            }
        }
        for(int i=0;i<mpp.size();i++){
            int column=mpp[i].second;
            for(int j=0;j<matrix.size();j++){
                matrix[j][column]=0;
            }
        }
    }
};