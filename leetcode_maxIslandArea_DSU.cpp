class Solution{
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> size;
    int findParent(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=findParent(parent[u]);
    }
    void Union(int curr_row,int curr_col,int row,int col,int n,int m){
        int p1=findParent(curr_row*m+curr_col);
        int p2=findParent(row*m+col);
        if(p1!=p2){
            if(size[p1]>=size[p2]){
                parent[p2]=p1;
                size[p1]+=size[p2];
            }else{
                parent[p1]=p2;
                size[p2]+=size[p1];
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid){
        int count=0;
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count++;
                }
                parent[i*m+j]=i*m+j;
                size[i*m+j]=1;
            }
        }
        if(count==0) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    if((i+1)<n and grid[i+1][j]==1){
                        Union(i,j,i+1,j,n,m);
                    }
                    if((j+1)<m and grid[i][j+1]==1){
                        Union(i,j,i,j+1,n,m);
                    }
                    ans=max(ans,size[findParent(i*m+j)]);
                }
            }
        }
        return ans;
    }
};