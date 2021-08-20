class Pair{
public:
    int curr;
    int time;
    int cost;
    Pair(int curr,int time,int cost){
        this->curr=curr;
        this->time=time;
        this->cost=cost;
    }
};

class Compare{
public:
    bool operator()(Pair p1,Pair p2){
        return p1.cost>p2.cost;
    }
};

class Graph{
public:
    unordered_map<int,list<pair<int,int>>> l;
    void add_edge(int u,int v,int w){
        l[u].push_back({v,w});
        l[v].push_back({v,w});
    }
    int MinCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees){
        priority_queue<Pair,vector<Pair>,Compare> pq;
        pq.push(Pair(0,0,passingFees[0]));
        vector<int> dp(passingFees.size(),INT_MAX);
        while(!pq.empty()){
            int size=pq.size();
            while(size--){
                Pair temp=pq.top();
                pq.pop();
                if(temp.curr==passingFees.size()-1){
                    if(temp.time<=maxTime){
                        return temp.cost;
                    }
                    continue;
                }
                if(temp.time>=maxTime){
                    continue;
                }
                if(temp.cost > dp[temp.curr]){
                    continue;
                }
                dp[temp.curr]=temp.cost;
                for(auto&it:l[temp.curr]){
                    if(temp.time + it.second <=maxTime){
                        pq.push(Pair(it.first,temp.time+it.second,temp.cost+passingFees[it.first]));
                    }
                }
            }
        }
        return -1;
    }
};

class Solution{
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees){
        Graph g;
        for(int i=0;i<edges.size();i++){
            g.add_edge(edges[i][0],edges[i][1],edges[i][2]);
        }
        return g.MinCost(maxTime,edges,passingFees);
    }
};