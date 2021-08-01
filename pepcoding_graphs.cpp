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
class compare_to{
public:
    bool operator()(pair<int,pair<int,int>> p1,pair<int,pair<int,int>> p2){
        return p1.second.second>p2.second.second;
    }
};

class compare{
public:
    bool operator()(pair<int,pair<int,string>> p1,pair<int,pair<int,string>> p2){
        if(p1.second.first==p2.second.first){
            if(p1.first==p2.first){
                return p1.second.second.length()<p2.second.second.length();
            }
            return p1.first>p2.first;
        }
        return p1.second.first>p2.second.first;
    }
};


template<class T>
class Graph{
public:
	map<T,list<pair<T,int>>> l;
	void add_edge(T src,T dest,int dist=-1,bool bdir=true){
		l[src].pb({dest,dist});
		if(bdir) l[dest].pb({src,dist});
	}

	void print(){
		for(auto&node:l){
			cout<<node.first<<"->";
			for(auto&neighbours:l[node.first]){
				cout<<"("<<neighbours.first<<" "<<neighbours.second<<")"<<", ";
			}
			cout<<endl;
		}
	}

	bool src_to_dest_helper(T src,T dest,unordered_map<T,bool> &visited){
		if(src==dest) return true;
		visited[src]=true;
		for(auto&neighbours:l[src]){
			bool reached=false;
			if(!visited[neighbours.first]) reached=src_to_dest_helper(neighbours.first,dest,visited);
			if(reached) return true;
		}
		return false;
	}

	bool src_to_dest(T src,T dest){
		unordered_map<T,bool> visited;
		return src_to_dest_helper(src,dest,visited);
	}

	void all_paths_from_source_to_destination_helper(T src,T dest,unordered_map<T,bool>&visited,string path){
		if(src==dest){
			path+=to_string(src);
			cout<<path<<endl;
			return;
		}
		visited[src]=true;
		for(auto&neighbours:l[src]){
			if(!visited[neighbours.first]) all_paths_from_source_to_destination_helper(neighbours.first,dest,visited,path+to_string(src));
		}
		visited[src]=false;
	}

	void all_paths_from_source_to_destination(T src,T dest){
		unordered_map<T,bool> visited;
		all_paths_from_source_to_destination_helper(src,dest,visited,"");
	}

	void is_connected_helper(T src,unordered_map<T,bool>&visited){
		visited[src]=true;
		for(auto&neighbours:l[src]){
			if(!visited[neighbours.first]) is_connected_helper(neighbours.first,visited);
		}
	}

	bool is_connected(){
		unordered_map<T,bool> visited;
		is_connected_helper(0,visited);
		for(auto&it:l){
			for(auto&neighbours:l[it.first]){
				if(!visited[neighbours.first]) return false;
			}
		}
		return true;
	}

	void get_connected_components_helper(T src,vector<int>&temp,unordered_map<T,bool>&visited){
		temp.push_back(src);
		visited[src]=true;
		for(auto&it:l[src]){
			if(!visited[it.first]) get_connected_components_helper(it.first,temp,visited);
		}
	}

	vector<vector<int>> get_connected_components(){
		unordered_map<T,bool> visited;
		vector<vector<int>> ans;
		for(auto list:l){
			vector<int> temp;
			if(!visited[list.first]){
				get_connected_components_helper(list.first,temp,visited);
			if(temp.size()>0)  ans.push_back(temp);
			}
		}
		return ans;
	}
	
	void clear_path(vector<vector<int>>&grid,int i,int j,bool visited[1000][1000]){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[i].size() or grid[i][j]!=0){
            return;
        }
        //if the node is visited dont explore the paths
        if(visited[i][j]) return;
        //if the node is not visited then mark it as visited
        visited[i][j]=true;
        //explore all paths
        clear_path(grid,i+1,j,visited);
        clear_path(grid,i,j+1,visited);
        clear_path(grid,i-1,j,visited);
        clear_path(grid,i,j-1,visited);
    }
    int numIslands(vector<vector<int>>& grid){
        int count=0;
        bool visited[1000][1000]={false};
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0 and !visited[i][j]){
                    count++;
                    clear_path(grid,i,j,visited);
                }
            }
        }
        return count;
    }

    void travel_and_store(int src,vector<int>&temp,unordered_map<int,bool>&visited){
    	visited[src]=true;
    	temp.push_back(src);
    	for(auto&neighbours:l[src]){
    		if(!visited[neighbours.first]) travel_and_store(neighbours.first,temp,visited);
    	}

    }

    int perfect_friends(){
    	vector<vector<int>> comps;
    	unordered_map<int,bool> visited;
    	int tot=0;
    	for(auto&nodes:l){
    			vector<int> temp;
    			if(!visited[nodes.first]){
    				travel_and_store(nodes.first,temp,visited);
    				comps.push_back(temp);
    			}
    		}
    		for(int i=0;i<comps.size();i++){
    			for(int j=i+1;j<comps.size();j++){
    				tot+=comps[i].size()*comps[j].size();
    			}
    		}
    	return tot;
    }

    void hamiltonian(int src,int oscr,unordered_map<int,bool>&visited,int len,string psf){
    	if(len==l.size()){
    		cout<<psf;
    		bool is_cycle=false;
    		for(auto&it:l[oscr]){
    			if(it.first==src){
    				is_cycle=true;
    				break;
    			}
    		}
    		if(is_cycle){
    			cout<<"*"<<endl;
    		}else{
    			cout<<"."<<endl;
    		}
    		return;
    	}
    	visited[src]=true;
    	for(auto&it:l[src]){
    		if(!visited[it.first]){	
    			hamiltonian(it.first,oscr,visited,len+1,psf+to_string(it.first));
    		}
    	}
    	visited[src]=false;
    }
    	
    void hamiltonian_path_and_cycle(int src){
    	unordered_map<int,bool> visited;
    	hamiltonian(src,src,visited,1,to_string(src));
    }

    void bfs(int src){
    	queue<pair<int,string>> q;
    	unordered_map<int,bool> visited;
        string psf="";
    	psf+=to_string(src);
    	q.push({src,psf});
    	visited[src]=true;
    	while(!q.empty()){
    		pair<int,string> p=q.front();
    		cout<<p.first<<"@"<<p.second<<endl;
    		q.pop();
    		for(auto&it:l[p.first]){
    			if(!visited[it.first]){
    				visited[it.first]=true;
    				q.push({it.first,p.second+to_string(it.first)});
    			}
    		}
    	}
    }


    bool is_cyclic_helper(int src,unordered_map<int,bool>&visited){
    	queue<int> q;
    	q.push(src);
    	while(!q.empty()){
    		int num=q.front();
    		q.pop();
    		if(visited[num]){
    			return true;
    		}
    		visited[num]=true;
    		for(auto&it:l[num]){ 
    			if(!visited[it.first])
    			q.push(it.first);
    		}
    	}
    	return false;
    }

    bool is_cyclic(){
    	unordered_map<int,bool> visited;
    	for(auto&it:l){
    		if(!visited[it.first]){
    			if(is_cyclic_helper(it.first,visited)){
    				return true;
    			}
    		}
    	}
    	return false;
    }

    bool is_bipatite(int src,unordered_map<int,bool>&visited){
    	queue<pair<int,int>> q;
    	q.push({src,1});
    	unordered_map<int,int> Set;
    	while(!q.empty()){
    		pair<int,int> p=q.front();
    		visited[p.first]=true;
    		q.pop();
    		if(Set[p.first]!=0){
    			if(Set[p.first]!=p.second){
    				return false;
    			}
    		}
    		else Set[p.first]=p.second;
    		for(auto&it:l[p.first]){
    			if(Set[it.first]==0){
    				if(p.second==1){
    					q.push({it.first,2});
    				}else{
    					q.push({it.first,1});
    				}
    			}
    		}
    	}
    	return true;
    }

    bool is_bipatite(){
    	unordered_map<int,bool> visited;
    	for(auto&it:l){
    		if(!visited[it.first]){
    			if(!is_bipatite(it.first,visited)){
    				return false;
    			}
    		}
    	}
    	return true;
    }

    int spread_infection(int src,int t){
        queue<pair<int,int>> q;
        q.push({src,0});
        int count=0;
        unordered_map<int,bool> visited;
        while(!q.empty()){
            pair<int,int> temp=q.front();
            q.pop();
            if(temp.second==t){
                break;
            }
            if(visited[temp.first]){
                continue;
            }
            count++;
            visited[temp.first]=true;
            for(auto&it:l[temp.first]){
                if(!visited[it.first]) q.push({it.first,temp.second+1});
            }
        }
        return count;
    }

    //if we want all nodes to be connected then use prims for min cost
    //if we dont want all nodes to be connected then use djkistras for min cost 


    //djkistras algorithms;
    //it wont work on negative values
    void shorted_path_weighted_graph(int src){
        priority_queue<pair<int,pair<int,string>>,vector<pair<int,pair<int,string>>>,compare> pq;
        unordered_map<int,bool> visited;
        pq.push({src,{0,to_string(src)}});
        while(!pq.empty()){
            pair<int,pair<int,string>> temp=pq.top();
            pq.pop();
            if(visited[temp.first]){
                continue;
            }
            cout<<temp.first<<" via "<<temp.second.second<<" @ "<<temp.second.first<<endl;
            visited[temp.first]=true;
            for(auto&it:l[temp.first]){
                if(!visited[it.first]){
                    pq.push({it.first,{it.second+temp.second.first,temp.second.second+to_string(it.first)}});
                }
            }
        }
    }
    //here below is the prims algo and difference
    //between prims and kruskals

    //the prims algo state that just take one min 
    //edge and first do operation on that min edge
    //and take next minimum edge that is connected
    //to that already taken edge and that min edge
    //must  be connected to already taken edge
    //and there must be no cyle present
    //in it and if it is visited already avoid that edge
    //ds stack->priority queue,visited hashmap,pair<src,dest>


    //but in kruskal you can take any min edge and start
    //traversing and start connected to it and making graph
    //and after take any min edge and start connecting
    //but this only works if we are using union find algo
    //because union find states that we must not create 
    //any cycle so this kruskal is valid only for 
    //union find
    //ds stack->sort edges based on weight,union find algo

    //prims minimum spanning tree
    //minimum edges to visit all nodes
    void min_wire_required(){
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare_to> pq;
        unordered_map<int,bool> visited;
        pq.push({0,{-1,0}});
        pair<int,pair<int,int>> temp=pq.top();
        pq.pop();
        visited[temp.first]=true;
        for(auto&it:l[temp.first]){
            pq.push({it.first,{temp.first,it.second}});
        }
        while(!pq.empty()){
            temp=pq.top();
            pq.pop();
            if(visited[temp.first]){
                continue;
            }
            visited[temp.first]=true;
            cout<<"["<<temp.first<<"-"<<temp.second.first<<"@"<<temp.second.second<<"]"<<endl;
            for(auto&it:l[temp.first]){
                if(!visited[it.first]) pq.push({it.first,{temp.first,it.second}});
            }
        }
    }
    stack<int> s;
    //topological sort
    //we must mark all the nodes and its corresponding edges
    //as directional not bidirectional edges
    //not cyclic graph but DAG directed acyclic graph
    void topological_sort(int src,unordered_map<int,bool>&visited){
        visited[src]=true;
        for(auto&it:l[src]){
            if(!visited[it.first]) topological_sort(it.first,visited);
        }
        s.push(src);
    }
    void order_of_compilation(){
        unordered_map<int,bool> visited;
        for(auto&it:l){
            if(!visited[it.first]) topological_sort(it.first,visited);
        }
        while(!s.empty()){
            cout<<s.top()<<endl;
            s.pop();
        }
    }
    //just replace bfs queue with stack
    //then we will get iterative dfs traversal of
    //the tree
    void iterative_dfs(int src){
        stack<pair<int,string>> s;
        unordered_map<int,bool> visited;
        s.push({src,to_string(src)});
        while(!s.empty()){
            pair<int,string> temp=s.top();
            s.pop();
            if(visited[temp.first]){
                continue;
            }
            cout<<temp.first<<"@"<<temp.second<<endl;
            visited[temp.first]=true;
            for(auto&it:l[temp.first]){
                if(!visited[it.first])
                s.push({it.first,temp.second+to_string(it.first)});
            }
        }
    }
    
};

int32_t main(){
	qubais_judge;
    IOS;
	Graph<int> g;
	int nodes,edges;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++){
		int n1,n2,n3;
		cin>>n1>>n2>>n3;
		g.add_edge(n1,n2,n3);
	}
    int src;
    cin>>src;
    g.iterative_dfs(src);
    return 0;
}