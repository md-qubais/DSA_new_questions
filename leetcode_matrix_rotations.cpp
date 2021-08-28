class Solution{
public:
    void rotateMatrix(vector<vector<int>>& mat){
        int row=mat.size();
        int col=mat[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i<j){
                    swap(mat[i][j],mat[j][i]);
                }
            }
        }
    }
    bool is_same(vector<vector<int>>& mat, vector<vector<int>>& target){
        int row=mat.size();
        int col=mat[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]!=target[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    void reverseMatrix(vector<vector<int>>& mat){
        for(int i=0;i<mat.size();i++){
            reverse(mat[i].begin(),mat[i].end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target){
        if(is_same(mat,target)){
            return true;
        }
        for(int rot=0;rot<3;rot++){
            rotateMatrix(mat);
            reverseMatrix(mat);
            if(is_same(mat,target)){
                return true;
            }
        }
        return false;
    }
};