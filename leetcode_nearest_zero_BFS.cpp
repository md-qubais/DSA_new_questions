class Solution{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<int> q;
        int index=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push(index);
                }else mat[i][j]=-1;
                index++;
            }
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int idx=q.front();
                q.pop();
                int row=idx/m;
                int col=idx%m;
                int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
                for(int k=0;k<4;k++){
                    int r=row+dir[k][0];
                    int c=col+dir[k][1];
                    if(r<0 or c<0 or r>=mat.size() or c>=mat[r].size()){
                        continue;
                    }
                    if(mat[r][c]==0 or mat[r][c]>0){
                        continue;
                    }
                    mat[r][c]=mat[row][col]+1;
                    q.push(r*m+c);
                }
            }
        }
        return mat;
    }
};