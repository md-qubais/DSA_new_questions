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
			leaders[l2]=leaders[l1];
		}else{
			size[l2]+=size[l1];
			leaders[l1]=leaders[l2];
		}
	}
	long minCost(int n,vector<vector<int>>&allcities){
		for(int i=1;i<=n;i++){
			leaders[i]=i;
			size[i]=1;
		}
		long ans=0;
		for(int i=0;i<allcities.size();i++){
			int u=allcities[i][0],v=allcities[i][1],w=allcities[i][2];
			int l1=getLeader(leaders[u]);
			int l2=getLeader(leaders[v]);
			if(l1!=l2){
				Union(l1,l2);
				ans+=w;
			}
		}
		return ans;
	}
};
bool compare(vector<int>&arr1,vector<int>&arr2){
	return arr1[arr1.size()-1]<arr2[arr2.size()-1];
}
long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>>&cities) {
	vector<vector<int>> allcities;
	for(int i=0;i<cities.size();i++){
		allcities.push_back(cities[i]);
		allcities[i].push_back(c_road);

	}
	for(int i=1;i<=n;i++){
		vector<int> temp;
		temp.push_back(0);
		temp.push_back(i);
		temp.push_back(c_lib);
		allcities.push_back(temp);
	}
	sort(allcities.begin(),allcities.end(),compare);
	Graph g;
	return g.minCost(n,allcities);
}
int32_t main(){
	qubais_judge;
	IOS;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m;
		cin>>m;
		int clib;
		cin>>clib;
		int croad;
		cin>>croad;
		vector<vector<int>> cities;
		for(int i=0;i<m;i++){
			vector<int> temp(2);
			cin>>temp[0]>>temp[1];
			cities.push_back(temp);
		}
		cout<<(long)roadsAndLibraries(n,clib,croad,cities)<<endl;
	}
	return 0;
}