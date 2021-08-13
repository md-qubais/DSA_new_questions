class Pair{
public:
    int row;
    int col;
    string mat;
    Pair(int row,int col,string mat){
        this->row=row;
        this->col=col;
        this->mat=mat;
    }
};
class Solution{
public:
    int slidingPuzzle(vector<vector<int>>& board){
        string ans="123450";
        string init="";
        queue<Pair> q;
        int r,c;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                init+=to_string(board[i][j]);
                if(board[i][j]==0){
                r=i,c=j;    
                }
            }
        }
        q.push(Pair(r,c,init));
        unordered_map<string,bool> visited;
        int level=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                Pair temp=q.front();
                q.pop();
                if(temp.mat==ans){
                    return level;
                }
                if(visited[temp.mat]){
                    continue;
                }
                visited[temp.mat]=true;
                int row_dir[]={1,-1,0,0};
                int col_dir[]={0,0,1,-1};
                for(int k=0;k<4;k++){
                    int row=row_dir[k]+temp.row;
                    int col=col_dir[k]+temp.col;
                    if(row<0 or col<0 or row>=board.size() or col>=board[row].size()){
                        continue;
                    }
                    vector<vector<char>> grid(board.size());
                    for(auto&it:grid){
                        it.resize(board[0].size());
                    }
                    int t=0;
                    for(int i=0;i<board.size();i++){
                        for(int j=0;j<board[i].size();j++){
                            grid[i][j]=temp.mat[t++];
                        }
                    }
                    swap(grid[temp.row][temp.col],grid[row][col]);
                    string str="";
                    for(int i=0;i<grid.size();i++){
                        for(int j=0;j<grid[i].size();j++){
                            str+=grid[i][j];
                        }
                    }
                    if(!visited[str]){
                        q.push(Pair(row,col,str));
                    }
                    swap(grid[temp.row][temp.col],grid[row][col]);
                }
            }
            level++;
        }
        return -1;
    }
};