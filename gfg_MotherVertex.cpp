class Solution{
public:
    void dfs(int src,vector<int>adj[],unordered_map<int,bool>&visited,stack<int>&st){
        visited[src]=true;
        for(auto&it:adj[src]){
            if(!visited[it]){
                dfs(it,adj,visited,st);
            }
        }
        st.push(src);
    }
    void dfs_count(int src,vector<int>adj[],unordered_map<int,bool>&visited,int&count){
        visited[src]=true;
        count++;
        for(auto&it:adj[src]){
            if(!visited[it]){
                dfs_count(it,adj,visited,count);
            }
        }
    }
    int findMotherVertex(int V, vector<int>adj[]){
        unordered_map<int,bool> visited;
        stack<int> st;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        visited.clear();
        int count=0;
        int src=st.top();
        dfs_count(src,adj,visited,count);
        if(count==V){
            return st.top();
        }
        return -1;
    }
};