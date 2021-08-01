class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<int> q;
        q.push(0);
        int path=1;
        int n=grid.size();
        int m=grid[0].size();
        if(n==0 or m==0 or grid[0][0]==1){
            return -1;
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int idx=q.front();
                q.pop();
                int row=idx/m;
                int col=idx%m;
                if(row==grid.size()-1 and col==grid[row].size()-1){
                    return path; 
                }
                grid[row][col]=1;
                int dir[8][2]={{1,1},{1,-1},{-1,1},{-1,-1},{1,0},{0,1},{-1,0},{0,-1}};     
                for(int k=0;k<8;k++){
                    int r=row+dir[k][0];
                    int c=col+dir[k][1];
                    if(r<0 or c<0 or r>=grid.size() or c>=grid[r].size() or grid[r][c]==1){
                        continue;
                    }
                    grid[r][c]=1;
                    q.push(r*m+c);
                }
            }
            path++;
        }
        return -1;
    }
};