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
	void Union(int l1,int l2){
		if(size[l1]>=size[l2]){
			size[l1]+=size[l2];
			leaders[l2]=l1;
		}else{
			size[l2]+=size[l1];
			leaders[l1]=l2;
		}
	}
	int mr_president(int n,vector<vector<int>>&roads,int k){
		sort(roads.begin(),roads.end(),compare);
		for(int i=1;i<=n;i++){
			leaders[i]=i;
			size[i]=1;
		}
		int mSum=0;
		int sRoad=0;
		vector<int> temp;

		for(int i=0;i<roads.size();i++){
			int u=roads[i][0],v=roads[i][1],w=roads[i][2];
			int l1=getLeader(leaders[u]);
			int l2=getLeader(leaders[v]);
			if(l1!=l2){
				temp.push_back(w);
				mSum+=w;
				Union(l1,l2);
				n--;
			}
		}
		if(n>1){
			return -1;
		}
		int i=temp.size()-1;
		while(i>=0 and mSum>k){
			mSum-=temp[i--]+1;
			sRoad++;
		}
		if(mSum>k or sRoad>k){
			return -1;
		}
		return sRoad;
	}
};
int32_t main(){
	qubais_judge;
	IOS;
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> roads(m);
	for(int i=0;i<m;i++){
		vector<int> temp(3);
		cin>>temp[0]>>temp[1]>>temp[2];
		roads[i]=temp;
	}
	Graph g;
	cout<<g.mr_president(n,roads,k);
	return 0;
}