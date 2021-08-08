class Pair{
public:
    int r;
    int c;
    int k;
    Pair(int r,int c,int k){
        this->r=r;
        this->c=c;
        this->k=k;
    }
};
class Solution{
public:
    bool visited[100][100][100]={false};
    int shortestPath(vector<vector<int>>& grid, int obs){
        queue<Pair> q;
        q.push(Pair(0,0,0));
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                Pair temp=q.front();
                q.pop();
                if(temp.r==grid.size()-1 and temp.c==grid[0].size()-1){
                    return level;
                }
                if(visited[temp.r][temp.c][temp.k]){
                    continue;
                }
                visited[temp.r][temp.c][temp.k]=true;
                int row_dir[]={1,-1,0,0};
                int col_dir[]={0,0,1,-1};
                for(int dir=0;dir<4;dir++){
                    int row=temp.r+row_dir[dir];
                    int col=temp.c+col_dir[dir];
                    if(row<0 or col<0 or row>=grid.size() or col>=grid[row].size() ){
                        continue;
                    }
                    if(grid[row][col]==1){
                        if(!visited[row][col][temp.k+1] and temp.k+1 <= obs){
                            q.push(Pair(row,col,temp.k+1));
                        }
                    }else{
                        q.push(Pair(row,col,temp.k));
                    }
                }
            }
            level++;
        }
        return -1;
    }
};