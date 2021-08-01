class Graph{
public:
    unordered_map<int,list<pair<int,string>>> l;
    void add_edge(int u,int v){
        l[u].push_back(make_pair(v,"forward"));
        l[v].push_back(make_pair(u,"backward"));
    }
    int bfs(int src){
        int ans=0;
        queue<pair<int,string>> q;
        unordered_map<int,bool> visited;
        q.push(make_pair(0,""));
        while(!q.empty()){
            int size=q.size();
            while(size--){
                pair<int,string> temp=q.front();
                q.pop();
                if(visited[temp.first]){
                    continue;
                }
                if(temp.second=="forward"){
                    ans++;
                }
                visited[temp.first]=true;
                for(auto&it:l[temp.first]){
                    if(!visited[it.first]){
                        q.push(make_pair(it.first,it.second));
                    }
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections){
        Graph g;
        for(int i=0;i<connections.size();i++){
            g.add_edge(connections[i][0],connections[i][1]);
        }
        return g.bfs(0);
    }
};