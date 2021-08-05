class Pair{
public:
    int vertex;
    int cost;
    Pair(int vertex,int cost){
        this->vertex=vertex;
        this->cost=cost;
    }
};
class compare{
public:
    bool operator()(Pair p1,Pair p2){
        return p1.cost > p2.cost;
    }
};
class Graph{
public:
    unordered_map<int,list<Pair>> l;
    void add_edge(int u,int v,int w){
        l[u].push_back(Pair(v,w));
    }
    int tot_time(int n,int src){
        unordered_map<int,bool> visited;
        priority_queue<Pair,vector<Pair>,compare> pq;
        int ans=-1;
        pq.push(Pair(src,0));
        while(!pq.empty()){
            Pair temp=pq.top();
            pq.pop();
            if(visited[temp.vertex]){
                continue;
            }
            visited[temp.vertex]=true;
            n--;
            ans=max(ans,temp.cost);
            for(auto&it:l[temp.vertex]){
                if(!visited[it.vertex]){
                    pq.push(Pair(it.vertex,it.cost+temp.cost));
                }
            }
        }
        return n>0?-1:ans;
    }
};
class Solution{
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k){
        Graph g;
        for(int i=0;i<times.size();i++){
            g.add_edge(times[i][0],times[i][1],times[i][2]);
        }
        return g.tot_time(n,k);
    }
};