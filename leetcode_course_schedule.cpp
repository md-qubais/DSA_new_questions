class Graph{
public:
    unordered_map<int,list<int>> l;
    unordered_map<int,int> indegree;
    void add_edge(int u,int v){
        l[u].push_back(v);
        indegree[v]++;
    }
    bool isCyclic(int n){
        //khans algorihtm to detect cycle in 
        //direct graph and find the topological order
        queue<int> q;
        for(auto&it:l){
            if(indegree[it.first]==0){
                q.push(it.first);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int size=q.size();
            //defines the level
            while(size--){
                int temp=q.front();
                q.pop();
                ans.push_back(temp);
                for(auto&it:l[temp]){
                    indegree[it]--;
                    if(indegree[it]==0){
                        q.push(it);
                    }
                }
            }
        }
        return ans.size()==n;
    }
};
class Solution{
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){
        Graph g;
        for(int i=0;i<prerequisites.size();i++){
            g.add_edge(prerequisites[i][0],prerequisites[i][1]);
        }
        return g.isCyclic(numCourses);
    }
};