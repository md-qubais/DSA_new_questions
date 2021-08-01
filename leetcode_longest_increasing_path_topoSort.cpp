//the problems of the dependencies can also be solve
//by the topological sort of kahn's algorithm bfs
//and this question can also be done by dfs
//and as well as dynamic programming
class Solution{
public:
    int longestIncreasingPath(vector<vector<int>>& matrix){
        queue<int> q;
        vector<vector<int>> indegree(matrix.size());
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<matrix.size();i++){
            vector<int> temp(matrix[0].size());
            indegree[i]=temp;
        }
        int row_dir[]={1,-1,0,0};
        int col_dir[]={0,0,1,-1};
        //count the indegrees of four directions
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                for(int k=0;k<4;k++){
                    int row=i+row_dir[k];
                    int col=j+col_dir[k];
                    if(row<0 or col<0 or row>=matrix.size() or col>=matrix[row].size() or matrix[row][col]<=matrix[i][j]){
                        continue;
                    }
                    indegree[row][col]++;
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(indegree[i][j]==0){
                    q.push(i*m+j);
                }
            }
        }
        int count=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int temp=q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int row=temp/m+row_dir[k];
                    int col=temp%m+col_dir[k];
                    if(row<0 or col<0 or row>=matrix.size() or col>=matrix[row].size() or matrix[row][col]<=matrix[temp/m][temp%m]){
                        continue;
                    }
                    indegree[row][col]--;
                    if(indegree[row][col]==0){
                        q.push(row*m+col);
                    }
                }   
            }
            count++;
        }
        return count;
    }
};