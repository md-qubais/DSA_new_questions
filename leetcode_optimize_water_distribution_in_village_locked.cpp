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
bool compare(vector<int>&arr1,vector<int>&arr2){
	return arr1[arr1.size()-1]<arr2[arr2.size()-1];
}
class Graph{
public:
	unordered_map<int,int> leaders;
	unordered_map<int,int> size;
	int getLeader(int num){
		if(num==leaders[num]){
			return num;
		}
		return leaders[num]=getLeader(leaders[num]);
	}
	void Union(int p1,int p2){
		if(size[p1]>=size[p2]){
			size[p1]+=size[p2];
			leaders[p2]=p1;
		}else{
			size[p2]+=size[p1];
			leaders[p1]=p2;
		}
	}
	int kruskal(vector<vector<int>>&allpipes){
		int ans=0;
		for(int i=0;i<allpipes.size();i++){
			int u=allpipes[i][0],v=allpipes[i][1],w=allpipes[i][2];
			int l1=getLeader(leaders[u]);
			int l2=getLeader(leaders[v]);
			if(l1!=l2){
				Union(l1,l2);
				ans+=w;
			}
		}
		return ans;
	}
	int minCostToSupplyWater(int n,vector<int>&wells,vector<vector<int>>&pipes){
		for(int i=0;i<=n;i++){
			leaders[i]=i;
			size[i]=1;
		}
		vector<vector<int>> allpipes;
		for(int i=0;i<pipes.size();i++){
			allpipes.push_back(pipes[i]);
		}
		for(int i=0;i<wells.size();i++){
			vector<int> temp(3);
		    temp[0]=0;
		    temp[1]=i+1;
		    temp[2]=wells[i];
		    allpipes.push_back(temp);
		}
		sort(allpipes.begin(),allpipes.end(),compare);
		return kruskal(allpipes);
	}
};
int32_t main(){
	qubais_judge;
	IOS;
	int n;
	cin>>n;
	vector<int> wells(n);
	for(int i=0;i<n;i++){
		cin>>wells[i];
	}
	int m;
	cin>>m;
	vector<vector<int>> pipes(m);
	for(int i=0;i<m;i++){
		vector<int> temp(3);
		cin>>temp[0]>>temp[1]>>temp[2];
		pipes[i]=temp;
	}
	Graph g;
	cout<<g.minCostToSupplyWater(n,wells,pipes);
	return 0;
}