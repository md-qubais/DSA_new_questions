class Solution{
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0;
        int rotten_count=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<int> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push(i*m+j);
                    rotten_count++;
                }else if(grid[i][j]==1){
                    count++;
                }
            }
        }
        if(count==0){
            return 0;
        }
        if(rotten_count==0){
            return -1;
        }
        int time=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int idx=q.front();
                int row=idx/m;
                int col=idx%m;
                q.pop();
                int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
                for(int i=0;i<4;i++){
                    int r=row+dir[i][0];
                    int c=col+dir[i][1];
                    if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size() or grid[r][c]==0 or grid[r][c]==2){
                        continue;
                    }
                    q.push(r*m+c);
                    grid[r][c]=2;
                    count--;
                    if(count==0){
                        return time+1;
                    }
                }
            }
            time++;
        }
        return -1;
    }
};