//this solution beats 96% time and space on lintcode
//https://leetcode.com/problems/the-maze-ii/

class comapre{
public:
    bool operator()(pair<int,int> p1,pair<int,int> p2){
        return p1.second > p2.second;
    }
};
class Solution {
public:
    int shortestDistance(vector<vector<int>> &maze, vector<int> &start, vector<int> &destination) {
        int n=maze.size();
        int m=maze[0].size();
        vector<int> visited(n*m);
        priority_queue<pair<int,int>,vector<pair<int,int>>,comapre> q;
        int levelaa=0;
        q.push({start[0]*m+start[1],0});
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int temp=q.top().first;
                int tot=q.top().second;
                q.pop();
                int row=temp/m;
                int col=temp%m;
                if(row==destination[0] and col==destination[1]){
                    return tot;
                }
                if(visited[temp]){
                    continue;
                }
                visited[temp]=true;
                //the ball travel in four directions
                //we can also traverl the directions
                //by using the radius formula traveal
                //all four directions at once
                int i=row;
                int j=col;
                int count=0;
                while(j<maze[0].size()-1 and maze[i][j]!=1 ){
                    count++;
                    j++;
                }
                if(maze[i][j]==1){
                    if(!visited[i*m+(j-1)])
                    q.push({i*m+(j-1),tot+count-1});
                }else{
                    if(!visited[i*m+j])
                    q.push({i*m+j,tot+count});
                }
                j=col;
                count=0;
                while(j>0 and maze[i][j]!=1){
                    j--;
                    count++;
                }
                if(maze[i][j]==1){
                    if(!visited[i*m+(j+1)])
                    q.push({i*m+(j+1),tot+count-1});
                }else {
                    if(!visited[i*m+j])
                    q.push({i*m+j,tot+count});
                }
                j=col;
                count=0;
                while(i<maze.size()-1 and maze[i][j]!=1){
                    i++;
                    count++;
                }
                if(maze[i][j]==1){
                    if(!visited[(i-1)*m+j])
                    q.push({(i-1)*m+j,tot+count-1});
                }else{
                    if(!visited[i*m+j])
                    q.push({i*m+j,tot+count});
                }
                i=row;
                count=0;
                while(i>0 and maze[i][j]!=1){
                    count++;
                    i--;
                }
                if(maze[i][j]==1){
                    if(!visited[(i+1)*m+j])
                    q.push({(i+1)*m+j,tot+count-1});
                }else{
                    if(!visited[i*m+j])
                    q.push({i*m+j,tot+count});
                }
            }
        }
        return -1;
    }
};