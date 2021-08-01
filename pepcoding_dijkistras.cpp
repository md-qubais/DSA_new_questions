#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
#define endl "\n"
#define pb push_back
#define p push
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin);freopen("output.txt","w",stdout)
using namespace std;
class Pair{
public:
	int vertex;
	int parent;
	int curr_w;
	int wsf;
	Pair(int vertex,int parent,int curr_w,int wsf){
		this->vertex=vertex;
		this->parent=parent;
		this->curr_w=curr_w;
		this->wsf=wsf;
	}
	Pair(int vertex,int parent,int wsf){
		this->vertex=vertex;
		this->parent=parent;
		this->wsf=wsf;
	}
};
class compare{
public:
	bool operator()(Pair p1,Pair p2){
		return p1.wsf > p2.wsf;
	}
};
class PrimsPair{
public:
	int vertex;
	int curr_wt;
	PrimsPair(int vertex,int curr_wt){
		this->vertex=vertex;
		this->curr_wt=curr_wt;
	} 
};
class Primscompare{
public:
	bool operator()(PrimsPair p1,PrimsPair p2){
		return p1.curr_wt > p2.curr_wt;
	}
};
//dijkistras doesnt gurnatee mst->minimum spanning tree
//but it gurantees spanning tree->graph with no cycle
//sometimes it can able to generate MST
//spanning tree means no cycle and one node contains only single
//parent and one nodes can have many childrens
//here in dijkstras we always compare with the total weight 
//of all the edges
//if we need from a particular source to destination
//in min cost so we use dijkstras algorithm
//we we wanted all connected nodes or all connected roads
//we wanted to travel all the ciities that are connected
//but all must be connected then we must use prims or krushkals
//prims and krushkals both give us MST
//but we can start with any node in prims 
//and we must start with the smallest edge weight in krushkals
//and rest algo is same in both
class Graph{
public:
	unordered_map<int,list<pair<int,int>>> l;
	void add_edge(int u,int v,int w){
		l[u].push_back({v,w});
		l[v].push_back({u,w});
	}
	//dijkistras algo time complexity is best-> if we use avl->O(ElogV)
	//worst O(ElogE)
	//for dense graph use prims
	//for partial or sparese graph using krushkals or can be used prims
	//always prims is good
	//whatever will be the scenario use prims if we have to inplement the graph
	//isme prims me graph banewa milna chaiye if not we need to create the graph
	//krushkal dont need a complete graph if given only edge use krushakals than good
	//kruskal dont need graph it can be work only on the basis of edges
	void dijkistras_01(vector<vector<int>>&edge,int src){
		l.clear();
		for(int i=0;i<edge.size();i++){
			add_edge(edge[i][0],edge[i][1],edge[i][2]);
		}
		priority_queue<Pair,vector<Pair>,compare> pq;
		unordered_map<int,int> min_cost_dest;
		unordered_map<int,int> parent;
		unordered_map<int,bool> visited;
		pq.push(Pair(src,-1,0,0));
		while(!pq.empty()){
			Pair temp=pq.top();
			pq.pop();
			if(visited[temp.vertex]){
				continue;
			}
			visited[temp.vertex]=true;
			min_cost_dest[temp.vertex]=temp.wsf;
			//we can find the complete path from
			//the parent vertex
			//by repeatedly calling the parent till the parent 
			//becomes -1 ->we will get the pure path shortest
			//min cost weight path
			parent[temp.vertex]=temp.parent;
			for(auto&it:l[temp.vertex]){
				if(!visited[it.first]){
					pq.push(Pair(it.first,temp.vertex,it.second,temp.wsf+it.second));
				}
			}
		}
		int num=0;
		cout<<min_cost_dest[num]<<endl;
		while(parent[num]!=-1){
			cout<<parent[num]<<endl;
			num=parent[num];
		}	
	}
	void dijkistras_02(int n,vector<vector<int>>&edge,int src){
		l.clear();
		for(int i=0;i<edge.size();i++){
			add_edge(edge[i][0],edge[i][1],edge[i][2]);
		}
		queue<Pair> q;
		unordered_map<int,int> min_cost_dest;
		unordered_map<int,int> parent;
		for(int i=0;i<n;i++){
			min_cost_dest[i]=INT_MAX;
			parent[i]=-1;
		}
		q.push(Pair(src,-1,0));
		while(!q.empty()){
			Pair temp=q.front();
			q.pop();
			if(min_cost_dest[temp.vertex]<=temp.wsf){
				continue;
			}
			min_cost_dest[temp.vertex]=min(min_cost_dest[temp.vertex],temp.wsf);
			if(temp.parent!=-1){
				parent[temp.vertex]=temp.parent;
			}
			for(auto&it:l[temp.vertex]){
				if(it.second+temp.wsf < min_cost_dest[it.first]){
					q.push(Pair(it.first,temp.vertex,it.second+temp.wsf));
				}
			}
		}
		int num=0;
		cout<<min_cost_dest[0]<<endl;
		while(parent[num]!=-1){
			cout<<parent[num]<<endl;
			num=parent[num];
		}		
	}



	//time complex ElogE
	//but some edges are eliminated through visited
	//array so acutal time complex ElogV
	//we are travelling edges so E and we are computing vertices log time so logV
	//tot time complexity is O(ElogV)
	void prims(int n,vector<vector<int>>&edge){
		l.clear();
		for(int i=0;i<edge.size();i++){
			add_edge(edge[i][0],edge[i][1],edge[i][2]);
		}
		priority_queue<PrimsPair,vector<PrimsPair>,Primscompare> pq;
		unordered_map<int,bool> visited;
		pq.push(PrimsPair(0,0));
		int tot=0;
		while(!pq.empty()){
			PrimsPair temp=pq.top();
			pq.pop();
			if(visited[temp.vertex]){
				continue;
			}
			visited[temp.vertex]=true;
			tot+=temp.curr_wt;
			for(auto&it:l[temp.vertex]){
				if(!visited[it.first]){
					pq.push(PrimsPair(it.first,it.second));
				}
			}
		}
		cout<<"total cost connecting all the cities using prims=>"<<tot<<endl;
	}
};


int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<vector<int>> edges(n);
	for(auto&it:edges){
		it.resize(3);
	}
	for(int i=0;i<n;i++){
		cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
	}
	int no;
	cin>>no;
	Graph g;
	//g.dijkistras_01(edges,4);
	//g.dijkistras_02(no,edges,4);
	g.prims(no,edges);
	return 0;
};