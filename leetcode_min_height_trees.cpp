class Graph{
public:
    vector<list<int>> l;
    void add_edge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    void topological(int src,stack<int>&s,vector<bool>&visited){
        visited[src]=true;
        for(auto&it:l[src]){
            if(!visited[it]){
                topological(it,s,visited);
            }
        }
        s.push(src);
    }
    int min_height(int n,vector<vector<int>>&edges){
        l.resize(n);
        for(auto&it:edges){
            int u=it[0];
            int v=it[1];
            add_edge(u,v);
        }
        vector<bool> visited(n,false);
        stack<int> s;
        topological(0,s,visited);
        return s.top();
    }
};
class Solution{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges){
        Graph g;
        return g.min_height(n,edges);
    }
};