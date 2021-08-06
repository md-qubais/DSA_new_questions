int row_dir[]={1,-1,0,0};
int col_dir[]={0,0,1,-1};
class Solution {
public:
    vector<bool> visited; 
    void mark_component(int i,int j,vector<vector<int>>&grid,int n,int m,int c){
        if(i<0 or j<0 or i>=n or j>=m or grid[i][j]==0  or visited[i*m+j]){
            return;
        }
        visited[i*m+j]=true;
        grid[i][j]=c;
        for(int k=0;k<4;k++){
            mark_component((i+row_dir[k]),(j+col_dir[k]),grid,n,m,c);
        }
    }
    int shortestBridge(vector<vector<int>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        visited.resize(n*m);
        int c=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i*m+j] and grid[i][j]==1){
                    mark_component(i,j,grid,n,m,c);
                    c++;
                }
            }
        }
        if(c==1){
            return 0;
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                visited[i*m+j]=false;
                if(grid[i][j]==1){
                    bool b=false;
                    for(int k=0;k<4;k++){
                        int row=i+row_dir[k];
                        int col=j+col_dir[k];
                        if(row<0 or col<0 or row>=n or col>=m or grid[row][col]!=0){
                            continue;
                        }
                        b=true;
                    }
                    if(b) q.push(i*m+j);
                }
            }
        }
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int temp=q.front();
                q.pop();
                int i=temp/m;
                int j=temp%m;
                for(int k=0;k<4;k++){
                    int row=i+row_dir[k];
                    int col=j+col_dir[k];
                    if(row<0 or col<0 or row>=n or col>=m or grid[row][col]==1){
                        continue;
                    }
                    if(grid[row][col]==2){
                        return level;
                    }
                    grid[row][col]=1;
                    q.push(row*m+col);
                }
            }
            level++;
        }
        return 0;
    }
};