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
//hamiltonian path=>visit all the vertex exaclty one

//eulerain path=>visit all edges exactly one time
//eulerain circuit=>visit all edges exactly one time and 
//come back to the statred vertex means start and end point should be same
//if eulerain circuit then it will eulerain path
//vice versa not possible


//another alogs for directed and undirected graphs

//Undirected graph eulerian circuit and eulerian path
//for eulerain circuit if degree is even then eulerian circuit
//for eulerain  path n-2 ki degree even honi chaiye and || 2 odd degree 



//directed graph eulerian circuit and eulerian path
//for eulerain circuit if indegree is equals to outdegree its eulerian circuit

//for eulerain path n-2 nodes (indgree and outdegree must be equal)
//and from that two remaining nodes there must exist
//one indegree of the first node that is greater than its outdegree
//and one outdegree of the second node that is greater than its indegree


int32_t main(){
	qubais_judge;
	IOS;
	return 0;
}