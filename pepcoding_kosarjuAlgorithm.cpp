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
class Graph{
public:
	unordered_map<int,list<int>> l;
	void add_edge(int u,int v){
		l[u].push_back(v);
	}
	void create_graph(vector<vector<int>>&edges){
		for(int i=0;i<edges.size();i++){
			int u=edges[i][0],v=edges[i][1];
			add_edge(u,v);
		}
	}
	void dfs(int src,unordered_map<int,bool>&visited,stack<int>&st){
		visited[src]=true;
		for(auto&it:l[src]){
			if(!visited[it]){
				dfs(it,visited,st);
			}
		}
		st.push(src);
	}
	void visit_all(int src,unordered_map<int,bool>&visited){
		visited[src]=true;
		for(auto&it:l[src]){
			if(!visited[it]){
				visit_all(it,visited);
			}
		}
	}
	int StronglyConnectedComponents(vector<vector<int>>&edges){
		int count=0;
		//first perform dfs and store in the stack
		unordered_map<int,bool> visited;
		stack<int> st;
		for(auto&it:l){
			if(!visited[it.first]){
				dfs(it.first,visited,st);
			}
		}
		l.clear();
		visited.clear();
		for(int i=0;i<edges.size();i++){
			int u=edges[i][0],v=edges[i][1];
			add_edge(v,u);
		}
		while(!st.empty()){
			if(!visited[st.top()]){
				count++;
				visit_all(st.top(),visited);
			}
			st.pop();
		}
		return count;
	}
};


//the only problem in the kosaraju algorithm is the problamatic edge
//first->fill the stack with random order dfs at the time of backtracking
//second->reverse all the edges of the graphs
//and then again call the dfs from that given stack so we can
//get the strongly connected components in the graph
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	int e;
	cin>>e;
	Graph g;
	vector<vector<int>> edges(6);
	for(auto&it:edges){
		it.resize(2);
		cin>>it[0]>>it[1];
	} 
	g.create_graph(edges);
	cout<<g.StronglyConnectedComponents(edges)<<endl;
	return 0;
}