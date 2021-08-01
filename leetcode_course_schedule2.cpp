class Graph{
public:
    unordered_map<int,list<int>> l;
    unordered_map<int,int> indegree;
    void add_edge(int u,int v){
        l[u].push_back(v);
        indegree[v]++;
    }
    vector<int> isCyclic_and_topological_order(int n){
        //khans algorihtm to detect cycle in 
        //direct graph and find the topological order
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
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
        if(ans.size()!=n){
            ans.resize(0);
            return ans;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        Graph g;
        if(prerequisites.size()==0){
            vector<int> ans;
            for(int i=0;i<numCourses;i++){
                ans.push_back(i);
            }
            return ans;
        }
        for(int i=0;i<prerequisites.size();i++){
            g.add_edge(prerequisites[i][0],prerequisites[i][1]);
        }
        return g.isCyclic_and_topological_order(numCourses);
    }
};