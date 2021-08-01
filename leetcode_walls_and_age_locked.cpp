//https://www.lintcode.com/problem/663/
//https://leetcode.com/problems/walls-and-gates/

class Solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        int n=rooms.size();
        int m=rooms[0].size();
        int index=0;
        queue<int> q;
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                if(rooms[i][j]==0){
                    q.push(index);
                }
                index++;
            }
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int idx=q.front();
                q.pop();
                int row=idx/m;
                int col=idx%m;
                int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
                for(int k=0;k<4;k++){
                    int r=row+dir[k][0];
                    int c=col+dir[k][1];
                    if(r<0 or c<0 or r>=rooms.size() or c>=rooms[r].size() or rooms[r][c]!=INT_MAX ){
                        continue;
                    }
                    rooms[r][c]=rooms[row][col]+1;
                    q.push(r*m+c);
                }
            }
        }
    }
};