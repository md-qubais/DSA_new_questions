//https://leetcode.com/problems/the-maze-iii/
//https://www.lintcode.com/problem/789/
class Pairing{
public:
    int row;
    int col;
    int tot;
    string direction;
    Pairing(){}
    Pairing(int row,int col,int tot,string direction){
        this->row=row;
        this->col=col;
        this->tot=tot;
        this->direction=direction;
    }
};

class Compare{
public:
    bool operator()(Pairing p1,Pairing p2){
         if(p1.tot == p2.tot){
            return p1.direction > p2.direction;
        }
        return p1.tot > p2.tot;
    }
};


class Solution {
public:
    string findShortestWay(vector<vector<int>> &maze, vector<int> &ball, vector<int> &hole){
        priority_queue<Pairing,vector<Pairing>,Compare> pq;
        queue<Pairing> q;
        bool visited[100][100]={false};
        q.push(Pairing(ball[0],ball[1],0,""));
        while(!q.empty()){
            int size=q.size();
            while(size--){
                Pairing temp=q.front();
                q.pop();
                int r=temp.row;
                int c=temp.col;
                if(visited[r][c]){
                    continue;
                }
                visited[r][c]=true;
                //move ball in all the four directions
                char dir[]={'d','u','r','l'};
                int row_dir[]={1,-1,0,0};
                int col_dir[]={0,0,1,-1};
                for(int k=0;k<4;k++){
                    int rows=r+row_dir[k];
                    int cols=c+col_dir[k];
                    int steps=0;
                    bool b=false;
                    while(rows>=0 and cols>=0 and rows<=maze.size()-1 and cols<=maze[0].size()-1 and maze[rows][cols]!=1){
                        b=true;
                        steps++;
                        if(rows==hole[0] and cols==hole[1]){
                            pq.push(Pairing(rows,cols,temp.tot+steps,temp.direction+dir[k]));
                            b=false;
                            break;
                        }
                        if(rows+row_dir[k]>=0 and cols+col_dir[k]>=0 and rows+row_dir[k]<=maze.size()-1 and cols+col_dir[k]<=maze[0].size()-1 and maze[rows+row_dir[k]][cols+col_dir[k]]!=1){
                            rows+=row_dir[k];
                            cols+=col_dir[k];
                        }else break;    
                    }
                    if(b){
                        q.push(Pairing(rows,cols,temp.tot+steps,temp.direction+dir[k]));
                    }
                }
            }
        }
        if(!pq.empty()){
            return pq.top().direction;
        }
        return "impossible";
    }
};