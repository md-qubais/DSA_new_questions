class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph,int src,int visited[]){
        queue<int> q;
        q.push(src);
        int color=1;
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int temp=q.front();
                q.pop();
                if(visited[temp]!=-1){
                    if(visited[temp]!=color){
                        return false;
                    }
                    continue;
                }
                visited[temp]=color;
                for(auto&it:graph[temp]){
                    q.push(it);
                }
            }
            color=(color+1)%2;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph){
        int visited[1000000];
        for(int i=0;i<1000000;i++){
            visited[i]=-1;
        }
        for(int i=1;i<graph.size();i++){
            if(visited[i]==-1 and !isBipartite(graph,i,visited)){
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes){
        vector<vector<int>> graph(n+1);
        for(int i=0;i<dislikes.size();i++){
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        return isBipartite(graph);
    }
};