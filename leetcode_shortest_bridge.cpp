int row_dir[]={1,-1,0,0};
int col_dir[]={0,0,1,-1};
class Solution{
public:
    bool visited[1000][1000]={false};
    void visit_all(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&comp,int c){
        if(i<0 or j<0 or i>=mat.size() or j>=mat[i].size() or visited[i][j] or mat[i][j]==0){
            return;
        }
        visited[i][j]=true;
        comp[i][j]=c;
        for(int k=0;k<4;k++){
            visit_all(i+row_dir[k],j+col_dir[k],mat,comp,c);
        }
    }
    int shortestBridge(vector<vector<int>>& mat){
        //create them a two different component
        vector<vector<int>> comp(mat.size());
        for(auto&it:comp){
            it.resize(mat[0].size());
        }
        for(int i=0;i<comp.size();i++){
            for(int j=0;j<comp[i].size();j++){
                comp[i][j]=0;
            }
        }
        int c=1;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(!visited[i][j] and mat[i][j]==1){
                    visit_all(i,j,mat,comp,c);
                    c++;
                }
            }
        }
        if(c==1){
            return 0;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<comp.size();i++){
            for(int j=0;j<comp[i].size();j++){
                visited[i][j]=false;
                bool b=false;
                if(j+1<comp[0].size() and comp[i][j+1]==0){
                    b=true;
                }
                if(j-1>=0 and comp[i][j-1]==0){
                    b=true;
                }
                if(i+1<comp.size() and comp[i+1][j]==0){
                    b=true;
                }
                if(i-1<comp.size() and comp[i-1][j]==0){
                    b=true;
                }
                if(b and comp[i][j]==1) q.push({i,j});
            }
        }
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<int,int> temp=q.front();
                q.pop();
                if(comp[temp.first][temp.second]==2){
                    return level-1;
                }
                if(visited[temp.first][temp.second]){
                    continue;
                }
                visited[temp.first][temp.second]=true;
                comp[temp.first][temp.second]=1;
                for(int k=0;k<4;k++){
                    if( temp.first+row_dir[k]>=0 and temp.second+col_dir[k]>=0 and temp.first+row_dir[k]<comp.size() and temp.second+col_dir[k]<comp[0].size() and !visited[temp.first+row_dir[k]][temp.second+col_dir[k]] and comp[temp.first+row_dir[k]][temp.second+col_dir[k]]!=1){
                        q.push({temp.first+row_dir[k],temp.second+col_dir[k]});
                    }
                }
            }
            level++;
        }
        return 0;
    }
};