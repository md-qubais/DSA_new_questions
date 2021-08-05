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
//dijkistras and bellamon ford work on the same thing
//djkistras and bellman work same  things single source shortest path with minimum weight
//but dj wont work on negative edges
//and bellman ford will work on negative edges
//djkstras will give infinite cycle if we perform source to destination
//min cost shortest path in negative edges means sometime 
//or sometimes it will give answer based on the graph
//it doesnt know that to do so we use bellman ford
//its like dynamic programming and its a topic of dynamic programming
//we can use bellman ford algorithm in problems
//like cheapest flight within k stops in leetcode
class Solution{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<int> prev(n+1);
        for(auto&it:prev){
            it=INT_MAX;
        }
        prev[src]=0;
        //perfoming atmax how many edges or stops 
        //or nodes that we can use
        for(int i=1;i<=k+1;i++){
            bool anyupdates=false;//this is for
            //negative detection of the cycle
            //if any changes performed after checking all
            //the valid edges if we get anypath
            //that is agin min than current path while
            //all n-1 edges are covered than there is 
            //negative cycle using bellman_ford

            //here we making a copy of prev array
            //to maintain the minimum if we get any minimum
            //we will change it
            vector<int> curr=prev;
            for(auto&it:flights){
                int u=it[0],v=it[1],w=it[2];
                if(prev[u]!=INT_MAX and prev[u]+w < curr[v]){
                    curr[v]=prev[u]+w;
                    anyupdates=true;
                }
            }
            if(i==(k+1) and anyupdates){
           //     cout<<"here negative cycle detected"<<endl;
            }
            prev=curr;
        }
        return prev[dst]==INT_MAX?-1:prev[dst];
    }
};

int32_t main(){
	qubais_judge;
	IOS;
	return 0;
}