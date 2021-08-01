class Solution{
public:
    unordered_map<int,int> leaders;
    unordered_map<int,int> size;
    int getLeaders(int n){
        if(n==leaders[n]){
            return n;
        }
        return leaders[n]=getLeaders(leaders[n]);
    }
    void Union(int n1,int n2){
        int l1=getLeaders(leaders[n1]);
        int l2=getLeaders(leaders[n2]);
        if(l1!=l2){
            if(size[l1]>=size[l2]){
                size[l1]+=size[l2];
                leaders[l2]=l1;
            }else{
                size[l2]+=size[l1];
                leaders[l1]=l2;
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid){
        int ans=0;
        int n=grid.size();
        int m=grid[ans].size();
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    leaders[i*m+j]=i*m+j;
                    size[i*m+j]=1;
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    if(i+1<n and grid[i+1][j]==1){
                        Union(i*m+j,(i+1)*m+j);
                    }
                    if(j+1<m and grid[i][j+1]==1){
                        Union(i*m+j,i*m+(j+1));
                    }
                    ans=max(ans,size[getLeaders(i*m+j)]);
                }
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    set<int> s;
                    int row_dir[]={1,-1,0,0};
                    int col_dir[]={0,0,1,-1};
                    for(int k=0;k<4;k++){
                        int row=i+row_dir[k];
                        int col=j+col_dir[k];
                        if(row<0 or col<0 or row>=n or col>=m or grid[row][col]==0 ){
                            continue;
                        }
                        s.insert(getLeaders(row*m+col));
                    }
                    int tot=0;
                    for(auto&it:s){
                        tot+=size[it];
                    }
                    ans=max(ans,tot+1);
                }
            }
        }
        return ans;
    }
};