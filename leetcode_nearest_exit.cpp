class Pair{
public:
    int first;
    int second;
    int cost;
    Pair(int first,int second,int cost){
        this->first=first;
        this->second=second;
        this->cost=cost;
    }
};
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance){
        queue<Pair> q;
        q.push(Pair(entrance[0],entrance[1],0));
        bool start=true;
        int row_dir[]={1,-1,0,0};
        int col_dir[]={0,0,1,-1};
        bool visited[1000][1000]={false};
        while(!q.empty()){
            Pair temp=q.front();
            q.pop();
            if(temp.first==maze.size()-1 or temp.first==0 or temp.second==maze[0].size()-1 or temp.second==0){
                if(temp.cost>0){
                    return temp.cost;
                }
            }
            if(visited[temp.first][temp.second]){
                continue;
            }
            visited[temp.first][temp.second]=true;
            for(int k=0;k<4;k++){
                int row=temp.first+row_dir[k];
                int col=temp.second+col_dir[k];
                if(row<0 or col<0 or row>maze.size()-1 or col>maze[row].size()-1 or visited[row][col] or maze[row][col]=='+'){
                    continue;
                }
                q.push(Pair(row,col,temp.cost+1));
            }
        }
        return -1;
    }
};