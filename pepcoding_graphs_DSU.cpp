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
    //DSU for detection the cycle in the DAG
    //Directed Acyclic Graph
    unordered_map<int,int> leader;
    unordered_map<int,int> size;   
    unordered_map<int,list<int>> l;
    void add_edge(int u,int v){
        l[u].push_back(v);
    }
    int get_leader(int num){
        if(leader[num]==num){
            return num;
        }
        //this below step is path comperssion
        return leader[num]=get_leader(leader[num]);
    }
    void Union(int p1,int p2){
        if(size[p1]>=size[p2]){
            //we just talk with the leader
            //that why we are using 
            //size[p1] or getLeader(arr[i][0])
            //instead of just using size[arr[i][0]]
            //it violates the DSU rule
            //the DSU rule is we just talk about
            //the leader instead of civlian
            //that is the main thing in DSU
            //just add the size of leader of particular
            //component to another leader size of another
            //components
            size[p1]+=size[p2];
            leader[p2]=p1;
        }else{
            size[p2]+=size[p1];
            leader[p1]=p2;
        }
    }
    bool DSU(int n,vector<vector<int>>&arr){
        for(int i=0;i<n;i++){
            leader[i]=i;
            size[i]=1;
        }
        for(int i=0;i<arr.size();i++){
            int p1=get_leader(arr[i][0]);
            int p2=get_leader(arr[i][1]);
            //here if u and v means 
            //the leader of arr[i][0]
            //and the leader of arr[i][1]
            //than we must not connect an edge
            //between arr[i][0] and arr[i][1]
            //if we connect than if makes a cycle
            //but we have to make directed acyclic graph
            if(u==v){
                continue;
            }
            //here below we are performing UNION


            //and here if we are always merging
            //than make components-- that leads
            //to giving us components that 
            //can be formed in the entire graph
            Union(p1,p2);
            add_edge(arr[i][0],arr[i][1]);
        }
     
    }
};
int32_t main(){
    qubais_judge;
    IOS;
    return 0;
}
