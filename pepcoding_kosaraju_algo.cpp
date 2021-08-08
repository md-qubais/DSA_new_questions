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
//strongly connected components => jaha par bhi cycle mile
//usse replace karke ek vertex maansakte hoo usse strongly connected
//componenets

//it just converts the cyclic connected graphs to
//ascyclic connected graphs
//we just convert the cycle graph to one single compoenet
//we are just reducing the cycle into vertex

//alog below
//1->topo order
//2->graph  ! complement vice versa all edges or graph inverse
//3->dfs topo order

int32_t main(){
	qubais_judge;
	IOS;
	return 0;
}