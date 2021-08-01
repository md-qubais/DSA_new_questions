class Graph{
public:
	unordered_map<int,int> leaders;
	unordered_map<int,int> size;
	int getLeader(int n){
		if(n==leaders[n]){
			return n;
		}
		return leaders[n]=getLeader(leaders[n]);
	}
	void Union(int l1,int l2){
		if(size[l1]>=size[l2]){
			size[l1]+=size[l2];
			leaders[l2]=l1;
		}else{
			size[l2]+=size[l1];
			leaders[l1]=l2;
		}
	}
	bool compare(vector<int>&arr1,int vector<int>&arr2){
		return arr1[arr1.size()-1]>arr2[arr2.size()-1];
	}
	int minCost(vector<vector<int>>&roads,vector<int>&machines){
		vector<vector<int>> critical_edges;
		unordered_map<int,bool> isMachine;
		vector<vector<int>> green;
		vector<vector<int>> red;
		for(auto&it:machines){
			isMachine[it]=true;
		}
		for(int i=0;i<roads.size();i++){
			int u=roads[i][0];
			int v=roads[i][1];
			int w=roads[i][2];
			leaders[u]=u;
			leaders[v]=v;
			size[u]=u;
			size[v]=v;
			vector<int> temp(3);
			temp[0]=u;temp[1]=v;temp[2]=w;
			if(!isMachine[u] and !isMachine[v]){
				green.push_back(temp);
				continue;
			}
			if(isMachine[u] and isMachine[v]){
				red.push_back(temp);
			}
			if((!isMachine[u] and isMachine[v]) or (isMachine[u] and !isMachine[v])){
				critical_edges.push_back(temp);
				continue;
			}
		}
		int ans=0;
		for(int i=0;i<green.size();i++){
			int l1=getLeader(leaders[green[i][0]]);
			int l2=getLeader(leaders[green[i][1]]);
			if(l1!=l2){
				Union(l1,l2);
			}
		}
		for(int i=0;i<red.size();i++){
			int l1=getLeader(leaders[red[i][0]]);
			int l2=getLeader(leaders[red[i][1]]);
			if(l1!=l2){
				Union(l1,l2);
			}
		}
		sort(critical_edges.begin(),critical_edges.end(),compare);
		
		return ans;
	}
};
int minTime(vector<vector<int>> roads, vector<int> machines){
	Graph g;
	return g.minCost(roads,machines);
}