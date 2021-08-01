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

bool compare(vector<int> arr1,vector<int> arr2){
    return arr1[arr1.size()-1]<arr2[arr2.size()-1];
}

//minimum spanning tree
//using krushkal algorithms
class Graph{
public:
    unordered_map<int,int> leader;
    unordered_map<int,int> size;   
    unordered_map<int,list<pair<int,int>>> l;
    void add_edge(int u,int v,int w){
        l[u].push_back(make_pair(v,w));
        l[v].push_back(make_pair(u,w));
    }
    void dispaly(){
        for(auto&it:l){
            cout<<"it.first->";
            cout<<"(";
            for(auto&i:l[it.first]){
                cout<<i.first<<",";
            }
            cout<<")"<<endl;
        }
    }
    int get_leader(int num){
        if(leader[num]==num){
            return num;
        }
        return leader[num]=get_leader(leader[num]);
    }
    void Union(int p1,int p2){
        if(size[p1]>=size[p2]){
            size[p1]+=size[p2];
            leader[p2]=p1;
        }else{
            size[p2]+=size[p1];
            leader[p1]=p2;
        }
    }
    void Union_find(vector<vector<int>>&edge){
        for(int i=0;i<edge.size();i++){
            size[i]=1;
            leader[i]=i;
        }
        for(int i=0;i<edge.size();i++){
            int u=edge[i][1],v=edge[i][2],w=edge[i][3];
            int p1=get_leader(leader[u]);
            int p2=get_leader(leader[v]);
            if(p1!=p2){
                Union(p1,p2);
                add_edge(u,v,w);
            }
        }
    }
    void kruskals_algo(vector<vector<int>>&edge){
        sort(edge.begin(),edge.end(),compare);
        Union_find(edge);
    }
};
int32_t main(){
    qubais_judge;
    IOS;
    return 0;
}

