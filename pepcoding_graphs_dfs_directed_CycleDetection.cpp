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
class Graph{
public:
	unordered_map<int,list<int>> l;
	void add_edge(int u,int v){
		l[u].push_back(v);
	}
	bool CycleDetection1(int src,unordered_map<int,bool>&vis,unordered_map<int,bool>&path){
		vis[src]=true;
		path[src]=true;
		for(auto&it:l[src]){
			if(!vis[it]){
				if(CycleDetection1(it,vis,path)){
					return true;
				}
			}else if(path[it]){
				return true;
			}
		}
		path[src]=false;
		return false;
	}
};
int32_t main(){
	qubais_judge;
	IOS;
	return 0;
}