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
/*
1->faith
2->recursion tree
3->recurion code
4->convert recursion code into memoization
5->observation
6->tabulation
7->optimization
*/
int fib_rec(int n){
	if(n==0 or n==1){
		return n;
	}
	return fib_rec(n-1)+fib_rec(n-2);
}
//just store everything at the time of returning
//and dont recursive call if its already stored and computed
int fib_memo(int n,int *dp){
	if(n==0 or n==1){
		return dp[n]=n;
	}
	if(dp[n]!=-1){
		return dp[n];
	}
	return dp[n]=fib_memo(n-1,dp)+fib_memo(n-2,dp);
}
//just replace the memo code into iterative code
//by just solving the dependencies and some observation
//and replacce return with continue;
int fib_tab(int N,int *dp){
	for(int n=0;n<=N;n++){
		if(n==0 or n==1){
			dp[n]=n;
			continue;
		}
		dp[n]=dp[n-1]+dp[n-2];
		continue;
	}
	return dp[N];
}

//now after tabbulation if we can optimize than
//we should write the optimzied code
//such as in fib we are just depending on two variables
//so faltu ka space kyun lena itna we can just do it
//with two variables using recursive and dp concept
//same tab code but by using two variables
int fib_optimized(int N){
	if(N==0 or N==1){
		return N;
	}
	int a=0,b=1;
	int sum=0;
	for(int n=2;n<=N;n++){
		sum=a+b;
		a=b;
		b=sum;
	}
	return sum;
}
void fib_set(int n,int *dp){
	cout<<fib_rec(n)<<endl;
	cout<<fib_memo(n,dp)<<endl;
	cout<<fib_tab(n,dp)<<endl;
	cout<<fib_optimized(n)<<endl;
}


//maze path right down and diagonal jumps
//only one jump
//count how many ways we can reach from 0,0 to n*m

int mazePath_rec(int n,int m,int i=0,int j=0){
	if(i>=n or j>=m){
		return 0;
	}
	if(i==n-1 and j==m-1){
		return 1;
	}
	return mazePath_rec(n,m,i+1,j)+mazePath_rec(n,m,i,j+1)+mazePath_rec(n,m,i+1,j+1);
}

int mazePath_memo(int n,int m,vector<vector<int>>&dp,int i=0,int j=0){
	if(i>=n or j>=m){
		return 0;
	}
	if(i==n-1 and j==m-1){
		return dp[i][j]=1;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	return dp[i][j]=mazePath_memo(n,m,dp,i+1,j)+mazePath_memo(n,m,dp,i,j+1)+mazePath_memo(n,m,dp,i+1,j+1);
}

int mazePath_tab(int n,int m,vector<vector<int>>&dp){
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(i==n-1 and j==m-1){
				dp[i][j]=1;
				continue;
			}

			if(i+1<n) dp[i][j]+=dp[i+1][j];
			if(j+1<m) dp[i][j]+=dp[i][j+1];
			if(i+1<n and j+1<m) dp[i][j]+=dp[i+1][j+1];
		}
	}
	//because 0,0 stores the answer for n-1,m-1
	//in tabulation approach
	return dp[0][0];
}


void mazePath_set(int n,int m){
	vector<vector<int>> dp(n);
	for(auto&it:dp){
		it.resize(m);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j]=-1;
		}
	}
	cout<<mazePath_rec(n,m)<<endl;
	cout<<mazePath_memo(n,m,dp)<<endl;
	dp.clear();
	dp.resize(n);
	for(auto&it:dp){
		it.resize(m);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			//we are storing zero here because
			//we have to calcuate the no of ways from
			//current to all three directions ie we have
			//to add up
			dp[i][j]=0;
		}
	}
	cout<<mazePath_tab(n,m,dp)<<endl;
}


//we can take infinte number of jumps here
int mazePathVar_rec(int n,int m,int *row_dir,int *col_dir,int i=0,int j=0){
	if(i>=n or j>=m ){
		return 0;
	}
	if(i==n-1 and j==m-1){
		return 1;
	}
	//all three directions jump here
	int count=0;
	for(int k=0;k<3;k++){
		int r=i+row_dir[k];
		int c=j+col_dir[k];
		//here below for infinte jump
		//if current row is increasing than keep on increasing
		//the row and col will be 0
		//if current col is increasing than keep on increasing
		//the col and row will be 0;
		//if current row and current col is increasing than keep
		//on increasing the row and col both will increase by 1 and 1
		while(r<n and c<m){
			count+=mazePathVar_rec(n,m,row_dir,col_dir,r,c);
			r+=row_dir[k];
			c+=col_dir[k];
		}
	}
	return count;
}


int mazePathVar_memo(int n,int m,int *row_dir,int *col_dir,vector<vector<int>>&dp,int i=0,int j=0){
	if(i>=n or j>=m ){
		return 0;
	}
	if(i==n-1 and j==m-1){
		return dp[i][j]=1;
	}
	//all three directions jump here
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int count=0;
	for(int k=0;k<3;k++){
		int r=i+row_dir[k];
		int c=j+col_dir[k];
		//here below for infinte jump
		//if current row is increasing than keep on increasing
		//the row and col will be 0
		//if current col is increasing than keep on increasing
		//the col and row will be 0;
		//if current row and current col is increasing than keep
		//on increasing the row and col both will increase by 1 and 1
		while(r<n and c<m){
			count+=mazePathVar_memo(n,m,row_dir,col_dir,dp,r,c);
			r+=row_dir[k];
			c+=col_dir[k];
		}
	}
	return dp[i][j]=count;
}

int mazePathVar_tab(int n,int m,int *row_dir,int *col_dir,vector<vector<int>>&dp){
	for(int i=n-1;i>=0;i--){
		for(int j=m-1;j>=0;j--){
			if(i==n-1 and j==m-1){
				dp[i][j]=1;
				continue;
			}
			int count=0;
			for(int k=0;k<3;k++){
				int r=i+row_dir[k];
				int c=j+col_dir[k];
				//here below for infinte jump
				//if current row is increasing than keep on increasing
		        //the row and col will be 0
		        //if current col is increasing than keep on increasing
		        //the col and row will be 0;
		        //if current row and current col is increasing than keep
		        //on increasing the row and col both will increase by 1 and 1
		        while(r<n and c<m){
		        	count+=dp[r][c];
		        	r+=row_dir[k];
		        	c+=col_dir[k];
		        }
		    }
		    dp[i][j]=count;
		}
	}
	return dp[0][0];
}


void mazePathVar_set(int n,int m){
	int row_dir[]={1,0,1};
	int col_dir[]={0,1,1};
	cout<<mazePathVar_rec(n,m,row_dir,col_dir)<<endl;
	vector<vector<int>> dp(n);
	for(auto&it:dp){
		it.resize(m);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j]=-1;
		}
	}
	cout<<mazePathVar_memo(n,m,row_dir,col_dir,dp)<<endl;
	dp.clear();
	dp.resize(n);
	for(auto&it:dp){
		it.resize(m);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			dp[i][j]=0;
		}
	}
	cout<<mazePathVar_tab(n,m,row_dir,col_dir,dp)<<endl;
}


class Solution{
public:
	int climbStairs_rec(int n){
		if(n==0){
			return 1; 
		}
		if(n<0){
			return 0;
		}
		return  climbStairs_rec(n-1)+climbStairs_rec(n-2);
	}
	int climbStairs_memo(int n,vector<int>&dp){
		if(n==0){
			return dp[n]=1;
		}
		if(n<0){
			return 0;
		}
		if(dp[n]!=-1){
			return dp[n];
		}
		return dp[n]=climbStairs_memo(n-1,dp)+climbStairs_memo(n-2,dp);
	}
	int climbStairs_tab(int N,vector<int>&dp){
		for(int n=0;n<=N;n++){
			if(n==0){
				dp[n]=1;
				continue;
			}
			int count=0;
			if(n-1>=0){
				count+=dp[n-1];
			}
			if(n-2>=0){
				count+=dp[n-2];
			}
			dp[n]=count;
		}
		return dp[N];
	}
	int climbStairs_optimized(int n){
		int a=1;
		int b=2;
		if(a==n){
			return a;
		}
		if(b==n){
			return b;
		}
		int sum=0;
		for(int i=3;i<=n;i++){
			sum=a+b;
			a=b;
			b=sum;
		}
		return sum;
	}
    int climbStairs(int n) {
    	vector<int> dp(n+1);
    	for(int i=0;i<n+1;i++){
    		dp[i]=0;
    	}
        return climbStairs_optimized(n);
    }
};





int32_t main(){
	qubais_judge;
	IOS;
	int n,m,jumps;
	cin>>n>>m>>jumps;
	mazePathVar_set(n,m);
	return 0;
}