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
//for single source


//djikistras==>(E+V)logV worst==> (E+V)logE
//and  V(E+V)logV=> V^3LogV
//for negative dijkistras fail

//har vertex se har vertex the min cost 

//bellman ford EV==>V^3



//V^3 floyd warshall
//floyd warshall is graph algo
//dynamic programming algo
//and it is based on bellman ford algorithm
//just a minor change
//and it also wont work on negative cycle detection
class Graph{
public:
	unordered_map<int,list<pair<int,int>>> l;
	void floyd_warshall(){
		//first convert that graph into matrix
		//2d cycles
		int n;//number of nodes/vertices
		vector<vector<int>> mat(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				mat[i][j]=INT_MAX;
			}
		}
		for(auto&it:l){
			int u=it.first;
			int v=it.second.first;
			int w=it.second.second;
			mat[u][v]=w;
		}
		for(int i=0;i<n;i++){
			mat[i][i]=0;
		}

		//we are going from u to v through k
		//that is the intution of bellman ford algorithm
		for(int k=0;k<4;k++){
			for(int u=0;u<n;u++){
				for(int v=0;v<n;i++){
					mat[u][v]=min(mat[u][v],mat[u][k]+mat[k][v]);
				}
			}
		}
		//we only use floyd warshall algorithm
		//because it can give single souce shortest path
		//from any source to any destiniation
		//unlilke dikjistras and bellam ford just give
		//for one source to destination for weighted graphs




	}
};
int32_t main(){
	qubais_judge;
	IOS;
	return 0;
}
