class Graph{
public:
    unordered_map<int,list<int>> l;
    void add_edge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    bool valid_path(int src, int dest){
        unordered_map<int,bool> visited;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int temp=q.front();
                q.pop();
                if(temp==dest){
                    return true;
                }
                if(visited[temp]){
                    continue;
                }
                visited[temp]=true;
                for(auto&it:l[temp]){
                    if(!visited[it]){
                        q.push(it);
                    }
                }
            }
        }



        return false;
    }
};
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end){      
        Graph g;
        for(int i=0;i<edges.size();i++){
            g.add_edge(edges[i][0],edges[i][1]);
        }
        return g.valid_path(start,end);
    }
};