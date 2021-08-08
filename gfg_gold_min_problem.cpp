#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
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
class Solution{
public:
    int maxGold_rec(int n,int m,int i,int j,int *row_dir,int *col_dir,vector<vector<int>>&grid){
        if(i<0 or j<0 or i>=n or j>=m){
            return 0;
        }
        if(j==m-1){
            return grid[i][j];
        }
        int count=INT_MIN;
        for(int k=0;k<3;k++){
            int r=i+row_dir[k];
            int c=j+col_dir[k];
            count=max(count,maxGold_rec(n,m,r,c,row_dir,col_dir,grid));
        }
        return count+grid[i][j];
    }

    int maxGold_memo(int n,int m,int i,int j,int *row_dir,int *col_dir,vector<vector<int>>&grid,vector<vector<int>>&dp){
        if(i<0 or j<0 or i>=n or j>=m){
            return 0;
        }
        if(j==m-1){
            return dp[i][j]=grid[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int count=INT_MIN;
        for(int k=0;k<3;k++){
            int r=i+row_dir[k];
            int c=j+col_dir[k];
            count=max(count,maxGold_rec(n,m,r,c,row_dir,col_dir,grid));
        }
        return dp[i][j]=count+grid[i][j];
    }

    int maxGold_tab(int n,int m,int *row_dir,int *col_dir,vector<vector<int>>&grid,vector<vector<int>>&dp){
        for(int i=0;i<n;i++){
            dp[i][m-1]=grid[i][m-1];
        }
        for(int j=m-1;j>=0;j--){
            for(int i=n-1;i>=0;i--){
                if(j==m-1){
                    continue;
                }
                int count=0;
                for(int k=0;k<3;k++){
                    int r=i+row_dir[k];
                    int c=j+col_dir[k];
                    if(r<n and c<m and r>=0 and c>=0){
                        count=max(count,dp[r][c]);
                    }
                }
                dp[i][j]=count+grid[i][j];       
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i][0]);
        }
        return ans;
    }
    int maxGold(int n,int m,vector<vector<int>>grid){
        int ans=0;
        int row_dir[]={-1,1,0};
        int col_dir[]={1,1,1};
        vector<vector<int>> dp(n);
        for(auto&it:dp){
            it.resize(m);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=0;
            }
        }
        return maxGold_tab(n,m,row_dir,col_dir,grid,dp);
    }
};

int32_t main(){
    qubais_judge;
    IOS;
    int n,m;
    cin>>n>>m;
    vector<vector<int>> grid(n);
    for(int i=0;i<grid.size();i++){
        grid[i].resize(m);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    Solution s;
    cout<<s.maxGold(n,m,grid)<<endl;
    return 0;
}