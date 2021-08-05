class Pair{
public:
    int vertex;
    int cost;
    int k;
    Pair(int vertex,int cost,int k=0){
        this->vertex=vertex;
        this->cost=cost;
        this->k=k;
    }
};
class compare{
public:
    bool operator()(Pair p1,Pair p2){
        return p1.cost>p2.cost;
    }
};
class Graph{
public:
    vector<list<Pair>> l;
    void add_edge(int u,int v,int w){
        l[u].push_back(Pair(v,w));
    }
    int tot_time(int n,int src,int dest,int k){
        priority_queue<Pair,vector<Pair>,compare> pq;
        vector<int> stops(n);
        for(auto&it:stops){
            it=0;
        }
        pq.push(Pair(src,0,k));
        while(!pq.empty()){
            Pair temp=pq.top();
            pq.pop();
            if((temp.k)<0){
                if(temp.vertex==dest){
                    return temp.cost;
                }
                continue;
            }
            if(temp.vertex==dest) return temp.cost;
            if(temp.k < stops[temp.vertex]){
                continue;
            }
            stops[temp.vertex]=temp.k;
            for(auto&it:l[temp.vertex]){
                pq.push({it.vertex,it.cost+temp.cost,temp.k-1});
            }          
        }
        return -1;
    }
};
class Solution{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        Graph g;
        g.l.resize(n);
        for(int i=0;i<flights.size();i++){
            g.add_edge(flights[i][0],flights[i][1],flights[i][2]);
        }
        return g.tot_time(n,src,dst,k);
    }
};