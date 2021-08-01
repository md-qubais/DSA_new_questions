class Graph{
public:
    unordered_map<int,list<int>> l;
    void add_edge(int u,int v){
        l[u].push_back(v);
    }
    bool CycleDetection(int src,unordered_map<int,int>&vis,vector<int>&res){
        vis[src]=1;
        for(auto&it:l[src]){
            if(!vis[it]){
                if(CycleDetection(it,vis,res)){
                    return true;
                }
            }else if(vis[it]==1){
                return true;
            }
        }
        vis[src]=2;
        res.push_back(src);
        return false;
    }
    vector<int> CycleDetection_topo_sort(int n){
        unordered_map<int,int> vis;
        vector<int> res;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(CycleDetection(i,vis,res)){
                    vector<int> ans;
                    return ans;
                }
            }
        }
        return res;
    }
};
class Solution{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        Graph g;
        for(int i=0;i<prerequisites.size();i++){
            g.add_edge(prerequisites[i][0],prerequisites[i][1]);
        }
        return g.CycleDetection_topo_sort(numCourses);
    }
};


