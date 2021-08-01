class Graph{
public:
    unordered_map<int,list<int>> l;
    void add_edge(int u,int v){
        l[u].push_back(v);
    }
    bool CycleDetection1(int src,unordered_map<int,bool>&vis,unordered_map<int,bool>&path){
        vis[src]=true;
        path[src]=true;
        for(auto&it:l[src]){
            if(!vis[it]){
                if(CycleDetection1(it,vis,path)){
                    return true;
                }
            }else if(path[it]){
                return true;
            }
        }
        path[src]=false;
        return false;
    }
    bool CycleDetection2(int src,unordered_map<int,int>&vis){
        vis[src]=1;
        for(auto&it:l[src]){
            if(!vis[it]){
                if(CycleDetection2(it,vis)){
                    return true;
                }
            }else if(vis[it]==1){
                return true;
            }
        }
        vis[src]=2;
        return false;
    }
    bool CycleDetection(int n){
        unordered_map<int,int> vis;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(CycleDetection2(i,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        Graph g;
        for(int i=0;i<prerequisites.size();i++){
            g.add_edge(prerequisites[i][0],prerequisites[i][1]);
        }
        return !g.CycleDetection(numCourses);
    }
};