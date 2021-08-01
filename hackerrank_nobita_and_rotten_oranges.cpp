#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define pb push_back
#define p push
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;
int orangesRotting(vector<vector<int>>& grid) {
	int count=0;
	int rotten_count=0;
    int n=grid.size();
    int m=grid[0].size();
    queue<int> q;
    for(int i=0;i<grid.size();i++){
    	for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==2 or grid[i][j]==3){
            	q.push(i*m+j);
                rotten_count++;
            }else if(grid[i][j]==1){
            	count++;
            }
        }
    }
    if(count==0){
    	return 0;
    }
    if(rotten_count==0){
    	return -1;
    }
    int time=0;
    while(!q.empty()){
    	int size=q.size();
    	while(size--){
    		int idx=q.front();
    		q.pop();
    		int row=idx/m;
    		int col=idx%m;
    		int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    		int dir2[4][2]={{2,0},{-2,0},{0,2},{0,-2}};
    	   if(grid[row][col]==3){
    			grid[row][col]=2;
    			for(int i=0;i<4;i++){
    				int r=row+dir[i][0];
    				int c=col+dir[i][1];
    				if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size()){
    					continue;
    				}
    				if(grid[r][c]==0 or grid[r][c]==2 or grid[r][c]==3){
    					continue;
    				}
    				q.push(r*m+c);
    				grid[r][c]=3;
    				count--;
    				if(count==0){
    					return time+1;
    				}
    			}
    			for(int i=0;i<4;i++){
    				int r=row+dir2[i][0];
    				int c=col+dir2[i][1];
    				if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size()){
    					continue;
    				}
    				if(grid[r][c]==0 or grid[r][c]==2 or grid[r][c]==3){
    					continue;
    				}
    				q.push(r*m+c);
    				grid[r][c]=3;
    				count--;
    				if(count==0){
    					return time+1;
    				}
    			}
    			continue;
    		}
    		for(int i=0;i<4;i++){
    			int r=row+dir[i][0];
    			int c=col+dir[i][1];
    			if(r<0 or c<0 or r>=grid.size() or c>=grid[0].size() or grid[r][c]==0 or grid[r][c]==2){
    				continue;
    			}
    			if(grid[r][c]==3){
    				continue;
    			}
                q.push(r*m+c);
                grid[r][c]=2;
                count--;
                if(count==0){
                	return time+1;
                }
            }
        }
        time++;
    }
    return -1;
}

int32_t main(){
	qubais_judge;
	IOS;
	int rows,cols;
	cin>>rows>>cols;
	vector<vector<int>> mat;
	for(int i=0;i<rows;i++){
		vector<int> temp(cols);
		for(int j=0;j<cols;j++){
			cin>>temp[j];
		}
		mat.push_back(temp);
	}
	cout<<orangesRotting(mat)<<endl;
	return 0;
}