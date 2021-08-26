class Solution{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c){
        if(r*c != mat.size()*mat[0].size()){
            return mat;
        }
        vector<vector<int>> ans(r);
        for(auto&it:ans){
            it.resize(c);
        }
        int index=0;
        int size=mat[0].size();
        for(int i=0;i<r and index<mat.size()*mat[0].size();i++){
            for(int j=0;j<c and index<mat.size()*mat[0].size();j++){
                int row=index/size;
                int col=index%size;
                ans[i][j]=mat[row][col];
                index++;
            }
        }
        return ans;
    }
};