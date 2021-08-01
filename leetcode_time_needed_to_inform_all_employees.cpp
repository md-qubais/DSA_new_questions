class Graph{
public:
    unordered_map<int,list<int>> l;
    void add_edge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    int tot_time(int n,int src,vector<int>&manager,vector<int>&informTime){
        queue<pair<int,int>> q;
        unordered_map<int,bool> visited;
        int ans=0;
        q.push(make_pair(src,informTime[src]));
        while(!q.empty()){
            int size=q.size();
            int time=0;
            while(size--){
                pair<int,int> temp=q.front();
                q.pop();
                if(visited[temp.first]){
                    continue;
                }
                visited[temp.first]=true;
                ans=max(ans,temp.second);
                for(auto&it:l[temp.first]){
                    if(!visited[it]){
                        q.push(make_pair(it,temp.second+informTime[it]));
                    }
                }
            }
        }
        return ans;
    }
};
class Solution{
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime){
        Graph g;
        for(int i=0;i<manager.size();i++){
            if(manager[i]==-1){
                continue;
            }
            g.add_edge(i,manager[i]);
        }
        return g.tot_time(n,headID,manager,informTime);
    }
};