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
//task=>do topological sort start with any node
//if there is all left to right edges in topological sort
//then the topological sort is valid and 
//if there is even one edge comming from right to left than
//topological sort is not valid and there is cycle

//topological order states that we can travel almost
//the entire graph or a component of that graph from 
//that starting node
class Edge{
public:
	int v;
	int w;
	Edge(int v,int w){
		this->v=v;
		this->w;
	}
};

class Graph{
public:
	
	unordered_map<int,list<Edge>> l;
	void add_edge(int u,int v,int w=-1){
		l[u].push_back(Edge(v,w));
	}
	//we can parallel execute the task 
	//that are not dependent to any other task
	//that are indepenedent
	//independent in the sense means that indegree is zero
	//or independent can also means if the graphs have outdegree
    //it totally depends on the questions
    //and in some questions its also totally depends
    //on the levels such as min time to complete with dependencies
    //by using BFS that is kahn's algorithm
	void dfs_topological(int src,unordered_map<int,bool>&visited,vector<int>&ans){
		visited[src]=true;
		for(auto&it:l[src]){
			if(!visited[it.v]){
				dfs_topological(it.v,visited,ans);
			}
		}
		ans.push_back(src);
	}

	void dfs(){
		unordered_map<int,bool> visited;
		vector<int> ans;
		for(auto&it:l){
			if(!visited[it.first]){
				dfs_topological(it.first,visited,ans);
			}
		}
		// cout<<"here is the list of the work we have to perform"<<endl;
		// cout<<"in the below order"<<endl;
		// cout<<"the work which is independent and which is "<<endl;
		// cout<<"not depenedent to anywork can be perform "<<endl;
		// cout<<"parallel"<<endl;
		for(auto&it:ans){
			cout<<it<<" ";
		}
		cout<<endl;
	}
    void kahns_algorithm(){
        queue<int> q;
        list<int> ans;
        unordered_map<int,int> indegree;
        for(int i=0;i<7;i++){
            for(auto&it:l[i]){
                indegree[it.v]++;
            }
        }
        for(int i=0;i<7;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int temp=q.front();
                q.pop();
                ans.push_front(temp);
                for(auto&it:l[temp]){
                    indegree[it.v]--;
                    if(indegree[it.v]==0){
                        q.push(it.v);
                    }
                }
            }
        }
        for(auto&it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }

};
int32_t main(){
	qubais_judge;
	IOS;
	vector<int> ans;
	Graph g;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int u,v;
		cin>>u>>v;
		g.add_edge(u,v);
	}
	g.dfs();
    g.kahns_algorithm();
	return 0;
}